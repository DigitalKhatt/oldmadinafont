#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <tuple>
#include <hb-ot.h>
#include "MPFont.h"
#include "Layout/OtLayout.h"
#include "Layout/Lookup.h"
#include "Layout/Subtable.h"
#include "Layout/GlyphVis.h"
#include "automedina/automedina.h"
#include "JustificationShaping.h"
#include "../fathamarkpositions.h"

namespace {
namespace fs = std::filesystem;

void require(bool condition, const std::string& message) {
  if (!condition) throw std::runtime_error(message);
}

std::string readFile(const fs::path& path) {
  std::ifstream stream(path, std::ios::binary);
  require(bool(stream), "Cannot read " + path.string());
  return {std::istreambuf_iterator<char>{stream}, {}};
}

void initializeFont(MPFont& font, const fs::path& project, const fs::path& resources) {
  font.initialize("MPGUI:=1;" + readFile(resources / "mfplain.mp") + readFile(resources / "mpost.mp") + readFile(resources / "vmf.mp") + readFile(project), project);
  const auto glyphs = readFile(project.parent_path() / "glyphs.mp");
  const std::string reset = "params[0]:=0;params[1]:=0;params[2]:=0;params[3]:=0;params[4]:=0;";
  std::size_t pos = 0;
  while (pos < glyphs.size()) {
    const auto begin = glyphs.find("beginchar", pos);
    const auto def = glyphs.find("defchar", pos);
    const bool isDef = def != std::string::npos && (begin == std::string::npos || def < begin);
    const auto start = isDef ? def : begin;
    if (start == std::string::npos) break;
    const std::string_view terminator = isDef ? "enddefchar;" : "endchar;";
    const auto end = glyphs.find(terminator, start);
    require(end != std::string::npos, "Unterminated glyph");
    const auto block = glyphs.substr(start, end + terminator.size() - start);
    const auto open = block.find('('), first = block.find(',', open), second = block.find(',', first + 1);
    require(second != std::string::npos, "Invalid glyph header");
    font.registerGlyphSource(block.substr(open + 1, first - open - 1), block, isDef ? "defchar" : "beginchar", std::stoi(block.substr(first + 1, second - first - 1)));
    font.execute(reset + block);
    pos = end + terminator.size();
  }
}

class FontProvider : public digitalkhatt::justify::FeatureJustificationLayout {
 public:
  explicit FontProvider(OtLayout& layout) : layout_(layout) {
    substitutions_ = digitalkhatt::justify::resolveAttachmentSubstitutions(*layout.compiledJustificationCatalog, [&](std::string_view name) -> std::optional<std::uint32_t> {
      const auto found = layout.glyphCodePerName.find(std::string(name));
      return found == layout.glyphCodePerName.end() ? std::nullopt : std::optional<std::uint32_t>(found->second);
    });
  }
  hb_font_t* createFont(double scale, bool newFace) override { return layout_.createFont(scale, newFace); }
  int scaleBy() const override { return OtLayout::SCALEBY; }
  int topSpace() const override { return OtLayout::TopSpace; }
  int interLineSpacing() const override { return layout_.interLineSpacing(); }
  std::string glyphName(hb_font_t*, hb_codepoint_t glyph) const override { return layout_.glyphNamePerCode.at(glyph); }
  const digitalkhatt::justify::CompiledJustificationCatalog* justificationCatalog() const override { return &*layout_.compiledJustificationCatalog; }
  bool supportsGlyphParameters() const override { return true; }
  bool dependentMarkStretchingEnabled() const override { return true; }
  std::span<const digitalkhatt::justify::ResolvedAttachmentSubstitution> attachmentSubstitutions() const override { return substitutions_; }
  GlyphParameters glyphParameters(const hb_glyph_info_t& info, double, double) const override { return layout_.glyphParameters(info); }
  bool setGlyphParameter(hb_glyph_info_t& info, digitalkhatt::GlyphAxisId axis, double value) const override {
    auto parameters = layout_.glyphParameters(info);
    parameters.set(axis, value);
    layout_.setGlyphParameters(info, parameters);
    return true;
  }
  bool setAttachmentParameter(hb_glyph_info_t& info, digitalkhatt::GlyphAxisId axis, double value, const GlyphParameters& baseline) const override {
    auto parameters = layout_.glyphParameters(info);
    parameters.set(axis, value);
    layout_.setGlyphParameters(info, parameters, &baseline);
    return true;
  }
  double glyphJustificationDelta(const hb_glyph_info_t& info, digitalkhatt::GlyphAxisId axis) const override { return layout_.glyphJustificationDelta(info, axis); }
  std::optional<double> glyphDesignWidth(hb_codepoint_t code, const GlyphParameters& parameters) const override { return layout_.getGlyph(code, parameters)->width; }
  std::optional<double> glyphInkWidth(hb_codepoint_t code, const GlyphParameters& parameters) const override {
    const auto* glyph = layout_.getGlyph(code, parameters);
    return glyph->bbox.urx - glyph->bbox.llx;
  }
  std::optional<double> glyphParameterMaximum(hb_codepoint_t code, digitalkhatt::GlyphAxisId axis) const override {
    const auto found = layout_.expandableGlyphs.find(layout_.glyphNamePerCode.at(code));
    if (found == layout_.expandableGlyphs.end() || axis != digitalkhatt::LeftTatweelAxis) return std::nullopt;
    return found->second.maxLeft;
  }

