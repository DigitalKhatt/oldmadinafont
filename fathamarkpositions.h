#pragma once

#include "automedina.h"
#include "Subtable.h"
#include "GlyphVis.h"
#include <algorithm>
#include <cmath>

namespace oldmadina {

enum class FathaAnchorStyle { Right,
                              Noon,
                              FinalKaf,
                              InitialKaf,
                              Centered };

inline constexpr double FathaShaddaCenterLimit = 1;
inline constexpr double FathaBaselineMinClearance = 100;
inline constexpr double FathaBaselineMaxClearance = 200;
inline constexpr double FathaBaselineRampStart = 3;
inline constexpr double FathaBaselineRampEnd = 4;

inline double fathaBaselineClearance(double lefttatweel) {
  const double ratio = std::clamp((lefttatweel - FathaBaselineRampStart) / (FathaBaselineRampEnd - FathaBaselineRampStart), 0.0, 1.0);
  return FathaBaselineMinClearance + ratio * (FathaBaselineMaxClearance - FathaBaselineMinClearance);
}

// Keep OldMadina's neutral top-mark anchor local. Other fonts still use the
// shared default calculator, including its historical width-dependent lift.
inline CalcAnchor topMarkAnchor(Automedina& font) {
  return [&font](std::string glyph, std::string, Point adjust, GlyphParameters parameters) {
    auto* current = font.glyphs.at(glyph).getAlternate(parameters);
    return Point(static_cast<int>(current->width * 0.5) + adjust.x(), 1 + adjust.y());
  };
}

// A subtable selects the style; the mark calculation sees only its own axes.
// Read the original subtable's anchor so its saved GUI adjustments survive.
inline CalcAnchor fathaMarkAnchor(Automedina& font, MarkBaseSubtable& source, std::string sourceClass, FathaAnchorStyle style, bool centerThenLeft = false) {
  return [&font, &source, sourceClass = std::move(sourceClass), style, centerThenLeft](std::string, std::string, Point adjust, GlyphParameters parameters) {
    auto neutralParameters = parameters;
    neutralParameters.lefttatweel = 0;
    const auto* neutral = font.glyphs.at("fatha").getAlternate(neutralParameters);
    const auto* current = font.glyphs.at("fatha").getAlternate(parameters);
    const auto neutralAnchor = source.getMarkAnchor("fatha", sourceClass, neutralParameters);
    Point anchor;
    if (style == FathaAnchorStyle::InitialKaf) {
      anchor = source.getMarkAnchor("fatha", sourceClass, parameters);
    } else if (style == FathaAnchorStyle::Right) {
      anchor = Point(std::lround(neutralAnchor.x() + current->bbox.urx - neutral->bbox.urx), std::lround(neutralAnchor.y() + current->bbox.ury - neutral->bbox.ury));
    } else {
      anchor = Point(std::lround(neutralAnchor.x() - (neutral->bbox.llx + neutral->bbox.urx) * 0.5 + (current->bbox.llx + current->bbox.urx) * 0.5), neutralAnchor.y());
    }
    if (style != FathaAnchorStyle::Right && style != FathaAnchorStyle::Centered) {
      const double lower = style == FathaAnchorStyle::InitialKaf ? 0.2 : style == FathaAnchorStyle::Noon ? 0.15
                                                                                                         : 0.25;
      anchor.setY(std::lround(neutralAnchor.y() + lower * std::max(0.0, current->width - neutral->width)));
    }
    if (centerThenLeft) {
      auto* reference = current;
      if (parameters.lefttatweel > FathaShaddaCenterLimit) {
        auto referenceParameters = parameters;
        referenceParameters.lefttatweel = FathaShaddaCenterLimit;
        reference = font.glyphs.at("fatha").getAlternate(referenceParameters);
      }
      // Centre up to the limit, then preserve that placement's right ink edge.
      // Keep the original neutral-anchor adjustment and all vertical profiles.
      const double neutralCenter = (neutral->bbox.llx + neutral->bbox.urx) * 0.5;
      const double referenceCenter = (reference->bbox.llx + reference->bbox.urx) * 0.5;
      anchor.setX(std::lround(neutralAnchor.x() - neutralCenter + referenceCenter + current->bbox.urx - reference->bbox.urx));
    }
    return anchor + adjust;
  };
}

inline CalcAnchor fathaBaseAnchor(Automedina& font, MarkBaseSubtable& source, std::string sourceClass, bool center) {
  return [&font, &source, sourceClass = std::move(sourceClass), center](std::string glyph, std::string, Point adjust, GlyphParameters parameters) {
    auto anchor = source.getBaseAnchor(glyph, sourceClass, parameters);
    if (center) {
      auto* current = font.glyphs.at(glyph).getAlternate(parameters);
      // An authored glyph anchor is already the designer's placement target.
      if (current->conatinsAnchor("topmarks", GlyphVis::AnchorType::MarkAnchor)) return anchor + adjust;
      const auto& offsets = source.classes.at(sourceClass).baseparameters;
      const auto found = offsets.find(glyph);
      const int offset = found == offsets.end() ? 0 : found->second.x();
      anchor.setX(std::lround((current->bbox.llx + current->bbox.urx) * 0.5 + offset));
    }
    return anchor + adjust;
  };
}

}  // namespace oldmadina
