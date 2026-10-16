#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <tuple>
#include <hb-ot.h>
#include "MPFont.h"
#include "Layout/OtLayout.h"
#include "Layout/MushafLayout.h"
#include "Layout/Lookup.h"
#include "Layout/Subtable.h"
#include "Layout/GlyphVis.h"
#include "automedina/automedina.h"
#include "FeaParser/driver.h"
#include "FeaParser/feaast.h"
#include "JustificationShaping.h"
#include "digitalkhatt/justify/declpolicy/DeclPolicyJustifier.h"
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

void checkIqlabModeration(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  auto& attachment = layout.compiledJustificationCatalog->attachments.at(0);
  require(attachment.followingMarkGlyphNames == std::vector<std::string>{"meemiqlab"} && attachment.followingGrowthScale == 0.5, "Font must declare half-strength growth before Iqlab");
  auto width = [&](const std::u16string& text, double scale, bool contextual) {
    attachment.followingGrowthScale = scale;
    const std::vector<GlyphParameterAssignment> assignments{{0, digitalkhatt::NoGlyphAxis, 0, layout.glyphCodePerName.at("noon.fina.expa")}, {0, digitalkhatt::LeftTatweelAxis, 9}};
    std::vector<hb_feature_t> features;
    if (contextual) features.push_back({HB_TAG('c','v','0','1'), 1, 1, 2});
    ShapingBuffer buffer(shape(text, font, features, &provider, assignments, true, digitalkhatt::justify::LineJustificationOperation::Stretch));
    unsigned count = 0;
    const auto* infos = hb_buffer_get_glyph_infos(buffer.get(), &count);
    for (unsigned i = 0; i < count; ++i) {
      if (infos[i].cluster != 1) continue;
      const auto& name = layout.glyphNamePerCode.at(infos[i].codepoint);
      if (name != "fatha" && name != "fatha.stretched") continue;
      auto baseline = layout.glyphParameters(infos[i]);
      baseline.lefttatweel = contextual ? 1 : 0;
      const double initial = layout.getGlyph(infos[i].codepoint, baseline)->width;
      const double current = layout.getGlyph(infos[i].codepoint, layout.glyphParameters(infos[i]))->width;
      require(layout.glyphParameters(infos[i]).lefttatweel >= baseline.lefttatweel, "Moderation must retain the contextual GSUB deformation");
      return current - initial;
    }
    throw std::runtime_error("Missing Fatha in Iqlab moderation test");
  };
  for (const bool contextual : {false, true}) {
    const double full = width(u"نَۢ", 1, contextual);
    const double half = width(u"نَۢ", 0.5, contextual);
    require(half > 0 && std::abs(half - full * 0.5) < 20, "Iqlab must halve actual added width, allowing one quantization step");
    require(std::abs(width(u"نَ͏ۢ", 0.5, contextual) - half) < 1, "Format controls must not break Fatha/Iqlab moderation");
    for (const auto text : {u"نَ", u"نَ بۢ", u"نَشۢ", u"نَّۢ"}) require(width(text, 1, contextual) == width(text, 0.5, contextual), "Moderation must not cross a word, base or unrelated mark");
  }
  attachment.followingGrowthScale = 0.5;
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

void checkIqlabGlyphAnchors(OtLayout& layout) {
  const auto type = GlyphVis::AnchorType::MarkAnchor;
  auto* lookup = layout.lookups.at(layout.lookupsIndexByName.at("defaultmkmk"));
  MarkBaseSubtable* source = nullptr;
  for (auto* raw : lookup->subtables) {
    if (raw->name == "defaultmkmkmeemiqlab") source = static_cast<MarkBaseSubtable*>(raw);
  }
  require(source, "Missing Iqlab attachment subtable");
  const auto& row = source->classes.at("meemiqlab");
  require(!row.basefunction && !row.markfunction, "Iqlab attachment must use glyph anchors without C++ calculators");
  require(source->base == std::vector<std::string>{"fatha", "fatha.stretched", "damma"}, "Audit the authored anchor whenever another Iqlab parent is added");

  auto* meem = layout.getGlyph(layout.glyphCodePerName.at("meemiqlab"));
  require(meem->conatinsAnchor("meemiqlab", type), "Meem Iqlab must author its own mating anchor");
  auto expectedMark = meem->getAnchor("meemiqlab", type);
  if (const auto offset = row.markparameters.find("meemiqlab"); offset != row.markparameters.end()) expectedMark += offset->second;
  require(source->getMarkAnchor("meemiqlab", "meemiqlab", {}) == expectedMark, "Meem's own anchor must remain authoritative, with any saved GUI adjustment");
  auto* dotLookup = layout.lookups.at(layout.lookupsIndexByName.at("defaultmarkdotmarkstop"));
  bool checkedDot = false;
  for (auto* raw : dotLookup->subtables) {
    if (raw->name != "defaultmarkdotmarkstop") continue;
    auto& dot = *static_cast<MarkBaseSubtable*>(raw);
    require(!dot.classes.at("topmarks").markparameters.contains("meemiqlab"), "Meem's dot calibration must no longer live in JSON");
    require(meem->conatinsAnchor("defaultmarkdotmarkstop", type) && dot.getMarkAnchor("meemiqlab", "topmarks", {}) == meem->getAnchor("defaultmarkdotmarkstop", type), "Meem's lookup-specific glyph anchor must supply its upper-dot calibration");
    checkedDot = true;
  }
  require(checkedDot, "Missing upper-dot attachment subtable");

  // Export a single-pair standard GPOS probe: both anchors must be identical
  // to live resolution, including baked parameterized parent glyphs.
  Lookup exported(&layout);
  exported.name = "defaultmkmk";
  exported.type = Lookup::mark2mark;
  MarkBaseSubtable table(&exported);
  table.classes["meemiqlab"] = row;
  table.classes["meemiqlab"].markCodes = {static_cast<std::uint16_t>(meem->charcode)};
  for (const auto* parent : {"fatha", "fatha.stretched", "damma"}) {
    for (const double left : {0.0, 0.5, 1.0, 3.0, 5.0, 10.0}) {
      GlyphParameters parameters;
      parameters.lefttatweel = left;
      auto* glyph = layout.getGlyph(layout.glyphCodePerName.at(parent), parameters);
      require(glyph->conatinsAnchor("meemiqlab", type), "Every Iqlab parent must retain its authored anchor at every sampled width");
      const auto authored = glyph->getAnchor("meemiqlab", type);
      auto expected = authored;
      if (const auto offset = row.baseparameters.find(parent); offset != row.baseparameters.end()) expected += offset->second;
      require(source->getBaseAnchor(parent, "meemiqlab", parameters) == expected, "Live Iqlab positioning must resolve the glyph-authored anchor plus any saved GUI adjustment");
      if (std::string_view(parent) == "fatha.stretched") require(authored == layout.getGlyph(layout.glyphCodePerName.at("fatha"), parameters)->getAnchor("meemiqlab", type), "Stretched Fatha must inherit Fatha's authored anchor");
      const auto* variant = layout.getAlternate(layout.glyphCodePerName.at(parent), parameters, true, true);
      table.sortedBaseCodes = {static_cast<std::uint16_t>(variant->charcode)};
      const auto bytes = table.getOpenTypeTable(false);
      const auto baseArray = u16(bytes, 10);
      const auto baseAnchor = baseArray + u16(bytes, baseArray + 2);
      const auto markArray = u16(bytes, 8);
      const auto markAnchor = markArray + u16(bytes, markArray + 4);
      require(u16(bytes, 0) == 1 && u16(bytes, baseAnchor) == 1 && u16(bytes, markAnchor) == 1, "Iqlab glyph anchors must export as standard MarkMarkPos/Anchor format 1");
      require(std::int16_t(u16(bytes, baseAnchor + 2)) == expected.x() && std::int16_t(u16(bytes, baseAnchor + 4)) == expected.y(), "Exported parent anchor must match the live authored anchor");
      require(std::int16_t(u16(bytes, markAnchor + 2)) == expectedMark.x() && std::int16_t(u16(bytes, markAnchor + 4)) == expectedMark.y(), "Exported Meem anchor must match live own-anchor resolution");
    }
  }
}

void checkShaddaCenterTransition(OtLayout& layout) {
  const double centerLimit = oldmadina::FathaShaddaCenterLimit;
  MarkBaseSubtable* source = nullptr;
  for (auto* lookup : layout.lookups) {
    if (lookup->name != "defaultmkmk") continue;
    for (auto* raw : lookup->subtables) if (raw->name == "defaultmkmktop") source = static_cast<MarkBaseSubtable*>(raw);
  }
  require(source != nullptr, "Missing ordinary top mark-to-mark source");
  for (int style = 0; style <= static_cast<int>(oldmadina::FathaAnchorStyle::ExpandedBeh); ++style) {
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
    for (double left : {0.0625, 0.5, centerLimit - 1e-6, centerLimit, centerLimit + 1e-6, 1.5, 2.0, 5.0, 10.0, 20.0}) {
      GlyphParameters parameters;
      parameters.lefttatweel = left;
      const auto* current = layout.getGlyph(layout.glyphCodePerName.at("fatha"), parameters);
      const auto anchor = centered.getMarkAnchor("fatha.stretched", "topmarks", parameters);
      const auto unchanged = others.getMarkAnchor("fatha.stretched", "topmarks", parameters);
      const double originalX = style == 3 ? source->getMarkAnchor("fatha", "topmarks", parameters).x() : style == 0 ? neutralAnchor.x() + current->bbox.urx - neutral->bbox.urx : neutralAnchor.x() - neutralCenter + (current->bbox.llx + current->bbox.urx) * 0.5;
      const double lower = style == 3 ? 0.2 : style == 1 ? 0.15 : 0.25;
      const double growth = std::max(0.0, current->width - neutral->width);
      const double originalY = style == 0 ? neutralAnchor.y() + current->bbox.ury - neutral->bbox.ury : style == 4 || style == 5 ? neutralAnchor.y() : neutralAnchor.y() + lower * growth;
      require(anchor.y() == unchanged.y() && unchanged.x() == std::lround(originalX) && unchanged.y() == std::lround(originalY), "Shadda transition must leave vertical profiles and other parents unchanged");
      if (style == static_cast<int>(oldmadina::FathaAnchorStyle::Noon) || style == static_cast<int>(oldmadina::FathaAnchorStyle::ExpandedBeh) || left <= oldmadina::FathaShaddaCenterLimit) {
        const double expected = neutralAnchor.x() - neutralCenter + (current->bbox.llx + current->bbox.urx) * 0.5;
        require(anchor.x() == std::lround(expected), "Fatha above expanded Noon/Beh must remain centered on Shadda at every width; other bases retain the short-Fatha centering limit");
      } else {
        require(std::abs(current->bbox.urx - anchor.x() - limitRight) <= 1, "Long stretched Fatha must preserve the right edge of its centered threshold placement");
        require(std::abs(anchor.x() - limitAnchor.x()) <= 1 || left > centerLimit + 1e-6, "The transition must not jump at the Shadda centering limit");
      }
    }
  }
}

void checkExpandedShaddaCentering(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  int xScale = 0;
  hb_font_get_scale(font, &xScale, nullptr);
  for (const auto& [root, text] : {std::pair{"noon.isol.expa", u"نَّ"}, {"noon.fina.expa", u"نَّ"}, {"noon.fina.expa.afterbeh", u"نَّ"}, {"behshape.isol.expa", u"بَّ"}, {"behshape.fina.expa", u"بَّ"}}) {
    for (double baseLeft : {3.0, 9.0}) {
      std::optional<double> calibratedCenter;
      for (double markLeft : {0.5, 1.0, 1.5, 3.0, 5.0, 10.0, 20.0}) {
        const std::vector<GlyphParameterAssignment> assignments{
            {0, digitalkhatt::NoGlyphAxis, 0, layout.glyphCodePerName.at(root)},
            {0, digitalkhatt::LeftTatweelAxis, baseLeft},
            {2, digitalkhatt::LeftTatweelAxis, markLeft}};
        ShapingBuffer buffer(shape(text, font, {}, &provider, assignments, false));
        unsigned count = 0;
        const auto* infos = hb_buffer_get_glyph_infos(buffer.get(), &count);
        const auto* positions = hb_buffer_get_glyph_positions(buffer.get(), nullptr);
        std::optional<double> fathaCenter, shaddaCenter;
        double pen = 0;
        for (unsigned i = 0; i < count; ++i) {
          const auto& name = layout.glyphNamePerCode.at(infos[i].codepoint);
          if (name == "fatha.stretched" || name == "shadda") {
            const auto* glyph = layout.getGlyph(infos[i].codepoint, layout.glyphParameters(infos[i]));
            const double center = pen + positions[i].x_offset + (glyph->bbox.llx + glyph->bbox.urx) * 0.5 * xScale / 1000;
            (name == "shadda" ? shaddaCenter : fathaCenter) = center;
          }
          pen += positions[i].x_advance;
        }
        require(fathaCenter && shaddaCenter, "Missing Fatha/Shadda in expanded Noon/Beh shaping regression");
        const double relativeCenter = *fathaCenter - *shaddaCenter;
        if (!calibratedCenter) calibratedCenter = relativeCenter;
        require(std::abs(relativeCenter - *calibratedCenter) <= std::abs(xScale) / 1000.0, std::string(root) + ": stretched Fatha must keep its calibrated center above Shadda beyond lefttatweel 1");
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
      const auto style = std::string_view(root).starts_with("behshape.") ? oldmadina::FathaAnchorStyle::ExpandedBeh : oldmadina::FathaAnchorStyle::Centered;
      if (!subtable.name.ends_with(".fatha." + std::to_string(static_cast<int>(style))) || std::find(subtable.base.begin(), subtable.base.end(), root) == subtable.base.end()) continue;
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

void checkShrinkAlefAboveDal(OtLayout& layout, FontProvider& provider, hb_font_t* font) {
  using namespace digitalkhatt::justify::runtime;
  const auto* normal = layout.getGlyph(layout.glyphCodePerName.at("alef.isol"));
  const auto* shorter = layout.getGlyph(layout.glyphCodePerName.at("alef.isol.ii"));
  require(shorter->bbox.ury - shorter->bbox.lly < normal->bbox.ury - normal->bbox.lly, "alef.isol.ii must have a shorter outline");
  for (const auto& [text, matches] : std::vector<std::pair<std::u16string, bool>>{{u"عَذَابٌ", true}, {u"عَدَابٌ", true}, {u"عَذْابٌ", false}}) {
    for (bool shrink : {false, true}) {
      std::vector<hb_feature_t> features;
      if (shrink) features.push_back({HB_TAG('s', 'k', '0', '3'), 1, 0, static_cast<unsigned>(-1)});
      auto* buffer = shape(text, font, features, &provider, {}, false);
      unsigned count = 0;
      const auto* infos = hb_buffer_get_glyph_infos(buffer, &count);
      const auto* positions = hb_buffer_get_glyph_positions(buffer, nullptr);
      bool alef = false;
      for (unsigned i = 0; i < count; ++i) {
        if (infos[i].cluster != 4) continue;
        const auto& name = layout.glyphNamePerCode.at(infos[i].codepoint);
        const bool replaced = shrink && matches;
        require(name == (replaced ? "alef.isol.ii" : "alef.isol"), "Short Alef substitution must follow the Dal-Fatha shrinking context only");
        if (replaced) require(positions[i].y_offset > 0, "Short Alef must retain the shrinking placement above Dal");
        alef = true;
      }
      hb_buffer_destroy(buffer);
      require(alef, "Missing Alef in Dal-Alef shrink probe");
    }
  }
}

void checkLamMeemStretching(OtLayout& layout) {
  using namespace digitalkhatt;
  const int width = 1800 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard, layout.compiledJustificationCatalog->stretchPolicyIndex("staged_pool_continue")};
  const std::vector<LineToJustify> input{{u"وَلَمْ", width, LineJustification::Distribute, LineType::Line}};
  bool preferred = false, continued = false;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    if (trace.decision != "applied") return;
    preferred |= trace.selection == "CandidatePreferred" && trace.rule == "PreferredLamMeemKashida";
    continued |= trace.rule == "PreferredLamMeemKashida" && trace.reason == "continued";
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
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard, layout.compiledJustificationCatalog->stretchPolicyIndex("staged_pool_continue")};
  for (const auto& [text, hehName] : std::vector<std::pair<std::u16string, std::string>>{{u"هَمْ", "heh.init"}, {u"مَهَمْ", "heh.medi"}}) {
    const std::vector<LineToJustify> input{{text, width, LineJustification::Distribute, LineType::Line}};
    bool preferred = false;
    layout.setJustificationTraceCallback([&](const auto& trace) {
      if (trace.decision != "applied") return;
      preferred |= trace.selection == "CandidatePreferred" && trace.rule == "PreferredHehMeemKashida";
      if (trace.rule != "PreferredHehMeemKashida") return;
      int endpointCount = 0;
      for (const auto& parameter : trace.parameters) {
        if (parameter.attribute != "lefttatweel" && parameter.attribute != "righttatweel") continue;
        ++endpointCount;
        require(parameter.maximumValue <= 1.5, "Heh-final-Meem continuation must retain its authored maximum");
        if (trace.reason != "continued") require(parameter.minimumValue == 0.5 && parameter.maximumValue == 1.5, "Heh-final-Meem preferred endpoints must use the 0.5..1.5 range");
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

void checkFinalAscendantPrecedence(OtLayout& layout) {
  using namespace digitalkhatt;
  const int width = 5000 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard, layout.compiledJustificationCatalog->stretchPolicyIndex("staged_pool_continue")};
  const std::vector<LineToJustify> input{{u"أَحْبَارَهُمْ", width, LineJustification::Distribute, LineType::Line}};
  bool behAlef = false, hehMeem = false, continued = false;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    if (trace.decision != "applied") return;
    behAlef |= trace.rule == "PreferredFinalAscendantKashida";
    hehMeem |= trace.rule == "PreferredHehMeemKashida";
    continued |= trace.rule == "PreferredFinalAscendantKashida" && trace.reason == "continued";
  });
  const auto page = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, options, "qpc_v1_layout");
  layout.setJustificationTraceCallback({});
  require(page.size() == 1 && behAlef && !hehMeem && continued, "Beh-Alef must win over Heh-Meem and retain the existing final-ascendant continuation");
  bool beh = false, alef = false, compactHeh = false, compactMeem = false;
  for (const auto& glyph : page.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    if (name == "behshape.medi.expa") beh = glyph.parameters.lefttatweel > 0;
    if (name == "alef.fina") alef = glyph.parameters.righttatweel > 0;
    if (name == "heh.init" || name == "heh.init.beforemeem") compactHeh = glyph.parameters.lefttatweel >= 0 && glyph.parameters.lefttatweel <= 0.5;
    if (name == "meem.fina.ii" || name == "meem.fina.afterheh") compactMeem = glyph.parameters.righttatweel >= 0 && glyph.parameters.righttatweel <= 0.5;
  }
  require(beh && alef && compactHeh && compactMeem, "Chosen Beh-Alef must stretch both endpoints while the competing Heh-Meem stays within short baseline spacing");
}

void checkLastResortDecomposition(OtLayout& layout) {
  using namespace digitalkhatt;
  const int width = 5000 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard, layout.compiledJustificationCatalog->stretchPolicyIndex("staged_pool_continue")};
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
    if (name == "behshape.init" && glyph.cluster == 0) beh = glyph.parameters.lefttatweel == 1;
    if (name == "hah.medi") hah = glyph.parameters.righttatweel == 1;
    if (name == "heh.medi") heh = glyph.parameters.lefttatweel > 0;
    if (name == "meem.fina.ii") meem = glyph.parameters.righttatweel > 0;
  }
  require(beh && hah && heh && meem, "Last-resort endpoints must stay at 1 and preserve the earlier Heh-Meem stretching");

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
  const auto hahRule = std::find_if(catalog.rules.begin(), catalog.rules.end(), [](const auto& rule) { return rule.name == "LastResortBeforeHah"; });
  require(hahRule != catalog.rules.end(), "Missing Hah-ligature last-resort rule");
  for (const auto& [first, second] : std::vector<std::pair<std::string, std::string>>{{"behshape.init.beforehah", "hah.medi.afterbeh"}, {"meem.init.beforehah", "hah.medi.aftermeem"}, {"fehshape.init.beforehah", "hah.medi.afterfeh"}, {"sad.init.beforehah", "hah.medi.aftersad"}, {"lam.init.lam_hah", "hah.medi.lam_hah"}}) {
    const std::array facts{digitalkhatt::justify::glyphFacts({.glyphName = first}, catalog.facts), digitalkhatt::justify::glyphFacts({.glyphName = second}, catalog.facts)};
    const auto matches = catalog.dfa->match(facts);
    require(std::any_of(matches.begin(), matches.end(), [&](const auto& match) { return match.ruleId == hahRule->id; }), first + "-" + second + " must be covered by last-resort Hah decomposition");
  }
  for (const auto& [first, second] : std::vector<std::pair<std::string, std::string>>{{"lam.init", "hah.medi.ii"}, {"lam.init.beforehahyeh", "hah.medi.afterlam.beforeyeh"}, {"behshape.init.beforehah", "hah.medi.afterbeh.beforeyeh"}}) {
    const std::array facts{digitalkhatt::justify::glyphFacts({.glyphName = first}, catalog.facts), digitalkhatt::justify::glyphFacts({.glyphName = second}, catalog.facts)};
    const auto matches = catalog.dfa->match(facts);
    require(std::none_of(matches.begin(), matches.end(), [&](const auto& match) { return match.ruleId == hahRule->id; }), "Ordinary Hah connections and three-glyph compounds must not match two-glyph last-resort decomposition");
  }
  const int staged = catalog.stretchPolicyIndex("staged_pool_continue");
  require(staged >= 0, "Missing staged_pool_continue policy");
  auto probe = catalog.stretchPolicies.at(staged);
  probe.name = "test.last_resort_only";
  std::erase_if(probe.steps, [](const auto& step) { return step.stage != "DecomposeLastResort"; });
  require(probe.steps.size() == 1, "Missing last-resort stage");
  const int probeIndex = static_cast<int>(catalog.stretchPolicies.size());
  catalog.stretchPolicies.push_back(std::move(probe));
  const JustOption probeOptions{JustType::DeclPolicy, JustStyle::XScale, ShrinkType::Standard, probeIndex};
  const std::vector<LineToJustify> ainInput{{u"عَا", width, LineJustification::Distribute, LineType::Line}};
  const auto ainPage = layout.justifyPage(scale, width, ainInput, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, probeOptions, "qpc_v1_layout");
  require(ainPage.size() == 1, "Missing Ain-Alef proof line");
  bool ain = false, alef = false;
  for (const auto& glyph : ainPage.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    require(name != "ain.init.finjani", "Ain-Alef last resort must replace the compact Finjani form");
    if (name == "ain.init") ain = glyph.parameters.lefttatweel == 1;
    if (name == "alef.fina") alef = glyph.parameters.righttatweel == 0.5;
  }
  require(ain && alef, "Last-resort Ain-Alef must use left 1 and ascendant incoming right 0.5");

  for (const auto& [text, firstName, hahName] : std::vector<std::tuple<std::u16string, std::string, std::string>>{{u"لَحَمْ", "lam.init", "hah.medi"}, {u"مَحَمْ", "meem.init", "hah.medi"}}) {
    const std::vector<LineToJustify> hahInput{{text, width, LineJustification::Distribute, LineType::Line}};
    const auto hahPage = layout.justifyPage(scale, width, hahInput, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, probeOptions, "qpc_v1_layout");
    require(hahPage.size() == 1, "Missing Hah-ligature last-resort proof line");
    bool first = false, hah = false;
    for (const auto& glyph : hahPage.front().glyphs) {
      const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
      require(name != "lam.init.lam_hah" && name != "lam.init.beforehahyeh" && name != "hah.medi.lam_hah" && name != "hah.medi.afterlam.beforeyeh" && name != "behshape.init.beforehah" && name != "meem.init.beforehah", "Last resort must open the incoming Hah ligature");
      if (name == firstName) first = glyph.parameters.lefttatweel == 1;
      if (name == hahName) hah = glyph.parameters.righttatweel == 1;
    }
    require(first && hah, firstName + "-" + hahName + " must open at 1 / 1");
  }
  for (const auto& [text, firstName, hahName] : std::vector<std::tuple<std::u16string, std::string, std::string>>{{u"لَحِيَ", "lam.init.beforehahyeh", "hah.medi.afterlam.beforeyeh"}, {u"بَحِيَ", "behshape.init.beforehah", "hah.medi.afterbeh.beforeyeh"}}) {
    const std::vector<LineToJustify> compoundInput{{text, width, LineJustification::Distribute, LineType::Line}};
    const auto compoundPage = layout.justifyPage(scale, width, compoundInput, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, probeOptions, "qpc_v1_layout");
    require(compoundPage.size() == 1, "Missing three-glyph compound proof line");
    bool first = false, hah = false;
    for (const auto& glyph : compoundPage.front().glyphs) {
      const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
      if (name == firstName) first = glyph.parameters.lefttatweel == 0;
      if (name == hahName) hah = glyph.parameters.righttatweel == 0;
    }
    require(first && hah, "Last-resort decomposition must preserve the three-glyph " + firstName + "-" + hahName + "-Yeh compound");
  }
  catalog.stretchPolicies.pop_back();

  // Seen-Reh wins first, then Ain-Alef opens minimally in another subword.
  // Last resort takes ownership of Horizontal; retained Seen-Reh must respect
  // that competing record instead of treating it as its own continuation.
  const std::vector<LineToJustify> shurraInput{{u"شُرَّعࣰا", width, LineJustification::Distribute, LineType::Line}};
  bool rehBlocked = false, ainContinued = false;
  std::string continuationTrace;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    continuationTrace += trace.rule + ":" + trace.decision + ":" + trace.reason + " ";
    rehBlocked |= trace.rule == "PreferredRehKashida" && trace.decision == "rejected" && trace.reason == "record_constraint";
    if (trace.decision != "applied") return;
    ainContinued |= trace.rule == "PreferredFinalAscendantKashida" && trace.reason == "continued";
  });
  const auto shurraPage = layout.justifyPage(scale, width, shurraInput, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES, options, "qpc_v1_layout");
  layout.setJustificationTraceCallback({});
  require(shurraPage.size() == 1 && rehBlocked && !ainContinued, "Minimal Ain-Alef must stay locked and its competing Horizontal record must remain respected: " + continuationTrace);
  bool minimalAin = false, minimalAlef = false;
  for (const auto& glyph : shurraPage.front().glyphs) {
    const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
    require(name != "ain.init.finjani", "Small decomposition must happen before continuation consumes the line gap");
    if (name == "ain.init") minimalAin = glyph.parameters.lefttatweel == 1;
    if (name == "alef.fina") minimalAlef = glyph.parameters.righttatweel == 0.5;
  }
  require(minimalAin && minimalAlef, "Final Ain-Alef parameters must remain 1 / 0.5 after the complete staged-pool recipe");
}