 private:
  OtLayout& layout_;
  std::vector<digitalkhatt::justify::ResolvedAttachmentSubstitution> substitutions_;
};

enum class Parent { Base,
                    Dot,
                    Shadda };

void checkDispatch(OtLayout& layout, FontProvider& provider, hb_font_t* font, const std::string& root, int style, Parent parent, double left, bool gsubParameter = false, bool startWithAlias = false) {
  using namespace digitalkhatt::justify::runtime;
  const std::u16string text = parent == Parent::Shadda ? u"نَّ" : parent == Parent::Dot ? u"نَ"
                                                                                      : u"كَ";
  const unsigned markCluster = parent == Parent::Shadda ? 2 : 1;
  std::vector<GlyphParameterAssignment> assignments{{0, digitalkhatt::NoGlyphAxis, 0, layout.glyphCodePerName.at(root)}};
  std::vector<hb_feature_t> features;
  if (gsubParameter)
    features.push_back({HB_TAG('c', 'v', '0', '1'), 1, markCluster, markCluster + 1});
  else
    assignments.push_back({markCluster, digitalkhatt::LeftTatweelAxis, left, startWithAlias ? layout.glyphCodePerName.at("fatha.stretched") : static_cast<hb_codepoint_t>(-1)});
  auto* buffer = shape(text, font, features, &provider, assignments, false);
  unsigned count = 0;
  const auto* infos = hb_buffer_get_glyph_infos(buffer, &count);
  bool checked = false;
  for (unsigned i = 0; i < count; ++i) {
    const auto& name = layout.glyphNamePerCode.at(infos[i].codepoint);
    if (name != "fatha" && name != "fatha.stretched") continue;
    const auto state = layout.glyphInstanceState(infos[i]);
    require(state.parameters.lefttatweel == left, "Glyph identity selection lost Fatha parameters");
    require(state.positioning.has_value(), "Fatha has no GPOS positioning record");
    const auto& applied = layout.gposlookups.at(state.positioning->lookup_index)->name;
    if (left > 0 && !gsubParameter) {
      if (parent == Parent::Base) {
        const auto* lookup = layout.gposlookups.at(state.positioning->lookup_index);
        const auto& subtable = lookup->subtables.at(state.positioning->subtable_index)->name;
        require(name == "fatha.stretched" && applied == "defaultmarkposition" && subtable.ends_with(".fatha." + std::to_string(style)), root + ": unexpected direct subtable " + applied + "/" + subtable);
      } else {
        const std::string expected = "fatha.stretched." + std::string(parent == Parent::Shadda ? "defaultmkmktop" : "defaultmarkdotmarkstop") + "." + std::to_string(style);
        require(name == "fatha.stretched" && applied == expected, root + ": expected " + expected + ", got " + applied);
        const auto* subtable = static_cast<MarkBaseSubtable*>(layout.gposlookups.at(state.positioning->lookup_index)->subtables.at(state.positioning->subtable_index));
        if (parent == Parent::Shadda) require(subtable->base == std::vector<std::string>{"shadda"} && subtable->name.ends_with(".shadda"), "Shadda positioning must use its exclusive transition subtable");
      }
    } else {
      require(name == "fatha" && !applied.starts_with("fatha.stretched."), "Contextual/natural/shrinking Fatha entered justification-stretched positioning");
    }
    checked = true;
  }
  hb_buffer_destroy(buffer);
  require(checked, "Fatha disappeared");
}

void checkAutomaticAttachment(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  const std::vector<GlyphParameterAssignment> assignments{{0, digitalkhatt::NoGlyphAxis, 0, layout.glyphCodePerName.at("noon.fina.expa")}, {0, digitalkhatt::LeftTatweelAxis, 3}, {1, digitalkhatt::ThirdAxis, 2}};
  auto* buffer = shape(u"نَ", font, {}, &provider, assignments, true, digitalkhatt::justify::LineJustificationOperation::Stretch);
  unsigned count = 0;
  const auto* infos = hb_buffer_get_glyph_infos(buffer, &count);
  bool checked = false;
  for (unsigned i = 0; i < count; ++i) {
    if (layout.glyphNamePerCode.at(infos[i].codepoint) != "fatha.stretched") continue;
    const auto parameters = layout.glyphParameters(infos[i]);
    require(parameters.lefttatweel > 0 && parameters.third == 2, "Dependent attachment must assign width and substitute identity while preserving other axes");
    require(layout.glyphJustificationDelta(infos[i], digitalkhatt::LeftTatweelAxis) == parameters.lefttatweel, "Automatic attachment must carry only its added mark stretching");
    checked = true;
  }
  hb_buffer_destroy(buffer);
  require(checked, "Automatic width response did not substitute the Fatha");
}

void checkContextualFatha(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  for (const auto& [text, cluster, expectedLeft] : {std::tuple{u"فَـٔ͏َاتُوهُنَّ", 1u, 0.0}, std::tuple{u"ٱللَّهَ", 4u, 0.5}}) {
    auto* buffer = shape(text, font, {}, &provider, {}, true, digitalkhatt::justify::LineJustificationOperation::Stretch);
    unsigned count = 0;
    const auto* infos = hb_buffer_get_glyph_infos(buffer, &count);
    bool checked = false;
    for (unsigned i = 0; i < count; ++i) {
      const auto name = layout.glyphNamePerCode.at(infos[i].codepoint);
      const auto parameters = layout.glyphParameters(infos[i]);
      if ((name != "fatha" && name != "fatha.stretched") || infos[i].cluster != cluster) continue;
      require(name == "fatha", "Contextual Fatha extension must not select justification identity");
      require(parameters.lefttatweel == expectedLeft, "Unexpected contextual Fatha width parameter");
      require(!layout.preserveMarkGposHorizontal(infos[i].codepoint, parameters), "Contextual Fatha must not activate justification-only placement constraints");
      require(layout.glyphJustificationDelta(infos[i], digitalkhatt::LeftTatweelAxis) == 0, "Contextual Fatha width must not be reported as justification growth");
      checked = true;
    }
    hb_buffer_destroy(buffer);
    require(checked, "Expected the regression word's contextual Fatha");
  }
}

void checkCompensatedJoinedConnection(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  // Page 82:4:2: contextual Feh left=1, Alef right=1. Justification adds
  // 17 ink units on Feh but removes 60 on Alef: no net kashida growth.
  const std::vector<GlyphParameterAssignment> assignments{{0, digitalkhatt::LeftTatweelAxis, 1.125}, {6, digitalkhatt::RightTatweelAxis, 0.5625}};
  auto* buffer = shape(u"فَـٔ͏َاتُوهُنَّ", font, {}, &provider, assignments, true, digitalkhatt::justify::LineJustificationOperation::Stretch);
  unsigned count = 0;
  const auto* infos = hb_buffer_get_glyph_infos(buffer, &count);
  bool checked = false;
  for (unsigned i = 0; i < count; ++i) {
    if (infos[i].cluster != 1) continue;
    require(layout.glyphNamePerCode.at(infos[i].codepoint) == "fatha", "A net-shortened connection must keep the natural Fatha identity");
    require(layout.glyphParameters(infos[i]).lefttatweel == 0, "A net-shortened connection must not stretch its Fatha");
    checked = true;
  }
  hb_buffer_destroy(buffer);
  require(checked, "Missing Feh Fatha in compensated-connection regression");
}

void checkAddedMarkStretching(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  // Allah's contextual Fatha starts at 0.5. Two justification assignments
  // must retain that original reference, not report the total or last step.
  const std::vector<GlyphParameterAssignment> assignments{{4, digitalkhatt::LeftTatweelAxis, 1}, {4, digitalkhatt::LeftTatweelAxis, 1.25}};
  auto* buffer = shape(u"ٱللَّهَ", font, {}, &provider, assignments, false);
  unsigned count = 0;
  const auto* infos = hb_buffer_get_glyph_infos(buffer, &count);
  bool checked = false;
  for (unsigned i = 0; i < count; ++i) {
    if (infos[i].cluster != 4) continue;
    require(layout.glyphNamePerCode.at(infos[i].codepoint) == "fatha.stretched", "Explicit mark extension must select the justification identity");
    require(layout.glyphParameters(infos[i]).lefttatweel == 1.25 && layout.glyphJustificationDelta(infos[i], digitalkhatt::LeftTatweelAxis) == 0.75, "Joined-mark gap must subtract contextual width and retain the first reference through GPOS");
    checked = true;
  }
  hb_buffer_destroy(buffer);
  require(checked, "Missing contextual Fatha in added-stretch regression");
}

unsigned u16(const digitalkhatt::ByteBuffer& table, std::size_t offset) {
  require(offset + 2 <= table.size(), "Anchor outside serialized table");
  return (unsigned(table.data()[offset]) << 8) | table.data()[offset + 1];
}

void checkShaddaCenterTransition(OtLayout& layout) {
  MarkBaseSubtable* source = nullptr;
  for (auto* lookup : layout.lookups) {
    if (lookup->name != "defaultmkmk") continue;
    for (auto* raw : lookup->subtables) if (raw->name == "defaultmkmktop") source = static_cast<MarkBaseSubtable*>(raw);
  }
  require(source != nullptr, "Missing ordinary top mark-to-mark source");
  for (int style = 0; style < 5; ++style) {
    auto* helper = layout.lookups.at(layout.lookupsIndexByName.at("fatha.stretched.defaultmkmktop." + std::to_string(style)));
    require(helper->subtables.size() == 2, "Top helpers must split Shadda from other mark parents");
    auto& centered = *static_cast<MarkBaseSubtable*>(helper->subtables[0]);
    auto& others = *static_cast<MarkBaseSubtable*>(helper->subtables[1]);
    require(centered.base == std::vector<std::string>{"shadda"} && std::find(others.base.begin(), others.base.end(), "shadda") == others.base.end(), "Transition coverage must be disjoint and Shadda-only");
    const auto neutralAnchor = source->getMarkAnchor("fatha", "topmarks", {});
    const auto* neutral = layout.getGlyph(layout.glyphCodePerName.at("fatha"));
    const double neutralCenter = (neutral->bbox.llx + neutral->bbox.urx) * 0.5;
    GlyphParameters atLimit;
    atLimit.lefttatweel = oldmadina::FathaShaddaCenterLimit;
    const auto* limit = layout.getGlyph(layout.glyphCodePerName.at("fatha"), atLimit);
    const auto limitAnchor = centered.getMarkAnchor("fatha.stretched", "topmarks", atLimit);
    const double limitRight = limit->bbox.urx - limitAnchor.x();
    for (double left : {0.0625, 0.5, 1.0, 1.499999, 1.5, 1.500001, 2.0, 5.0}) {
      GlyphParameters parameters;
      parameters.lefttatweel = left;
      const auto* current = layout.getGlyph(layout.glyphCodePerName.at("fatha"), parameters);
      const auto anchor = centered.getMarkAnchor("fatha.stretched", "topmarks", parameters);
      const auto unchanged = others.getMarkAnchor("fatha.stretched", "topmarks", parameters);
      const double originalX = style == 3 ? source->getMarkAnchor("fatha", "topmarks", parameters).x() : style == 0 ? neutralAnchor.x() + current->bbox.urx - neutral->bbox.urx : neutralAnchor.x() - neutralCenter + (current->bbox.llx + current->bbox.urx) * 0.5;
      const double lower = style == 3 ? 0.2 : style == 1 ? 0.15 : 0.25;
      const double growth = std::max(0.0, current->width - neutral->width);
      const double originalY = style == 0 ? neutralAnchor.y() + current->bbox.ury - neutral->bbox.ury : style == 4 ? neutralAnchor.y() : neutralAnchor.y() + lower * growth;
      require(anchor.y() == unchanged.y() && unchanged.x() == std::lround(originalX) && unchanged.y() == std::lround(originalY), "Shadda transition must leave vertical profiles and other parents unchanged");
      if (left <= oldmadina::FathaShaddaCenterLimit) {
        const double expected = neutralAnchor.x() - neutralCenter + (current->bbox.llx + current->bbox.urx) * 0.5;
        require(anchor.x() == std::lround(expected), "Short stretched Fatha must remain centered with its original GUI calibration");
      } else {
        require(std::abs(current->bbox.urx - anchor.x() - limitRight) <= 1, "Long stretched Fatha must preserve the right edge of its centered threshold placement");
        require(std::abs(anchor.x() - limitAnchor.x()) <= 1 || left > 1.500001, "The threshold transition must not jump at 1.5");
      }
    }
  }
}

void checkLocalAnchorsAndExpandedCentering(OtLayout& layout) {
  const auto fatha = layout.glyphCodePerName.at("fatha");
  const auto stretched = layout.glyphCodePerName.at("fatha.stretched");
  GlyphParameters parameters;
  parameters.lefttatweel = 5;
  require(layout.markBaselineClearance(stretched, parameters) == 200 && !layout.markBaselineClearance(fatha, parameters) && !layout.markBaselineClearance(stretched, {}), "Only actively justification-stretched Fatha must author the baseline floor");
  for (const auto& [left, expected] : {std::pair{0.0625, 100.0}, {1.5, 100.0}, {3.0, 100.0}, {3.125, 112.5}, {3.5, 150.0}, {3.8125, 181.25}, {4.0, 200.0}, {4.5, 200.0}, {5.0, 200.0}, {10.0, 200.0}, {20.0, 200.0}}) {
    auto probe = parameters;
    probe.lefttatweel = left;
    require(layout.markBaselineClearance(stretched, probe) == expected, "Long-Fatha baseline floor must ramp smoothly and remain bounded between 100 and 200 design units");
  }
  for (double threshold : {oldmadina::FathaBaselineRampStart, oldmadina::FathaBaselineRampEnd}) {
    require(std::abs(oldmadina::fathaBaselineClearance(threshold - 1e-6) - oldmadina::fathaBaselineClearance(threshold + 1e-6)) < 1e-3, "Baseline clearance must not jump at either ramp threshold");
  }
  const auto* lookup = layout.lookups.at(layout.lookupsIndexByName.at("defaultmarkposition"));
  bool ordinaryChecked = false;
  for (auto* raw : lookup->subtables) {
    auto* subtable = static_cast<MarkBaseSubtable*>(raw);
    for (const auto& [name, row] : subtable->classes) {
      if (subtable->name.find(".fatha.") != std::string::npos) continue;
      if (std::find(row.mark.begin(), row.mark.end(), "fatha") == row.mark.end()) continue;
      require(subtable->getMarkAnchor("fatha", name, parameters).y() == subtable->getMarkAnchor("fatha", name, {}).y(), "OldMadina ordinary default Fatha must not retain width-dependent lift");
      ordinaryChecked = true;
    }
  }
  require(ordinaryChecked, "Missing ordinary Fatha default anchor regression");
  for (const auto* root : {"behshape.isol.expa", "behshape.fina.expa", "alefmaksura.isol.expa", "yehshape.isol.expa", "yehshape.fina.ii.expa", "yehshape.fina.afterbeh.expa", "yehshape.fina.expa"}) {
    bool checked = false;
    require(!layout.markBaselineClearance(layout.glyphCodePerName.at(root), parameters), "Base glyphs must not receive the mark baseline floor");
    for (auto* raw : lookup->subtables) {
      auto& subtable = *static_cast<MarkBaseSubtable*>(raw);
      if (!subtable.name.ends_with(".fatha.4") || std::find(subtable.base.begin(), subtable.base.end(), root) == subtable.base.end()) continue;
      const auto className = subtable.classes.begin()->first;
      const auto* neutralBase = layout.getGlyph(layout.glyphCodePerName.at(root));
      const auto* currentBase = layout.getGlyph(layout.glyphCodePerName.at(root), parameters);
      const auto* neutralMark = layout.getGlyph(fatha);
      const auto* currentMark = layout.getGlyph(fatha, parameters);
      const auto base = subtable.getBaseAnchor(root, className, parameters);
      const auto neutralBaseAnchor = subtable.getBaseAnchor(root, className, {});
      const auto mark = subtable.getMarkAnchor("fatha.stretched", className, parameters);
      const auto neutralMarkAnchor = subtable.getMarkAnchor("fatha.stretched", className, {});
      const double baseCenterChange = (currentBase->bbox.llx + currentBase->bbox.urx - neutralBase->bbox.llx - neutralBase->bbox.urx) * 0.5;
      const double markCenterChange = (currentMark->bbox.llx + currentMark->bbox.urx - neutralMark->bbox.llx - neutralMark->bbox.urx) * 0.5;
      require(std::abs(base.x() - neutralBaseAnchor.x() - baseCenterChange) <= 1 && std::abs(mark.x() - neutralMarkAnchor.x() - markCenterChange) <= 1, "Expanded Beh/Yeh GPOS must track both base and Fatha ink centres while retaining neutral GUI offsets");
      require(mark.y() == neutralMarkAnchor.y(), "Expanded Beh/Yeh centered Fatha must not gain width-dependent vertical compensation");
      checked = true;
    }
    require(checked, std::string("Missing centered expanded base coverage: ") + root);
  }
}

void checkSharedGlyphTopAnchor(OtLayout& layout) {
  const std::string root = "yehshape.fina.ii.expa";
  const auto code = layout.glyphCodePerName.at(root);
  auto* lookup = layout.lookups.at(layout.lookupsIndexByName.at("defaultmarkposition"));
  for (double left : {0.0, 1.0, 3.0, 5.1}) {
    GlyphParameters parameters;
    parameters.lefttatweel = left;
    auto* glyph = layout.getGlyph(code, parameters);
    require(glyph->conatinsAnchor("topmarks", GlyphVis::AnchorType::MarkAnchor), "Expanded Yeh must author one editable topmarks anchor");
    const auto authored = glyph->getAnchor("topmarks", GlyphVis::AnchorType::MarkAnchor);
    require(authored.y() == 206 && std::abs(authored.x() - (glyph->bbox.llx + glyph->bbox.urx) * 0.5) < 1, "Authored top anchor must retain its lower Y while following expanded ink centre: left=" + std::to_string(left) + " anchor=" + std::to_string(authored.x()) + "," + std::to_string(authored.y()) + " center=" + std::to_string((glyph->bbox.llx + glyph->bbox.urx) * 0.5) + " matrixX=" + std::to_string(glyph->matrix.xpart) + " bounds=" + std::to_string(glyph->bbox.llx) + "," + std::to_string(glyph->bbox.urx));
    int checked = 0;
    for (auto* raw : lookup->subtables) {
      auto& subtable = *static_cast<MarkBaseSubtable*>(raw);
      for (const auto* markClass : {"topmarks", "shadda", "maddahabove", "smallalefreplacement"}) {
        if (subtable.name != markClass || !subtable.classes.contains(markClass)) continue;
        const auto& adjustments = subtable.classes.at(markClass).baseparameters;
        const auto found = adjustments.find(root);
        const auto bias = found == adjustments.end() ? Point{} : found->second;
        require(subtable.getBaseAnchor(root, markClass, parameters) == authored + bias, "All upper classes must reuse the glyph's single topmarks anchor and retain explicit GUI bias");
        ++checked;
      }
      if (subtable.name == "lowmarks") require(subtable.getBaseAnchor(root, "lowmarks", parameters).y() < 0, "Shared upper anchor must never override the lower-mark subtable");
    }
    require(checked == 4, "Expected ordinary Fatha, Shadda, Maddah and replacement small Alef to use the shared anchor");
  }
  auto& neutral = layout.glyphs.at(root);
  const GlyphVis::AnchorKey key{"shadda", GlyphVis::AnchorType::MarkAnchor};
  require(!neutral.anchors.contains(key), "Yeh regression expects only the shared top anchor initially");
  neutral.anchors[key] = {Point(12, 34), static_cast<int>(GlyphVis::AnchorType::MarkAnchor)};
  bool checkedOverride = false;
  for (auto* raw : lookup->subtables) {
    auto& subtable = *static_cast<MarkBaseSubtable*>(raw);
    if (subtable.name != "shadda") continue;
    require(subtable.getBaseAnchor(root, "shadda", {}) == Point(12, 34), "A future explicit class anchor must override the shared topmarks fallback");
    checkedOverride = true;
  }
  neutral.anchors.erase(key);
  require(checkedOverride, "Missing Shadda override precedence regression");
}

void checkFontOwnedGroupAnchors(OtLayout& layout) {
  const std::string root = "yehshape.fina.ii.expa";
  auto& glyph = layout.glyphs.at(root);
  const auto authored = glyph.getAnchor("topmarks", GlyphVis::AnchorType::MarkAnchor);
  const auto shadda = layout.glyphCodePerName.at("shadda");
  const auto kasra = layout.glyphCodePerName.at("kasra");
  const auto base = layout.glyphCodePerName.at("behshape.init");
  Lookup lookup(&layout);
  lookup.name = "fallback.probe";
  lookup.type = Lookup::mark2base;
  MarkBaseSubtable subtable(&lookup);
  auto& row = subtable.classes["arbitrary_upper_name"];
  row.mark = {"shadda"};
  row.baseparameters[root] = Point(5, 7);
  const auto calculated = [](std::string, std::string, Point adjust, GlyphParameters) { return Point(11, 22) + adjust; };
  row.basefunction = calculated;
  const Point bias(5, 7);
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == authored + bias, "Font group anchor must work with an arbitrary class name and custom calculator");
  row.basefunction = {};
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == authored + bias, "Font group anchor must not require a base calculator");
  row.basefunction = calculated;
  row.baseanchors[root] = Point(33, 44);
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == authored + bias, "Font-resolved group anchor must win over base coordinates and calculated defaults");
  row.basefunction = {};
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == authored + bias, "Font-resolved group anchor must also win over base coordinates without a calculator");
  row.markCodes = {kasra};
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == Point(33, 44) + bias, "Nullopt must retain base coordinates when there is no calculator");
  row.basefunction = calculated;
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == Point(11, 22) + bias, "Nullopt must retain the original calculator precedence over base coordinates");
  row.markCodes.clear();
  layout.prepareAnchorResolution();
  row.baseanchors.clear();
  const auto saved = glyph.anchors;
  glyph.anchors[{lookup.name, GlyphVis::AnchorType::MarkAnchor}] = {Point(55, 66), static_cast<int>(GlyphVis::AnchorType::MarkAnchor)};
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == Point(55, 66) + bias, "Lookup anchor must win over the shared fallback");
  glyph.anchors[{lookup.name + "_arbitrary_upper_name", GlyphVis::AnchorType::MarkAnchor}] = {Point(77, 88), static_cast<int>(GlyphVis::AnchorType::MarkAnchor)};
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == Point(77, 88) + bias, "Lookup/class anchor must win over lookup anchor");
  glyph.anchors[{"arbitrary_upper_name", GlyphVis::AnchorType::MarkAnchor}] = {Point(99, 111), static_cast<int>(GlyphVis::AnchorType::MarkAnchor)};
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == Point(99, 111) + bias, "Explicit class anchor must win over all fallbacks");
  glyph.anchors = saved;
  const auto checkCoverage = [&](std::unordered_set<std::string> expressions, std::unordered_set<std::uint16_t> codes, bool expected) {
    row.mark = std::move(expressions);
    row.markCodes = std::move(codes);
    layout.prepareAnchorResolution();
    require(layout.getAnchor(glyph, subtable, "arbitrary_upper_name", {}).has_value() == expected, "Group eligibility must require a nonempty, completely resolved subset of the actual anchor class");
    require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == (expected ? authored : Point(11, 22)) + bias, "Coverage membership must select the group anchor without treating it as all upper marks");
  };
  checkCoverage({"kasra"}, {}, false);
  checkCoverage({"shadda", "kasra"}, {}, false);
  checkCoverage({"^no-such-upper-mark-probe$"}, {}, false);
  checkCoverage({"shadda", "^no-such-upper-mark-probe$"}, {}, false);
  checkCoverage({"onedotup"}, {}, false);
  checkCoverage({"waqf.meem"}, {}, false);
  checkCoverage({}, {}, false);
  checkCoverage({}, {base}, false);
  checkCoverage({}, {shadda}, true);
  checkCoverage({}, {shadda, kasra}, false);
  checkCoverage({"shadda"}, {kasra}, false);
  checkCoverage({"kasra"}, {shadda}, true);
  const auto withoutAnchor = layout.glyphCodePerName.at("behshape.isol");
  row.markCodes = {shadda};
  row.mark.clear();
  layout.prepareAnchorResolution();
  require(!layout.getGlyph(withoutAnchor)->conatinsAnchor("topmarks", GlyphVis::AnchorType::MarkAnchor) && subtable.getBaseAnchor("behshape.isol", "arbitrary_upper_name", {}) == Point(11, 22), "Eligible classes must retain their calculator when the glyph has no shared anchor");

  // The same mark coverage uses each glyph's authored anchors, most specific first.
  auto& lam = layout.glyphs.at("lam.isol.expa");
  const auto savedLamAnchors = lam.anchors;
  const GlyphVis::AnchorKey shaddaKey{"shadda", GlyphVis::AnchorType::MarkAnchor};
  const GlyphVis::AnchorKey topKey{"topmarks", GlyphVis::AnchorType::MarkAnchor};
  const auto type = static_cast<int>(GlyphVis::AnchorType::MarkAnchor);
  lam.anchors[shaddaKey] = {Point(120, 130), type};
  lam.anchors[topKey] = {Point(220, 230), type};
  row.baseparameters[lam.name] = bias;
  require(subtable.getBaseAnchor(lam.name, "arbitrary_upper_name", {}) == Point(120, 130) + bias, "The singleton Shadda anchor must outrank the broader topmarks anchor");
  require(subtable.getBaseAnchor(root, "arbitrary_upper_name", {}) == authored + bias, "The same class must use Yeh's different authored group anchor");
  lam.anchors.erase(shaddaKey);
  require(subtable.getBaseAnchor(lam.name, "arbitrary_upper_name", {}) == Point(220, 230) + bias, "A missing specific anchor must allow the broader authored group anchor");
  lam.anchors[shaddaKey] = {Point(0, 0), type};
  require(subtable.getBaseAnchor(lam.name, "arbitrary_upper_name", {}) == bias, "An optional zero anchor must not be mistaken for a missing anchor");
  row.markCodes = {layout.glyphCodePerName.at("damma")};
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(lam.name, "arbitrary_upper_name", {}) == Point(220, 230) + bias, "Lam's general rule must handle other upper marks without using its Shadda rule");
  lam.anchors = savedLamAnchors;

  // Any glyph can opt in simply by authoring an anchor: no glyph-name registry.
  auto& ordinary = layout.glyphs.at("behshape.isol");
  const auto savedOrdinaryAnchors = ordinary.anchors;
  ordinary.anchors[topKey] = {Point(310, 320), type};
  row.markCodes = {shadda};
  row.baseparameters[ordinary.name] = bias;
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(ordinary.name, "arbitrary_upper_name", {}) == Point(310, 320) + bias, "An unlisted glyph must opt in through its authored group anchor alone");
  ordinary.anchors[topKey].anchor = Point(330, 340);
  require(subtable.getBaseAnchor(ordinary.name, "arbitrary_upper_name", {}) == Point(330, 340) + bias, "The membership cache must never retain glyph anchor coordinates");
  ordinary.anchors[{"lowmarks", GlyphVis::AnchorType::MarkAnchor}] = {Point(210, -220), type};
  ordinary.anchors[{"kasras", GlyphVis::AnchorType::MarkAnchor}] = {Point(110, -120), type};
  row.markCodes = {kasra};
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(ordinary.name, "arbitrary_upper_name", {}) == Point(110, -120) + bias, "An arbitrary lower group must work and prefer its narrower containing class");
  row.markCodes = {layout.glyphCodePerName.at("hamzabelow")};
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(ordinary.name, "arbitrary_upper_name", {}) == Point(210, -220) + bias, "Marks outside the narrower group must use the wider authored group");
  ordinary.anchors = savedOrdinaryAnchors;
  ordinary.anchors[{"kasras", GlyphVis::AnchorType::EntryAnchor}] = {Point(1, 2), static_cast<int>(GlyphVis::AnchorType::EntryAnchor)};
  ordinary.anchors[{"^kas.*", GlyphVis::AnchorType::MarkAnchor}] = {Point(3, 4), type};
  row.markCodes = {kasra};
  layout.prepareAnchorResolution();
  require(!layout.getAnchor(ordinary, subtable, "arbitrary_upper_name", {}), "Cursive anchors and regex-like undeclared anchor names must not become mark classes");
  ordinary.anchors = savedOrdinaryAnchors;

  class UnconfiguredFont : public Automedina {
   public:
    explicit UnconfiguredFont(OtLayout& layout) : Automedina(&layout, nullptr, true) {}
    Lookup* getLookup(std::string) override { return nullptr; }
    CalcAnchor getanchorCalcFunctions(std::string, Subtable*) override { return {}; }
  } otherFont(layout);
  require(!otherFont.getAnchor(glyph, subtable, "arbitrary_upper_name", {}), "Other fonts must inherit a nullopt callback with no mark-group policy");
}

