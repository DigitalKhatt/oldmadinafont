#pragma once
#include <string>

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
  ~OldMadina() {}

 private:
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