void checkLateBaselineSpacing(OtLayout& layout) {
  using namespace digitalkhatt;
  using namespace digitalkhatt::justify;
  auto& catalog = *layout.compiledJustificationCatalog;
  const int source = catalog.stretchPolicyIndex("staged_pool_continue");
  require(source >= 0, "Missing stage-continuation stretch policy");
  const auto& steps = catalog.stretchPolicies.at(source).steps;
  const auto preferred = std::find_if(steps.begin(), steps.end(), [](const auto& step) { return step.stage == "PreferredStretch"; });
  const auto baselineSelection = std::find_if(catalog.selections.begin(), catalog.selections.end(), [](const auto& selection) { return selection.name == "InitialShortJoins"; });
  require(preferred != steps.end() && baselineSelection != catalog.selections.end(), "Missing preferred/baseline stages");
  auto probe = catalog.stretchPolicies.at(source);
  probe.name = "test.late_baseline";
  const LinePolicyStep baselineStep{.operation = LineStepOp::Stage, .stage = "InitialShortStretch", .phases = {{.selection = static_cast<JustificationSelectionId>(baselineSelection - catalog.selections.begin()), .levels = 1, .allocator = PolicyPhase::Allocator::BaselinePool}}};
  probe.steps = {*preferred};
  const int index = static_cast<int>(catalog.stretchPolicies.size());
  catalog.stretchPolicies.push_back(probe);
  const int width = 10000 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::None, ShrinkType::Standard, index};
  const std::vector<LineToJustify> input{{u"بل مم", width, LineJustification::Distribute, LineType::Line}};
  const auto before = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  catalog.stretchPolicies.back().steps.push_back(baselineStep);
  bool skipped = false, applied = false;
  layout.setJustificationTraceCallback([&](const auto& trace) {
    if (trace.selection != "InitialShortJoins") return;
    skipped |= trace.decision == "rejected" && trace.reason == "baseline_unsupported_or_nonzero";
    applied |= trace.decision == "applied" && trace.reason == "baseline_spacing";
  });
  const auto after = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  layout.setJustificationTraceCallback({});
  require(before.size() == 1 && after.size() == 1 && before[0].glyphs.size() == after[0].glyphs.size(), "Late baseline spacing must preserve glyph identities");
  require(skipped && applied, "Late baseline spacing must skip stretched connections and still apply to untouched ones");
  bool preserved = false, added = false;
  for (std::size_t i = 0; i < before[0].glyphs.size(); ++i) {
    const auto& first = before[0].glyphs[i];
    const auto& second = after[0].glyphs[i];
    require(first.codepoint == second.codepoint && first.cluster == second.cluster, "Late baseline spacing must not substitute glyphs");
    for (const auto axis : {LeftTatweelAxis, RightTatweelAxis}) {
      const auto value = first.parameters.value(axis);
      if (value != 0) {
        require(second.parameters.value(axis) == value, "Late baseline spacing must preserve prior stretching exactly");
        preserved = true;
      } else {
        added |= second.parameters.value(axis) > 0;
      }
    }
  }
  require(preserved && added, "Late baseline proof must contain both existing and newly added stretching");
  const auto opportunity = std::find_if(catalog.rules.begin(), catalog.rules.end(), [](const auto& rule) { return rule.name == "InitialShortJoin"; });
  require(opportunity != catalog.rules.end(), "Missing baseline opportunity");
  const auto binding = std::find_if(catalog.actions.begin(), catalog.actions.end(), [&](const auto& action) { return action.rule == opportunity->id; });
  require(binding != catalog.actions.end() && binding->definition >= 0, "Missing baseline opportunity body");
  const auto action = catalog.actionDefinitions.begin() + binding->definition;
  const auto vary = std::find_if(action->effects.begin(), action->effects.end(), [](const auto& effect) { return effect.kind == JustEffectKind::Vary; });
  require(vary != action->effects.end(), "Missing baseline endpoint");
  const auto endpoint = vary->value;
  for (const double invalid : {0.0, -0.5, std::numeric_limits<double>::infinity()}) {
    vary->value = {{.literal = invalid}};
    bool rejected = false;
    try {
      (void)layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
    } catch (const std::runtime_error& error) {
      rejected = std::string_view(error.what()).find("baseline_pool requires native vary ranges") != std::string_view::npos;
    }
    require(rejected, "Late baseline spacing must still reject invalid endpoints");
  }
  vary->value = endpoint;
  catalog.stretchPolicies.pop_back();
}