void checkLamMeemStretching(OtLayout& layout) {
  using namespace digitalkhatt;
  const int width = 1800 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard};
  const std::vector<LineToJustify> input{{u"وَلَمْ", width, LineJustification::Distribute, LineType::Line}};
  bool preferred = false, continued = false;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    if (trace.decision != "applied") return;
    preferred |= trace.selection == "CandidatePreferred" && trace.rule == "PreferredLamMeemKashida";
    continued |= trace.selection == "CandidateContinuePreferred" && trace.rule == "ContinueLamMeemKashida";
  });
  const auto page = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, options, "qpc_v1_layout");
  layout.setJustificationTraceCallback({});
  require(page.size() == 1 && preferred && continued, "Lam-Meem must stretch in the preferred stage and continue when width remains");
  bool lam = false, meem = false, fatha = false;
  for (const auto& glyph : page.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    if (name == "lam.init") lam = glyph.parameters.lefttatweel >= 1;
    if (name == "meem.fina.ii") meem = glyph.parameters.righttatweel >= 1;
    if (name == "fatha.stretched") fatha |= glyph.parameters.lefttatweel > 0;
  }
  require(lam && meem && fatha, "With sufficient width, preferred Lam-final-Meem stretching must deform both endpoints and its owning Fatha");
}

