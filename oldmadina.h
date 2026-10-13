#pragma once
#include <map>
#include <optional>
#include <string>
#include <tuple>

#include "GlyphVis.h"
#include "Lookup.h"
#include "Subtable.h"
#include "automedina.h"

class OldMadina : public Automedina {
 public:
  OldMadina(OtLayout* layout, MPFont* font, bool extended);
  Lookup* getLookup(std::string lookupName) override;
  CalcAnchor getanchorCalcFunctions(std::string functionName, Subtable* subtable) override;
  PairAdjustFunc getPairAdjustFunction(std::string functionName, Subtable* subtable) override;

  void generateSubstEquivGlyphs() override;
  bool preserveMarkGposHorizontal(hb_codepoint_t mark, const GlyphParameters& parameters) const override;
  std::optional<double> markBaselineClearance(hb_codepoint_t mark, const GlyphParameters& parameters) const override;
  std::optional<Point> getAnchor(const GlyphVis& glyph, const MarkBaseSubtable& subtable, std::string_view className, const GlyphParameters& parameters) const override;
  void prepareAnchorResolution() override;
  ~OldMadina() {}

 private:
  // Only membership is cached, never glyph identities or anchor coordinates.
  using AnchorClassKey = std::tuple<const MarkBaseSubtable*, std::string, std::string>;
  mutable std::map<AnchorClassKey, std::optional<std::size_t>> anchorClassCache_;
  std::optional<std::size_t> matchingAnchorClassSize(const MarkBaseSubtable& subtable, std::string_view className, const std::string& anchorName) const;
  Lookup* defaultmarkposition();
  Lookup* defaultwaqfmarktobase();
  Lookup* forsmalllalef();
  Lookup* forsmallhighwaw();
  Lookup* forhamza();
  Lookup* forheh();
  Lookup* forwaw();
  Lookup* cursivejoin();
  Lookup* pointmarks();
  Lookup* defaultwaqfmarkabovemarkprecise();
  Lookup* defaultdotmarks();
  Lookup* defaultmarkdotmarks();
  Lookup* defaultmkmk();
  Lookup* stretchedFathaMkmk();
  void addStretchedFathaBaseSubtables(Lookup* lookup);
  Lookup* ayanumbers();
  Lookup* ayanumberskern();
  Lookup* rehwawcursivecpp();
  Lookup* tajweedcolorcpp();
  Lookup* glyphalternates();
  // Justification
  Lookup* shrinkstretchlt(float lt, std::string featureName);
  Lookup* shrinkstretchlt();
  void addEndOfAyas(std::string ayaName, bool isColored, int maxWidth);
  void generateGlyphs();
};