void checkRelativeMarginSyntax() {
  const auto source = [](std::string_view step) {
    return "table(justdfa) margin_syntax { pagepolicy { measure [Line]; sizing style AdaptiveMargins { " + std::string(step) + " bounded_fit 0.95 1.2 0 0; } } facts {} opportunities {} selections {} stretchpolicy normal { fill_spaces; } shrinkpolicy normal { balance; } };";
  };
  feayy::FeaContext context(nullptr);
  feayy::Driver driver(context);
  require(driver.parse_string(source("margins decrease 300 increase 900;")), "Parser must accept explicit relative margin adjustments");
  const auto& step = context.justificationDfas.at("margin_syntax").pagePolicy->branches.at(0).steps.at(0);
  require(step.operation == "relative_margins" && step.arguments == std::vector<double>{300, 900}, "Parser must preserve the decrease/increase order and values");
  for (const auto invalid : {"margins increase 300 decrease 900;", "margins decrease 300 increase;", "margins decrease 300 900;", "margins decrease 300 grow 900;", "other decrease 300 increase 900;"}) {
    feayy::FeaContext invalidContext(nullptr);
    feayy::Driver invalidDriver(invalidContext);
    require(!invalidDriver.parse_string(source(invalid)), "Parser must reject malformed relative margin syntax: " + std::string(invalid));
  }
}