void checkHehMeemStretching(OtLayout& layout) {
  using namespace digitalkhatt;
  const int width = 2400 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard};
  for (const auto& [text, hehName] : std::vector<std::pair<std::u16string, std::string>>{{u"هَمْ", "heh.init"}, {u"مَهَمْ", "heh.medi"}}) {
    const std::vector<LineToJustify> input{{text, width, LineJustification::Distribute, LineType::Line}};
    bool preferred = false;
    layout.setJustificationTraceCallback([&](const auto& trace) {
      if (trace.decision != "applied") return;
      preferred |= trace.selection == "CandidatePreferred" && trace.rule == "PreferredHehMeemKashida";
      if (trace.rule != "PreferredHehMeemKashida" && trace.rule != "ContinueHehMeemKashida") return;
      int endpointCount = 0;
      for (const auto& parameter : trace.parameters) {
        if (parameter.attribute != "lefttatweel" && parameter.attribute != "righttatweel") continue;
        ++endpointCount;
        if (trace.rule == "PreferredHehMeemKashida") {
          require(parameter.minimumValue == 0.5 && parameter.maximumValue == 1.5, "Heh-final-Meem preferred endpoints must use the 0.5..1.5 range");
        } else {
          require(parameter.maximumValue == 1.2, "Heh-final-Meem continuation must retain the maximum 1.2");
        }
      }
      require(endpointCount == 2, "Heh-final-Meem must limit both kashida endpoints");
    });
    const auto page = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, options, "qpc_v1_layout");
    layout.setJustificationTraceCallback({});
    require(page.size() == 1 && preferred, hehName + "-final-Meem must stretch in the preferred stage");
    bool heh = false, meem = false;
    for (const auto& glyph : page.front().glyphs) {
      const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
      if (name == hehName) heh = glyph.parameters.lefttatweel > 1 && glyph.parameters.lefttatweel <= 1.5;
      if (name == "meem.fina" || name == "meem.fina.ii") meem = glyph.parameters.righttatweel > 0.5 && glyph.parameters.righttatweel <= 1.5;
    }
    require(heh && meem, hehName + "-final-Meem must decompose if necessary and deform both endpoints beyond their starting lengths");
  }
}

void checkLastResortDecomposition(OtLayout& layout) {
  using namespace digitalkhatt;
  const int width = 5000 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard};
  const std::vector<LineToJustify> input{{u"تَحُسُّونَهُم", width, LineJustification::Distribute, LineType::Line}};
  bool preferredHeh = false, regularDecomposition = false;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    if (trace.decision != "applied") return;
    preferredHeh |= trace.rule == "PreferredHehMeemKashida";
    regularDecomposition |= trace.selection == "CandidateDecomposition";
  });
  const auto page = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, options, "qpc_v1_layout");
  layout.setJustificationTraceCallback({});
  require(page.size() == 1 && preferredHeh && !regularDecomposition, "The normal decomposition selection must still respect an earlier Horizontal record in the word");
  bool beh = false, hah = false, heh = false, meem = false;
  for (const auto& glyph : page.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    require(name != "behshape.init.beforehah" && name != "hah.medi.afterbeh", "Last resort must decompose Beh-Hah despite the earlier Horizontal record");
    if (name == "behshape.init" && glyph.cluster == 0) beh = glyph.parameters.lefttatweel == 0.5;
    if (name == "hah.medi") hah = glyph.parameters.righttatweel == 0.5;
    if (name == "heh.medi") heh = glyph.parameters.lefttatweel > 0;
    if (name == "meem.fina.ii") meem = glyph.parameters.righttatweel > 0;
  }
  require(beh && hah && heh && meem, "Last-resort endpoints must stay at 0.5 and preserve the earlier Heh-Meem stretching");

  // A preferred Meem-Lam connection occupies the same subword as Beh-Hah.
  const std::vector<LineToJustify> sameSubwordInput{{u"تَحْمَلْ", width, LineJustification::Distribute, LineType::Line}};
  bool preferredMeemLam = false;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    preferredMeemLam |= trace.decision == "applied" && trace.rule == "PreferredFinalAscendantKashida";
  });
  const auto blockedPage = layout.justifyPage(scale, width, sameSubwordInput, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, options, "qpc_v1_layout");
  layout.setJustificationTraceCallback({});
  require(blockedPage.size() == 1 && preferredMeemLam, "Same-subword probe must first accept the preferred Meem-Lam stretch");
  bool retainedBeh = false, retainedHah = false;
  for (const auto& glyph : blockedPage.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    retainedBeh |= name == "behshape.init.beforehah";
    retainedHah |= name == "hah.medi.afterbeh";
  }
  require(retainedBeh && retainedHah, "Last-resort decomposition must not open another connection in an already-stretched subword");

  // Isolate the authored last-resort stage so earlier preferred actions do
  // not consume Ain-Alef before its own last-resort rule can be exercised.
  auto& catalog = *layout.compiledJustificationCatalog;
  const int staged = catalog.stretchPolicyIndex("staged_pool");
  require(staged >= 0, "Missing staged_pool policy");
  auto probe = catalog.stretchPolicies.at(staged);
  probe.name = "test.last_resort_only";
  std::erase_if(probe.steps, [](const auto& step) { return step.stage != "DecomposeLastResort"; });
  require(probe.steps.size() == 1, "Missing last-resort stage");
  const int probeIndex = static_cast<int>(catalog.stretchPolicies.size());
  catalog.stretchPolicies.push_back(std::move(probe));
  const JustOption probeOptions{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard, probeIndex};
  const std::vector<LineToJustify> ainInput{{u"عَا", width, LineJustification::Distribute, LineType::Line}};
  const auto ainPage = layout.justifyPage(scale, width, ainInput, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, probeOptions, "qpc_v1_layout");
  catalog.stretchPolicies.pop_back();
  require(ainPage.size() == 1, "Missing Ain-Alef proof line");
  bool ain = false, alef = false;
  for (const auto& glyph : ainPage.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    require(name != "ain.init.finjani", "Ain-Alef last resort must replace the compact Finjani form");
    if (name == "ain.init") ain = glyph.parameters.lefttatweel == 0.5;
    if (name == "alef.fina") alef = glyph.parameters.righttatweel == 0.25;
  }
  require(ain && alef, "Last-resort Ain-Alef must use left 0.5 and ascendant incoming right 0.25");
}