void checkContinuationSyntax() {
  const auto source = [](std::string_view steps) {
    return "table(justdfa) test { linepolicy { stretch test; shrink test; } facts {} opportunities {} selections {} stretchpolicy test { " + std::string(steps) + " } shrinkpolicy test { balance; } };";
  };
  feayy::FeaContext context(nullptr);
  feayy::Driver driver(context);
  require(driver.parse_string(source("stage Preferred; stage Preferred continue by 1; stage Preferred continue to 9; stage Preferred continue;")), "Parser must accept all three continuation forms");
  const auto& steps = context.justificationDfas.at("test").stretchPolicies.at(0).steps;
  require(steps.size() == 4 && steps[0].continuation.empty() && steps[1].continuation == "by" && steps[1].continuationLimit == 1 && steps[2].continuation == "to" && steps[2].continuationLimit == 9 && steps[3].continuation == "maximum", "Parser must preserve relative, absolute and full continuation modes");
  for (const auto invalid : {"stage Preferred increment 1;", "stage Preferred continue by 0;", "stage Preferred continue to -1;", "stage Preferred continue 9;"}) {
    feayy::FeaContext invalidContext(nullptr);
    feayy::Driver invalidDriver(invalidContext);
    require(!invalidDriver.parse_string(source(invalid)), "Parser must reject invalid or removed stage syntax: " + std::string(invalid));
  }
}

void checkOpportunitySyntax(OtLayout& layout) {
  using namespace digitalkhatt::justify;
  const auto source = [](std::string_view body) {
    return "table(justdfa) syntax { facts { fact Named form terminal chars [\"ن\"]; } " + std::string(body) + " selections { selection Pick { choose Inline last selected_only; } } stages { stage Main { phase Pick 1 candidate_pool; } } stretchpolicy normal { stage Main; } shrinkpolicy normal { balance; } };";
  };
  const std::string shared = "actions { action Shared { prepare { forbid $self:righttatweel > 0; } range $self:lefttatweel minimum 1 preferred 3 maximum 9; } } ";
  const std::string patterns = "patterns { pattern Terminal [{ form terminal chars [\"ن\"] }]; pattern Connection [Named { form medi position first glyphs [meem.init meem.medi] }]; } ";
  const std::string opportunities = "opportunities { opportunity Inline { match Terminal; action Shared; } opportunity Mixed { match Connection; prepare { update $1:third = 1; } range $1:third preferred 4; } opportunity Local { match [Named]; prepare { lookup $self justify.expand_terminal; } range $self:lefttatweel minimum 1 preferred 3 maximum 9; } opportunity Direct { match [{ form terminal chars [\"ن\"] }]; action Shared; } }";
  feayy::FeaContext context(&layout);
  feayy::Driver driver(context);
  require(driver.parse_string(source(patterns + shared + opportunities)), "Parser must accept named and inline patterns, shared/inline opportunity bodies and mixed fact slots");
  const auto& authored = context.justificationDfas.at("syntax");
  require(authored.rules.empty() && authored.actions.empty() && authored.opportunities.size() == 4 && authored.patterns.size() == 2 && authored.opportunities[0].patternName == "Terminal", "Opportunity parsing must preserve named pattern references without separate rule or bind declarations");
  auto compiled = compileJustificationCatalog(authored);
  require(compiled.facts.size() == 2 && compiled.rules[1].pattern.size() == 2 && compiled.facts[1].glyphSetRef >= 0, "Inline facts must intern with named facts and preserve deferred glyph-set resolution");
  require(compiled.rules[0].pattern == compiled.rules[3].pattern && compiled.rules[0].id != compiled.rules[3].id, "Named and inline pattern spellings must compile to identical predicates with independent opportunity IDs");
  resolveJustificationGlyphSets(compiled, [&](int ref) {
    std::vector<std::string> names;
    for (const auto code : context.justificationGlyphSets.at(ref)->getCodes(&layout)) names.push_back(layout.glyphNamePerCode.at(code));
    return names;
  });
  const auto inlineMask = std::uint64_t{1} << 1;
  require((glyphFacts({.glyphName = "meem.medi", .firstInSubword = true}, compiled.facts) & inlineMask) != 0 &&
              (glyphFacts({.glyphName = "meem.medi", .firstInSubword = false}, compiled.facts) & inlineMask) == 0 &&
              (glyphFacts({.glyphName = "behshape.medi", .firstInSubword = true}, compiled.facts) & inlineMask) == 0,
          "Inline glyph-set, form and position constraints must be ANDed after live coverage resolution");
  const auto& effects = compiled.actionDefinitions.front().effects;
  require(effects.size() == 3 && effects[0].kind == JustEffectKind::Forbid && effects[1].kind == JustEffectKind::Update && effects[2].kind == JustEffectKind::Vary && !effects[2].maximum.empty(), "prepare/range must lower to the existing ordered guard, minimum update and bounded range");
  for (const auto invalid : {
           "rules { rule Inline [Named]; } actions { bind Inline Old; }",
           "opportunities { opportunity Inline { match [Named]; update $self:third = 1; } }",
           "opportunities { opportunity Inline { match [Named]; range $self:third minimum 1; } }",
           "opportunities { opportunity Inline { match [Named]; range $self:third preferred 2 preferred 3; } }",
           "opportunities { opportunity Inline { match [Named]; action Shared; prepare { update $self:third = 1; } } }",
           "opportunities { opportunity Inline { match []; prepare { update $self:third = 1; } } }",
           "opportunities { opportunity Inline { match [Named]; prepare { vary $self:third to 4; } } }",
           "patterns { pattern Empty []; } opportunities {}",
           "patterns { pattern Terminal [Named]; } opportunities { opportunity Inline { match Terminal [Named]; action Shared; } }"}) {
    feayy::FeaContext invalidContext(&layout);
    feayy::Driver invalidDriver(invalidContext);
    require(!invalidDriver.parse_string(source(invalid)), "Parser must reject removed or ambiguous opportunity syntax");
  }
}