void checkSerialization(OtLayout& layout) {
  layout.setExtended(false);  // Standard OTF reads parameters from materialized glyph IDs.
  GlyphParameters parameters;
  parameters.lefttatweel = 1;
  const auto* variant = layout.getAlternate(layout.glyphCodePerName.at("fatha.stretched"), parameters, true, true);
  int checked = 0;
  for (auto* lookup : layout.lookups) {
    if (!lookup->name.starts_with("fatha.stretched.default")) continue;
    require(lookup->type == Lookup::mark2mark && lookup->feature.empty(), "Style helper must only execute through its contextual selector");
    for (auto* raw : lookup->subtables) {
      auto& subtable = *static_cast<MarkBaseSubtable*>(raw);
      // Numeric coverage keeps this probe independent of exporter's coverage-cache lifecycle.
      subtable.classes.at("topmarks").markCodes.insert(variant->charcode);
      const auto bytes = subtable.getOpenTypeTable(false);
      require(u16(bytes, 0) == 1, "Expected standard MarkMarkPos format 1");
      const auto found = subtable.markCodes.find(variant->charcode);
      require(found != subtable.markCodes.end(), "Parameterized Fatha missing from coverage");
      const auto index = std::distance(subtable.markCodes.begin(), found);
      const auto markArray = u16(bytes, 8);
      const auto anchor = markArray + u16(bytes, markArray + 2 + index * 4 + 2);
      const auto expected = subtable.getMarkAnchor("fatha.stretched", "topmarks", parameters);
      require(u16(bytes, anchor) == 1, "Expected standard own-glyph anchor format 1");
      require(std::int16_t(u16(bytes, anchor + 2)) == expected.x() && std::int16_t(u16(bytes, anchor + 4)) == expected.y(), "Serialized anchor differs from live own-parameter calculation");
      ++checked;
    }
  }
  require(checked == 15, "Expected five dot styles and five split Shadda/other-parent styles");
  const auto* selector = layout.lookups.at(layout.lookupsIndexByName.at("fatha.stretched.mkmk"));
  require(selector->type == Lookup::chainingpos, "Expected standard chained-context positioning");
  for (auto* raw : selector->subtables) require(u16(raw->getOpenTypeTable(false), 0) == 3, "Expected standard ChainContextPos format 3");

  const std::string baseName = "yehshape.fina.ii.expa";
  const auto* baseVariant = layout.getAlternate(layout.glyphCodePerName.at(baseName), parameters, true, true);
  const auto shadda = layout.glyphCodePerName.at("shadda");
  Lookup lookup(&layout);
  lookup.name = "serialized.upper.fallback.probe";
  lookup.type = Lookup::mark2base;
  MarkBaseSubtable subtable(&lookup);
  subtable.sortedBaseCodes = {static_cast<std::uint16_t>(baseVariant->charcode)};
  auto& row = subtable.classes["arbitrary_upper_name"];
  row.markCodes = {shadda};
  row.markanchors["shadda"] = Point(0, 0);
  row.baseparameters[baseName] = Point(5, 7);
  row.basefunction = [](std::string, std::string, Point adjust, GlyphParameters) { return Point(11, 22) + adjust; };
  for (const bool upper : {true, false}) {
    const auto markName = upper ? "shadda" : "kasra";
    row.markCodes = {layout.glyphCodePerName.at(markName)};
    row.markanchors[markName] = Point(0, 0);
    layout.prepareAnchorResolution();
    const auto bytes = subtable.getOpenTypeTable(false);
    const auto baseArray = u16(bytes, 10);
    const auto anchor = baseArray + u16(bytes, baseArray + 2);
    const auto expected = subtable.getBaseAnchor(baseName, "arbitrary_upper_name", parameters);
    require(u16(bytes, 0) == 1 && u16(bytes, anchor) == 1 && std::int16_t(u16(bytes, anchor + 2)) == expected.x() && std::int16_t(u16(bytes, anchor + 4)) == expected.y(), "Standard MarkBasePos export must use the same font fallback or nullopt calculator path as live shaping");
  }

  // A newly baked mark variant remains a member of its source's font class.
  const auto fatha = layout.glyphCodePerName.at("fatha.stretched");
  row.markCodes = {fatha};
  layout.prepareAnchorResolution();
  const auto expected = subtable.getBaseAnchor(baseName, "arbitrary_upper_name", parameters);
  GlyphParameters markParameters;
  markParameters.lefttatweel = 2.125;
  const auto* markVariant = layout.getAlternate(fatha, markParameters, true, true);
  require(markVariant->sourceGlyphCode == fatha, "Materialized mark must record its authoritative source glyph");
  row.markCodes = {static_cast<std::uint16_t>(markVariant->charcode)};
  row.markanchors["fatha.stretched"] = Point{};
  layout.prepareAnchorResolution();
  require(subtable.getBaseAnchor(baseName, "arbitrary_upper_name", parameters) == expected, "Materialized mark membership must survive cached source-class coverage");
  const auto bytes = subtable.getOpenTypeTable(false);
  const auto baseArray = u16(bytes, 10);
  const auto anchor = baseArray + u16(bytes, baseArray + 2);
  require(std::int16_t(u16(bytes, anchor + 2)) == expected.x() && std::int16_t(u16(bytes, anchor + 4)) == expected.y(), "OTF group anchors must resolve materialized base and mark parameters consistently");
}
}  // namespace