void checkAdaptiveMargins(OtLayout& layout) {
  using namespace digitalkhatt;
  using namespace digitalkhatt::justify;
  auto& policy = *layout.compiledJustificationCatalog->pagePolicy;
  const auto saved = policy;
  const auto originalGeometry = layout.pageLayout();
  auto geometry = originalGeometry;
  geometry.leftMargin = 400;
  geometry.rightMargin = 800;
  layout.setPageLayout(geometry);
  auto rule = std::find_if(policy.sizing.begin(), policy.sizing.end(), [](const auto& value) { return value.style == JustStyle::AdaptiveMargins; });
  require(rule != policy.sizing.end(), "Missing AdaptiveMargins page policy");
  rule->relativeMargins = false;  // Retain absolute-margin compatibility coverage.
  rule->margins = {600, 600};
  const int unit = 1 << OtLayout::SCALEBY;
  const int width = geometry.textWidth() * unit;
  const double scale = unit * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::AdaptiveMargins, ShrinkType::None};
  const std::vector<LineToJustify> input{
      {u"بِسْمِ ٱللَّهِ", width, LineJustification::Distribute, LineType::Line},
      {u"عَلِيمٌ", width / 2, LineJustification::Center, LineType::Line},
      {u"بِسْمِ ٱللَّهِ", width, LineJustification::Center, LineType::Bism},
      {u"عَلِيمٌ", 0, LineJustification::Center, LineType::Line}};
  const auto output = layout.justifyPage(scale, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  const auto rightReference = (geometry.pageWidth - geometry.rightMargin) * unit;
  require(output[0].desiredLineWidth == width, "Equal margin bounds must produce the expected frame");
  require(output[0].xstartposition == -200 * unit, "Adaptive frame must compensate asymmetric reference margins");
  require(std::abs(output[0].renderedOverflow()) < 1, "Adaptive body must fit its selected frame");
  require(output[1].desiredLineWidth == width / 2 && output[3].desiredLineWidth == 0, "Short and natural line targets must retain their meaning");
  for (std::size_t i = 1; i < output.size(); ++i) {
    const double center = rightReference - output[i].xstartposition - output[i].renderedWidth() / 2;
    require(std::abs(center - geometry.pageWidth * unit / 2.0) <= 1, "Headings and centered lines must remain at the physical page center");
  }
  require(layout.textWidth() == geometry.textWidth() && layout.pageLayout().rightMargin == 800, "Adaptive fitting must not mutate global geometry");
  rule->margins = {800, 800};
  const auto narrower = layout.justifyPage(scale * 0.9, width, input, false, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  require(narrower[0].desiredLineWidth == (geometry.pageWidth - 1600) * unit, "Physical margin bounds must not change with font size");
  require(narrower[1].desiredLineWidth == narrower[0].desiredLineWidth / 2, "Short lines must track the selected frame proportionally");
  policy = saved;
  layout.setPageLayout(originalGeometry);
}

void checkAdaptivePreview(OtLayout& layout) {
  using namespace digitalkhatt;
  const auto saved = layout.pageLayout();
  auto geometry = saved;
  geometry.pageWidth = 17600;
  geometry.leftMargin = geometry.rightMargin = 600;
  layout.setPageLayout(geometry);
  const int unit = 1 << OtLayout::SCALEBY;
  const int width = geometry.textWidth() * unit;
  const auto& sizing = layout.compiledJustificationCatalog->pagePolicy->sizing;
  const auto rule = std::find_if(sizing.begin(), sizing.end(), [](const auto& value) { return value.style == JustStyle::AdaptiveMargins; });
  require(rule != sizing.end() && rule->relativeMargins, "OldMadina must declare relative margin adjustments");
  const int decrease = static_cast<int>(std::floor(std::min(rule->margins->first, 600.0) * unit));
  // All of page 577, including its shortest and longest lines. A subset misses
  // the raw-interval conflict that individual margin clamping must resolve.
  const std::vector<std::string> text{
      "فَمَا تَنفَعُهُمْ شَفَٰعَةُ ٱلشَّٰفِعِينَ \u06dd٤٨ فَمَا لَهُمْ عَنِ ٱلتَّذْكِرَةِ مُعْرِضِينَ",
      "۝٤٩ كَا͏ٔ͏َنَّهُمْ حُمُرࣱ مُّسْتَنفِرَةࣱ ۝٥٠ فَرَّتْ مِن قَسْوَرَةِۭ ۝٥١ بَلْ يُرِيدُ",
      "كُلُّ ٱمْرِي͏ٔ͏ࣲ مِّنْهُمْ ا͏ٔ͏َن يُو͏ٔ͏ْتَىٰ صُحُفࣰا مُّنَشَّرَةࣰ ۝٥٢ كَلَّاۖ بَل لَّا يَخَافُونَ",
      "ٱلْـٔ͏َاخِرَةَ ۝٥٣ كَلَّا͏ٓ إ͏ِنَّهُۥ تَذْكِرَةࣱ ۝٥٤ فَمَن شَا͏ٓءَ ذَكَرَهُۥ ۝٥٥",
      "وَمَا يَذْكُرُونَ إ͏ِلَّا͏ٓ ا͏ٔ͏َن يَشَا͏ٓءَ ٱللَّهُۚ هُوَ ا͏ٔ͏َهْلُ ٱلتَّقْوَىٰ وَا͏ٔ͏َهْلُ ٱلْمَغْفِرَةِ ۝٥٦",
      "سُورَةُ القِيَامَةِ",
      "بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ",
      "لَا͏ٓ ا͏ٔ͏ُقْسِمُ بِيَوْمِ ٱلْقِيَٰمَةِ ۝١ وَلَا͏ٓ ا͏ٔ͏ُقْسِمُ بِٱلنَّفْسِ ٱللَّوَّامَةِ ۝٢ ا͏ٔ͏َيَحْسَبُ",
      "ٱلْإ͏ِنسَٰنُ ا͏ٔ͏َلَّن نَّجْمَعَ عِظَامَهُۥ ۝٣ بَلَىٰ قَٰدِرِينَ عَلَىٰٓ ا͏ٔ͏َن نُّسَوِّيَ بَنَانَهُۥ ۝٤ بَلْ",
      "يُرِيدُ ٱلْإ͏ِنسَٰنُ لِيَفْجُرَ ا͏ٔ͏َمَامَهُۥ \u06dd٥ يَسْـٔ͏َلُ ا͏ٔ͏َيَّانَ يَوْمُ ٱلْقِيَٰمَةِ \u06dd٦ فَإ͏ِذَا بَرِقَ ٱلْبَصَرُ",
      "۝٧ وَخَسَفَ ٱلْقَمَرُ ۝٨ وَجُمِعَ ٱلشَّمْسُ وَٱلْقَمَرُ ۝٩ يَقُولُ ٱلْإ͏ِنسَٰنُ يَوْمَي͏ٔ͏ِذٍ",
      "ا͏ٔ͏َيْنَ ٱلْمَفَرُّ ۝١٠ كَلَّا لَا وَزَرَ ۝١١ إ͏ِلَىٰ رَبِّكَ يَوْمَي͏ٔ͏ِذٍ ٱلْمُسْتَقَرُّ ۝١٢ يُنَبَّو͏ٔ͏ُا۟ ٱلْإ͏ِنسَٰنُ",
      "يَوْمَي͏ٔ͏ِذِۭ بِمَا قَدَّمَ وَا͏ٔ͏َخَّرَ \u06dd١٣ بَلِ ٱلْإ͏ِنسَٰنُ عَلَىٰ نَفْسِهِۦ بَصِيرَةࣱ \u06dd١٤ وَلَوْ ا͏ٔ͏َلْقَىٰ",
      "مَعَاذِيرَهُۥ ۝١٥ لَا تُحَرِّكْ بِهِۦ لِسَانَكَ لِتَعْجَلَ بِهِۦٓ ۝١٦ إ͏ِنَّ عَلَيْنَا جَمْعَهُۥ",
      "وَقُرْءَانَهُۥ ۝١٧ فَإ͏ِذَا قَرَا͏ٔ͏ْنَٰهُ فَٱتَّبِعْ قُرْءَانَهُۥ ۝١٨ ثُمَّ إ͏ِنَّ عَلَيْنَا بَيَانَهُۥ ۝١٩"};
  const JustOption options{JustType::DeclPolicy, JustStyle::AdaptiveMargins, ShrinkType::None};
  const auto output = layout.justifyPage(unit, width, width, text, LineJustification::Distribute, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  require(output.size() == 15 && output[0].desiredLineWidth == width + 2 * decrease && output[0].xstartposition == -decrease, "Full page-577 GUI preview must decrease the nominal margins by the configured allowance");
  require(output[5].type == LineType::Sura && output[6].type == LineType::Bism, "GUI preview must classify Sura and Basmala before adaptive measurement");
  require(output[5].desiredLineWidth == 0 && output[6].desiredLineWidth == 0, "Preview headings must use natural centered treatment");
  std::vector<TextString> decoded;
  auto* buffer = hb_buffer_create();
  for (const auto& line : text) {
    hb_buffer_clear_contents(buffer);
    hb_buffer_add_utf8(buffer, line.data(), static_cast<int>(line.size()), 0, static_cast<int>(line.size()));
    unsigned count = 0;
    const auto* info = hb_buffer_get_glyph_infos(buffer, &count);
    TextString value;
    for (unsigned i = 0; i < count; ++i) value += static_cast<char16_t>(info[i].codepoint);
    decoded.push_back(std::move(value));
  }
  hb_buffer_destroy(buffer);
  const auto corpus = layout.justifyPage(unit, width, mushafLineInputs(decoded, 577, width, "qpc_v1_layout"), true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  for (std::size_t i = 0; i < output.size(); ++i)
    require(output[i].desiredLineWidth == corpus[i].desiredLineWidth && output[i].xstartposition == corpus[i].xstartposition && output[i].currentLineWidth == corpus[i].currentLineWidth && output[i].xscale == corpus[i].xscale, "GUI and corpus page-577 geometry differs at line " + std::to_string(i + 1));
  std::cout << "Page 577: GUI and corpus targets = " << output[0].desiredLineWidth / unit << "; margins = " << 600 - decrease / unit << "; all 15 line geometries match\n";
  const JustOption legacy{JustType::DeclPolicy, JustStyle::FontSizeXScale, ShrinkType::None};
  const auto previous = layout.justifyPage(unit, width, width, text, LineJustification::Distribute, false, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, legacy, "qpc_v1_layout");
  require(previous[5].type == LineType::Line && previous[5].desiredLineWidth == width, "Legacy preview input semantics must remain unchanged");
  layout.setPageLayout(saved);
}

void checkAdaptiveLastPage(OtLayout& layout) {
  using namespace digitalkhatt;
  const auto saved = layout.pageLayout();
  auto geometry = saved;
  geometry.pageWidth = 17600;
  geometry.leftMargin = geometry.rightMargin = 600;
  layout.setPageLayout(geometry);
  const int unit = 1 << OtLayout::SCALEBY;
  const int width = geometry.textWidth() * unit;
  const auto& sizing = layout.compiledJustificationCatalog->pagePolicy->sizing;
  const auto rule = std::find_if(sizing.begin(), sizing.end(), [](const auto& value) { return value.style == JustStyle::AdaptiveMargins; });
  require(rule != sizing.end() && rule->relativeMargins, "OldMadina must declare relative margin adjustments");
  const int increase = static_cast<int>(std::floor(rule->margins->second * unit));
  // qpc_v1_layout page 604, including its three intentionally short endings.
  std::vector<TextString> text{
      u"سُورَةُ الإِخْلَاصِ",
      u"بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ",
      u"قُلْ هُوَ ٱللَّهُ أَحَدٌ ۝١ ٱللَّهُ ٱلصَّمَدُ ۝٢ لَمْ يَلِدْ",
      u"وَلَمْ يُولَدْ ۝٣ وَلَمْ يَكُن لَّهُۥ كُفُوًا أَحَدُۢ ۝٤",
      u"سُورَةُ الفَلَقِ",
      u"بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ",
      u"قُلْ أَعُوذُ بِرَبِّ ٱلْفَلَقِ ۝١ مِن شَرِّ مَا خَلَقَ ۝٢ وَمِن",
      u"شَرِّ غَاسِقٍ إِذَا وَقَبَ ۝٣ وَمِن شَرِّ ٱلنَّفَّٰثَٰتِ فِي",
      u"ٱلْعُقَدِ ۝٤ وَمِن شَرِّ حَاسِدٍ إِذَا حَسَدَ ۝٥",
      u"سُورَةُ النَّاسِ",
      u"بِسْمِ ٱللَّهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ",
      u"قُلْ أَعُوذُ بِرَبِّ ٱلنَّاسِ ۝١ مَلِكِ ٱلنَّاسِ ۝٢ إِلَٰهِ",
      u"ٱلنَّاسِ ۝٣ مِن شَرِّ ٱلْوَسْوَاسِ ٱلْخَنَّاسِ ۝٤ ٱلَّذِي",
      u"يُوَسْوِسُ فِي صُدُورِ ٱلنَّاسِ ۝٥",
      u"مِنَ ٱلْجِنَّةِ وَٱلنَّاسِ ۝٦"};
  std::vector<std::string> strings;
  for (auto& line : text) {
    normalizeMushafWord(line, "dk_v1");
    // This Arabic fixture contains BMP characters only.
    std::string encoded;
    for (char16_t ch : line) {
      if (ch < 0x80) encoded += char(ch);
      else if (ch < 0x800) { encoded += char(0xc0 | (ch >> 6)); encoded += char(0x80 | (ch & 0x3f)); }
      else { encoded += char(0xe0 | (ch >> 12)); encoded += char(0x80 | ((ch >> 6) & 0x3f)); encoded += char(0x80 | (ch & 0x3f)); }
    }
    strings.push_back(std::move(encoded));
  }
  const JustOption options{JustType::DeclPolicy, JustStyle::AdaptiveMargins, ShrinkType::None};
  const auto preview = layout.justifyPage(unit, width, width, strings, LineJustification::Distribute, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout", 604);
  const auto input = mushafLineInputs(text, 604, width, "qpc_v1_layout");
  const auto corpus = layout.justifyPage(unit, width, input, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout");
  require(preview.size() == 15 && preview.size() == corpus.size(), "Both page-604 entry points must retain all 15 lines");
  require(preview[2].desiredLineWidth == width - 2 * increase && preview[2].xstartposition == increase, "Page 604 GUI preview must increase the nominal margins by the configured allowance");
  for (std::size_t i = 0; i < preview.size(); ++i) {
    const auto& a = preview[i];
    const auto& b = corpus[i];
    require(a.type == b.type && a.desiredLineWidth == b.desiredLineWidth && a.currentLineWidth == b.currentLineWidth && a.xstartposition == b.xstartposition && a.fontSize == b.fontSize && a.xscale == b.xscale, "GUI and corpus page-604 geometry differs at line " + std::to_string(i + 1));
    require(a.glyphs.size() == b.glyphs.size(), "GUI and corpus page-604 glyph counts differ");
    for (std::size_t j = 0; j < a.glyphs.size(); ++j) {
      const auto& x = a.glyphs[j];
      const auto& y = b.glyphs[j];
      require(x.codepoint == y.codepoint && x.parameters == y.parameters && x.x_advance == y.x_advance && x.y_advance == y.y_advance && x.x_offset == y.x_offset && x.y_offset == y.y_offset, "GUI and corpus page-604 glyph shaping differs");
    }
  }
  require(preview[8].desiredLineWidth < preview[2].desiredLineWidth && preview[13].desiredLineWidth < preview[2].desiredLineWidth && preview[14].desiredLineWidth < preview[2].desiredLineWidth, "Short page-604 endings must not become full-width lines");
  std::cout << "Page 604: GUI and corpus targets = " << preview[2].desiredLineWidth / unit << "; margins = " << 600 + increase / unit << "; all 15 lines match\n";
  layout.setPageLayout(saved);
}

void checkKafNoonExclusion(OtLayout& layout) {
  using namespace digitalkhatt::justify;
  const auto& catalog = *layout.compiledJustificationCatalog;
  const DeclPolicyJustifier engine(catalog);
  const auto input = [&](std::string_view name, char16_t character, int base, bool last) {
    return FixedSlotGlyphInput{.facts = glyphFacts({.glyphName = name, .sourceCharacter = character, .firstInSubword = base == 0, .lastInSubword = last}, catalog.facts), .wordIndex = 0, .subwordIndex = 0, .baseIndex = base, .indexInLine = base};
  };
  const std::vector<FixedSlotGlyphInput> noon{input("noon.fina", u'ن', 1, true)};
  const std::vector<FixedSlotGlyphInput> kaf{input("kaf.medi.ii", u'ك', 0, false), input("noon.fina", u'ن', 1, true)};
  const std::vector<FixedSlotGlyphInput> kafYehNoon{input("kaf.init.ii", u'ك', 0, false), input("behshape.medi", u'ي', 1, false), input("noon.fina", u'ن', 2, true)};
  const std::vector<FixedSlotGlyphInput> beh{input("behshape.fina.expa", u'ب', 0, true)};
  const auto ruleId = [&](std::string_view name) {
    const auto rule = std::find_if(catalog.rules.begin(), catalog.rules.end(), [&](const auto& value) { return value.name == name; });
    require(rule != catalog.rules.end(), "Missing Kaf/Noon opportunity " + std::string(name));
    return rule->id;
  };
  const auto count = [&](std::string_view selectionName, std::string_view ruleName, const auto& glyphs, const DeclPolicyExecutionState& state) {
    const auto selection = std::find_if(catalog.selections.begin(), catalog.selections.end(), [&](const auto& value) { return value.name == selectionName; });
    require(selection != catalog.selections.end(), "Missing Kaf/Noon selection");
    const std::array phases{PolicyPhase{.selection = static_cast<JustificationSelectionId>(selection - catalog.selections.begin()), .levels = 1, .allocator = PolicyPhase::Allocator::CandidatePool}};
    const auto wanted = ruleId(ruleName);
    int found = 0;
    engine.collectStageCandidates(2, glyphs, phases, state, [&](const auto& site, auto, const auto&) { found += site.rule == wanted; });
    return found;
  };
  for (const auto& [selection, rule, blockedBy, inputs] : std::vector<std::tuple<std::string, std::string, std::string, std::vector<FixedSlotGlyphInput>>>{
           {"CandidatePreferred", "PreferredNoon", "KafBody", noon},
           {"CandidatePreferred", "PreferredKaf", "TerminalNoon", kaf},
           {"CandidatePreferred", "PreferredKafBeforeNoon", "TerminalNoon", kaf},
           {"CandidateRemainingKaf", "CandidateKaf", "TerminalNoon", kaf}}) {
    DeclPolicyExecutionState state;
    state.recordsByWord.resize(2);
    require(count(selection, rule, inputs, state) == 1, "Unblocked Kaf/Noon opportunity must remain available");
    const int recordedBase = blockedBy == "KafBody" ? 0 : 1;
    state.recordsByWord[0][blockedBy] = {0, recordedBase};
    require(count(selection, rule, inputs, state) == 0, "Adjacent Kaf and terminal Noon must exclude each other, including continuation");
    state.recordsByWord[0][blockedBy] = {1, 0};
    require(count(selection, rule, inputs, state) == 1, "A record in another subword must not block Kaf/Noon");
    state.recordsByWord[0].clear();
    state.recordsByWord[1][blockedBy] = {0, 0};
    require(count(selection, rule, inputs, state) == 1, "A record in another word must not block Kaf/Noon");
    if (rule != "PreferredKafBeforeNoon") {
      state.recordsByWord[0][blockedBy] = {0, blockedBy == "KafBody" ? 0 : 2};
      require(count(selection, rule, kafYehNoon, state) == 1, "An intervening Yeh must allow Kaf and expanded Noon in the same subword");
    }
  }
  DeclPolicyExecutionState state;
  state.recordsByWord.resize(2);
  state.recordsByWord[0]["KafBody"] = {0, 0};
  require(count("CandidatePreferred", "PreferredAlternateGroup1", beh, state) == 1, "Other group-one terminal alternates must remain allowed beside Kaf");
  require(count("CandidatePreferred", "PreferredAlternateGroup1", noon, {}) == 0, "Noon must not bypass its exclusion through the generic terminal rule");

  const auto selection = std::find_if(catalog.selections.begin(), catalog.selections.end(), [](const auto& value) { return value.name == "CandidatePreferred"; });
  const auto selectionIndex = static_cast<JustificationSelectionId>(selection - catalog.selections.begin());
  std::array<FixedSlotGlyphInput, 3> terminals{noon.front(), beh.front(), noon.front()};
  for (int i = 0; i < 3; ++i) terminals[i].wordIndex = terminals[i].indexInLine = i;
  const auto weights = [&](const auto& source, int phaseCount) {
    std::vector<PolicyPhase> phases(phaseCount, PolicyPhase{.selection = selectionIndex, .levels = 1, .allocator = PolicyPhase::Allocator::CandidatePool});
    std::vector<double> found;
    DeclPolicyJustifier(source).collectStageCandidates(3, terminals, phases, {}, [&](const auto&, auto, const auto& score) { found.push_back(score.total); });
    return found;
  };
  const std::vector<double> expected{6, 6 * 0.85, 6 * std::pow(0.85, 2)};
  require(weights(catalog, 1) == expected, "Splitting Noon must preserve the original shared terminal occurrence decay");
  auto repeated = expected;
  repeated.insert(repeated.end(), expected.begin(), expected.end());
  require(weights(catalog, 2) == repeated, "A shared decay group must reset for each phase");
  auto independent = catalog;
  for (auto& choice : independent.selections.at(selectionIndex).rules) choice.decayGroup.clear();
  require(weights(independent, 1) == std::vector<double>{6, 6, 6 * 0.85}, "Choices without decay_group must retain independent per-rule counters");

  auto& mutableCatalog = *layout.compiledJustificationCatalog;
  auto probe = mutableCatalog.stretchPolicies.at(mutableCatalog.stretchPolicyIndex("staged_pool_continue"));
  const auto preferred = std::find_if(probe.steps.begin(), probe.steps.end(), [](const auto& step) { return step.stage == "PreferredStretch"; });
  require(preferred != probe.steps.end(), "Missing Kaf/Noon preferred stage");
  probe.steps = {*preferred};
  probe.name = "test.kaf_noon_preference";
  const int policy = static_cast<int>(mutableCatalog.stretchPolicies.size());
  mutableCatalog.stretchPolicies.push_back(std::move(probe));
  const auto shape = [&](const std::u16string& text) {
    const int width = 10000 << OtLayout::SCALEBY;
    const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
    return layout.justifyPage(scale, width, {{text, width, LineJustification::Distribute, LineType::Line}}, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, JustOption{JustType::DeclPolicy, JustStyle::None, ShrinkType::None, policy}, "qpc_v1_layout").at(0);
  };
  const auto expanded = [&](const auto& line, bool isKaf) {
    return std::any_of(line.glyphs.begin(), line.glyphs.end(), [&](const auto& glyph) {
      const auto& name = layout.glyphNamePerCode.at(glyph.codepoint);
      return isKaf ? ((name == "kaf.init.ii" || name == "kaf.medi.ii") && glyph.parameters.third > 0) : (name.starts_with("noon.") && name.find(".expa") != std::string::npos && glyph.parameters.lefttatweel > 0);
    });
  };
  const auto preferredStep = mutableCatalog.stretchPolicies.back().steps.front();
  for (const bool continuing : {false, true}) {
    mutableCatalog.stretchPolicies.back().steps = {preferredStep};
    if (continuing) {
      auto continuation = preferredStep;
      continuation.continuation = {StageContinuation::Mode::Maximum};
      mutableCatalog.stretchPolicies.back().steps.push_back(continuation);
    }
    for (const auto text : {u"كن", u"يَكُن"}) {
      const auto line = shape(text);
      require(expanded(line, false) && !expanded(line, true), "A fitting expanded Noon must outrank adjacent Kaf, including stage continuation and intervening marks");
    }
    const auto separated = shape(u"كِين");
    require(expanded(separated, false) && expanded(separated, true), "Kaf-Yeh-Noon must permit both bodies to expand and continue");
  }
  const auto noonBinding = std::find_if(mutableCatalog.actions.begin(), mutableCatalog.actions.end(), [&](const auto& binding) { return binding.rule == ruleId("PreferredNoon"); });
  auto& noonAction = mutableCatalog.actionDefinitions.at(noonBinding->definition);
  const auto savedEffects = noonAction.effects;
  noonAction.effects.insert(noonAction.effects.begin(), JustEffect{.kind = JustEffectKind::Forbid, .condition = {{.op = JustExprOp::Literal, .literal = 1}}});
  const auto fallback = shape(u"كن");
  require(expanded(fallback, true) && !expanded(fallback, false), "Alternate Kaf must remain available when the preferred Noon opportunity is unavailable");
  noonAction.effects = savedEffects;
  mutableCatalog.stretchPolicies.pop_back();
}

void checkPreferredContinuation(OtLayout& layout) {
  using namespace digitalkhatt;
  using namespace digitalkhatt::justify;
  auto& catalog = *layout.compiledJustificationCatalog;
  require(catalog.stretchPolicyIndex("staged_pool") < 0 && catalog.stretchPolicyIndex("staged_pool_full_shape") < 0, "Obsolete staged comparison policies must not remain selectable");
  auto probe = catalog.stretchPolicies.at(catalog.stretchPolicyIndex("staged_pool_continue"));
  const auto preferred = std::find_if(probe.steps.begin(), probe.steps.end(), [](const auto& step) { return step.stage == "PreferredStretch"; });
  require(preferred != probe.steps.end(), "Missing reusable preferred stage");
  auto step = *preferred;
  step.continuation = {StageContinuation::Mode::By, 1};
  probe.name = "test.continuation";
  probe.steps = {step};
  const int index = static_cast<int>(catalog.stretchPolicies.size());
  catalog.stretchPolicies.push_back(std::move(probe));
  const int width = 10000 << OtLayout::SCALEBY;
  const double scale = (1 << OtLayout::SCALEBY) * OtLayout::EMSCALE;
  const JustOption options{JustType::DeclPolicy, JustStyle::None, ShrinkType::Standard, index};
  const auto run = [&](std::u16string text) {
    return layout.justifyPage(scale, width, {{text, width, LineJustification::Distribute, LineType::Line}}, true, false, HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS, options, "qpc_v1_layout").at(0);
  };
  const auto find = [&](const auto& line, std::string_view name) -> const GlyphLayoutInfo& {
    const auto glyph = std::find_if(line.glyphs.begin(), line.glyphs.end(), [&](const auto& value) { return layout.glyphNamePerCode.at(value.codepoint) == name; });
    require(glyph != line.glyphs.end(), "Missing continuation proof glyph " + std::string(name));
    return *glyph;
  };
  for (const auto& [text, name, axis, maximum] : std::vector<std::tuple<std::u16string, std::string, GlyphAxisId, double>>{{u"ن", "noon.isol.expa", LeftTatweelAxis, 9}, {u"بل", "behshape.init", LeftTatweelAxis, 5}, {u"كب", "kaf.init.ii", ThirdAxis, 4}}) {
    catalog.stretchPolicies.back().steps = {step};
    const auto first = run(text);
    require(find(first, name).parameters.value(axis) == 1, "First continuation must include activation, not add another unit after it");
    catalog.stretchPolicies.back().steps = {step, step};
    bool continued = false;
    layout.setJustificationTraceCallback([&](const auto& trace) { continued |= trace.decision == "applied" && trace.reason == "continued"; });
    const auto second = run(text);
    layout.setJustificationTraceCallback({});
    require(continued && find(second, name).parameters.value(axis) == 2, "Repeating the same preferred stage must continue its accepted site despite its own record");
    require(find(first, name).codepoint == find(second, name).codepoint, "Continuation must retain the prepared glyph");
    if (text == u"بل") require(find(second, "lam.fina").parameters.righttatweel == 1, "Ascendant incoming stretch must remain half the outgoing stretch");
    catalog.stretchPolicies.back().steps.assign(12, step);
    const auto saturated = run(text);
    require(find(saturated, name).parameters.value(axis) == maximum, "Repeated relative continuation must stop at the authored full maximum");

    auto ordinary = step;
    ordinary.continuation = {};
    catalog.stretchPolicies.back().steps = {ordinary};
    const auto initial = find(run(text), name).parameters.value(axis);
    catalog.stretchPolicies.back().steps = {ordinary, step};
    require(find(run(text), name).parameters.value(axis) == std::min(maximum, initial + 1), "Ordinary allocation must retain its accepted site for relative continuation");
    auto absolute = step;
    absolute.continuation = {StageContinuation::Mode::To, 3.5};
    catalog.stretchPolicies.back().steps = {ordinary, absolute};
    require(find(run(text), name).parameters.value(axis) == std::max(initial, std::min(maximum, 3.5)), "Absolute continuation must target the supplied value rather than add it");
    absolute.continuation.limit = 0;
    catalog.stretchPolicies.back().steps = {ordinary, absolute};
    require(find(run(text), name).parameters.value(axis) == initial, "An absolute limit below the accepted value must leave it unchanged");
    auto full = step;
    full.continuation = {StageContinuation::Mode::Maximum};
    catalog.stretchPolicies.back().steps = {ordinary, full};
    require(find(run(text), name).parameters.value(axis) == maximum, "Bare continuation must use the action's declared maximum");
  }
  // Page 51, line 15: baseline Beh-Sad spacing changes Sad's incoming axis,
  // while the accepted Sad-Yeh opportunity owns its outgoing axis only.
  const auto shortSelection = std::find_if(catalog.selections.begin(), catalog.selections.end(), [](const auto& selection) { return selection.name == "InitialShortJoins"; });
  require(shortSelection != catalog.selections.end(), "Missing short-joining selection");
  const LinePolicyStep baseline{.operation = LineStepOp::Stage, .stage = "test.baseline", .phases = {{.selection = static_cast<JustificationSelectionId>(shortSelection - catalog.selections.begin()), .levels = 1, .allocator = PolicyPhase::Allocator::BaselinePool}}};
  auto ordinary = step;
  ordinary.continuation = {};
  auto full = step;
  full.continuation = {StageContinuation::Mode::Maximum};
  catalog.stretchPolicies.back().steps = {ordinary, baseline};
  const auto withBaseline = run(u"بَصِيرُۢ");
  require(find(withBaseline, "sad.medi").parameters.lefttatweel == 1.75 && find(withBaseline, "sad.medi").parameters.righttatweel == 0.5, "Proof must combine preferred Sad-Yeh stretching with incoming baseline spacing");
  catalog.stretchPolicies.back().steps = {ordinary, baseline, full};
  bool resumedAfterBaseline = false;
  layout.setJustificationTraceCallback([&](const auto& trace) { resumedAfterBaseline |= trace.rule == "PreferredBehKashida" && trace.decision == "applied" && trace.reason == "continued"; });
  const auto afterBaseline = run(u"بَصِيرُۢ");
  layout.setJustificationTraceCallback({});
  require(resumedAfterBaseline && find(afterBaseline, "sad.medi").parameters.lefttatweel == 4 && find(afterBaseline, "behshape.medi.beforereh").parameters.righttatweel == 4, "Changing an unrelated incoming axis must not block Sad-Yeh continuation");
  require(find(afterBaseline, "sad.medi").parameters.righttatweel == 0.5 && find(afterBaseline, "behshape.init").parameters.lefttatweel == 0.5, "Continuation must preserve the adjacent connection's baseline spacing");
  // An intervening writer takes ownership: the cached range must not resume
  // simply because the final parameter is still positive.
  const auto parameterSelection = std::find_if(catalog.selections.begin(), catalog.selections.end(), [](const auto& selection) { return selection.name == "ParameterAlternateGroup1"; });
  require(parameterSelection != catalog.selections.end(), "Missing intervening fixed-step selection");
  const LinePolicyStep intervening{.operation = LineStepOp::Stage, .stage = "test.intervening", .phases = {{.selection = static_cast<JustificationSelectionId>(parameterSelection - catalog.selections.begin()), .levels = 1}}};
  catalog.stretchPolicies.back().steps = {step, intervening, step};
  require(find(run(u"ن"), "noon.isol.expa").parameters.lefttatweel == 2, "An intervening parameter change must invalidate continuation ownership");
  catalog.stretchPolicies.pop_back();
}

void checkSerialization(OtLayout& layout) {
  layout.setExtended(false);  // Standard OTF reads parameters from materialized glyph IDs.
  GlyphParameters parameters;
  parameters.lefttatweel = 3;
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
  require(checked == 18, "Expected six dot styles and six split Shadda/other-parent styles");
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
    checkRelativeMarginSyntax();
    checkContinuationSyntax();
    MPFont mpFont;
    initializeFont(mpFont, fs::absolute(argv[1]), fs::absolute(argv[2]));
    OtLayout layout(&mpFont, true, false);
    layout.useNormAxisValues = false;
    layout.loadLookupFile((fs::absolute(argv[1]).parent_path() / "features.fea").string());
    checkOpportunitySyntax(layout);
    auto* font = layout.createFont(1, false);
    FontProvider provider(layout);
    checkShrinkAlefAboveDal(layout, provider, font);
    for (const auto& [root, style] : {std::pair{"noon.fina.expa", 1}, {"kaf.fina.expa", 2}, {"kaf.init.ii", 3}, {"behshape.isol", 0}}) {
      for (const auto parent : {Parent::Base, Parent::Dot, Parent::Shadda}) checkDispatch(layout, provider, font, root, style, parent, 1);
      for (double left : {0.0625, oldmadina::FathaShaddaCenterLimit, oldmadina::FathaShaddaCenterLimit + 0.0625, 5.0}) checkDispatch(layout, provider, font, root, style, Parent::Shadda, left);
    }
    for (const auto* root : {"behshape.isol.expa", "behshape.fina.expa", "alefmaksura.isol.expa", "yehshape.isol.expa", "yehshape.fina.ii.expa", "yehshape.fina.afterbeh.expa", "yehshape.fina.expa"}) {
      const auto style = std::string_view(root).starts_with("behshape.") ? oldmadina::FathaAnchorStyle::ExpandedBeh : oldmadina::FathaAnchorStyle::Centered;
      for (const auto parent : {Parent::Base, Parent::Dot, Parent::Shadda}) checkDispatch(layout, provider, font, root, static_cast<int>(style), parent, 3);
    }
    for (double left : {0.0, -1.0}) {
      checkDispatch(layout, provider, font, "noon.fina.expa", 1, Parent::Dot, left);
      checkDispatch(layout, provider, font, "noon.fina.expa", 1, Parent::Dot, left, false, true);
    }
    checkDispatch(layout, provider, font, "noon.fina.expa", 1, Parent::Dot, 1, true);
    checkAutomaticAttachment(layout, provider, font);
    checkIqlabModeration(layout, provider, font);
    checkContextualFatha(layout, provider, font);
    checkCompensatedJoinedConnection(layout, provider, font);
    checkAddedMarkStretching(layout, provider, font);
    checkShaddaCenterTransition(layout);
    checkExpandedShaddaCentering(layout, provider, font);
    checkLocalAnchorsAndExpandedCentering(layout);
    checkSharedGlyphTopAnchor(layout);
    checkFontOwnedGroupAnchors(layout);
    hb_font_destroy(font);
    checkLamMeemStretching(layout);
    checkHehMeemStretching(layout);
    checkFinalAscendantPrecedence(layout);
    checkLastResortDecomposition(layout);
    checkLateBaselineSpacing(layout);
    checkPreferredContinuation(layout);
    checkKafNoonExclusion(layout);
    checkAdaptiveMargins(layout);
    checkAdaptivePreview(layout);
    checkAdaptiveLastPage(layout);
    checkSerialization(layout);
    checkIqlabGlyphAnchors(layout);
    std::cout << "Attachment/native/GSUB regressions, local no-lift anchors, expanded Beh/Yeh centring, baseline metadata, Shadda threshold transitions, expanded Noon/Beh Shadda centring and 18 serialized anchor subtables passed\n";
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