int main(int argc, char** argv) {
  try {
    require(argc == 3, "Usage: FathaAnchorsTest FONT.mp RESOURCES");
    MPFont mpFont;
    initializeFont(mpFont, fs::absolute(argv[1]), fs::absolute(argv[2]));
    OtLayout layout(&mpFont, true, false);
    layout.useNormAxisValues = false;
    layout.loadLookupFile((fs::absolute(argv[1]).parent_path() / "features.fea").string());
    auto* font = layout.createFont(1, false);
    FontProvider provider(layout);
    for (const auto& [root, style] : {std::pair{"noon.fina.expa", 1}, {"kaf.fina.expa", 2}, {"kaf.init.ii", 3}, {"behshape.isol", 0}}) {
      for (const auto parent : {Parent::Base, Parent::Dot, Parent::Shadda}) checkDispatch(layout, provider, font, root, style, parent, 1);
      for (double left : {0.0625, 1.5, 1.5625, 5.0}) checkDispatch(layout, provider, font, root, style, Parent::Shadda, left);
    }
    for (const auto* root : {"behshape.isol.expa", "behshape.fina.expa", "alefmaksura.isol.expa", "yehshape.isol.expa", "yehshape.fina.ii.expa", "yehshape.fina.afterbeh.expa", "yehshape.fina.expa"}) {
      for (const auto parent : {Parent::Base, Parent::Dot, Parent::Shadda}) checkDispatch(layout, provider, font, root, 4, parent, 3);
    }
    for (double left : {0.0, -1.0}) {
      checkDispatch(layout, provider, font, "noon.fina.expa", 1, Parent::Dot, left);
      checkDispatch(layout, provider, font, "noon.fina.expa", 1, Parent::Dot, left, false, true);
    }
    checkDispatch(layout, provider, font, "noon.fina.expa", 1, Parent::Dot, 1, true);
    checkAutomaticAttachment(layout, provider, font);
    checkContextualFatha(layout, provider, font);
    checkCompensatedJoinedConnection(layout, provider, font);
    checkAddedMarkStretching(layout, provider, font);
    checkShaddaCenterTransition(layout);
    checkLocalAnchorsAndExpandedCentering(layout);
    checkSharedGlyphTopAnchor(layout);
    checkFontOwnedGroupAnchors(layout);
    hb_font_destroy(font);
    checkLamMeemStretching(layout);
    checkHehMeemStretching(layout);
    checkLastResortDecomposition(layout);
    checkSerialization(layout);
    std::cout << "Attachment/native/GSUB regressions, local no-lift anchors, expanded Beh/Yeh centring, baseline metadata, Shadda threshold transitions and 15 serialized anchor subtables passed\n";
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
