#include "oldmadina.h"

#include <algorithm>

#include "GlyphVis.h"
#include "Lookup.h"
#include "Subtable.h"
#include "defaultmarkpositions.h"
#include "font.hpp"
#include "metafont.h"
#include "qdebug.h"
#include "qregularexpression.h"
#include "qstring.h"

using namespace std;

class DefaultBaseOfWaqfToMark : public AnchorCalc {
 public:
  DefaultBaseOfWaqfToMark(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis* curr = &_y.glyphs[glyphName];
    curr = curr->getAlternate(parameters);

    int width = curr->width * 0.5;
    int height = curr->height + 30;

    width = width + adjust.x();
    height = height + adjust.y();

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};

class DefaultBaseOfWaqfToBase : public AnchorCalc {
 public:
  DefaultBaseOfWaqfToBase(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis* curr = &_y.glyphs[glyphName];
    curr = curr->getAlternate(parameters);

    int height = std::max((int)curr->height + 100, 900);
    int width = 0;  // curr.bbox.llx;

    width += adjust.x();
    height += adjust.y();

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};

class DefaultMarkOfWaqfToBase : public AnchorCalc {
 public:
  DefaultMarkOfWaqfToBase(Automedina& y, MarkBaseSubtable& subtable) : _y(y), _subtable(subtable) {}
  QPoint operator()(QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) override {
    GlyphVis* curr = &_y.glyphs[glyphName];
    curr = curr->getAlternate(parameters);

    int height = 0;
    int width = 0;
    // curr->width / 4;

    width += adjust.x();
    height += adjust.y();

    return QPoint(width, height);
  };

 private:
  Automedina& _y;
  MarkBaseSubtable& _subtable;
};

void OldMadina::generateSubstEquivGlyphs() {
  return;

  GlyphParameters parameters;

  for (auto& glyph : m_layout->expandableGlyphs) {
    auto glyphCode = m_layout->glyphCodePerName[glyph.first];
    auto valueLimits = glyph.second;

    if (valueLimits.maxLeft > 0) {
      for (double leftTatweel = 0.5; leftTatweel <= valueLimits.maxLeft; leftTatweel += 0.5) {
        parameters.lefttatweel = leftTatweel;
        parameters.righttatweel = 0.0;
        GlyphVis* newglyph = m_layout->getAlternate(glyphCode, parameters, true, true);
      }
    };

    if (valueLimits.maxRight > 0) {
      for (double righttatweel = 0.5; righttatweel <= valueLimits.maxRight; righttatweel += 0.5) {
        parameters.lefttatweel = 0.0;
        parameters.righttatweel = righttatweel;
        GlyphVis* newglyph = m_layout->getAlternate(glyphCode, parameters, true, true);
      }
    };

    parameters.lefttatweel = valueLimits.minLeft;
    parameters.righttatweel = valueLimits.minRight;

    if (parameters.lefttatweel != 0 || parameters.righttatweel != 0) {
      GlyphVis* newglyph = m_layout->getAlternate(glyphCode, parameters, true, true);
    }
  }
}

void OldMadina::generateGlyphs() {
  auto edgess = font->getEdges();

  glyphs.clear();

  for (auto edges : edgess) {
    auto name = QString(edges->charname);

    if (name != "alternatechar") {
      GlyphVis& glyph = *glyphs.insert(name, GlyphVis(m_layout, edges));

      if (edges->glyphtype != (int)GlyphType::GlyphTypeColored && edges->glyphtype != (int)GlyphType::GlyphTypeTemp) {
        m_layout->glyphNamePerCode[glyph.charcode] = QString::fromStdString(glyph.name);
        m_layout->glyphCodePerName[QString::fromStdString(glyph.name)] = glyph.charcode;
        if (glyph.unicode != -1) {
          m_layout->unicodeToGlyphCode.insert(glyph.unicode, glyph.charcode);
        }

        if (!classes["marks"].contains(glyph.name)) {
          classes["bases"].insert(glyph.name);
          m_layout->glyphGlobalClasses[glyph.charcode] = OtLayout::BaseGlyph;
        } else {
          m_layout->glyphGlobalClasses[glyph.charcode] = OtLayout::MarkGlyph;
        }

        for (int i = 0; i < edges->numAnchors; i++) {
          AnchorPoint anchor = edges->anchors[i];
          if (anchor.anchorName) {
            switch (anchor.type) {
              case 1:
                markAnchors[anchor.anchorName][glyph.charcode] = QPoint(anchor.x, anchor.y);
                break;
              case 2:
                entryAnchors[anchor.anchorName][glyph.charcode] = QPoint(anchor.x, anchor.y);
                break;
              case 3:
                exitAnchors[anchor.anchorName][glyph.charcode] = QPoint(anchor.x, anchor.y);
              case 4:
                entryAnchorsRTL[anchor.anchorName][glyph.charcode] = QPoint(anchor.x, anchor.y);
                break;
              case 5:
                exitAnchorsRTL[anchor.anchorName][glyph.charcode] = QPoint(anchor.x, anchor.y);
              default:
                break;
            }
          }
        }
      }
    }
  }

  auto addFake = [this](QString glyphName, std::uint16_t unicode, std::uint16_t codechar) {
    auto code = unicode;  // codechar; //layout.glyphNamePerCode.lastKey();
    GlyphVis& glyph = *glyphs.insert(glyphName, GlyphVis());
    glyph.name = glyphName.toStdString();
    glyph.charcode = code;

    m_layout->glyphNamePerCode[glyph.charcode] = QString::fromStdString(glyph.name);
    m_layout->glyphCodePerName[QString::fromStdString(glyph.name)] = glyph.charcode;
    m_layout->unicodeToGlyphCode.insert(unicode, glyph.charcode);
  };
  addFake("alef.maddahabove.isol", 0x0622, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("alef.hamzaabove.isol", 0x0623, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("waw.hamzaabove.isol", 0x0624, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("alef.hamzabelow.isol", 0x0625, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("alefmaksura.hamzaabove.isol", 0x0626, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("behshape.onedotdown.isol", 0x0628, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("heh.twodotsup.isol", 0x0629, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("behshape.twodotsup.isol", 0x062A, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("behshape.three_dots.isol", 0x062B, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("hah.onedotdown.isol", 0x062C, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("hah.onedotup.isol", 0x062E, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("dal.onedotup.isol", 0x0630, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("reh.onedotup.isol", 0x0632, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("seen.three_dots.isol", 0x0634, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("sad.onedotup.isol", 0x0636, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("tah.onedotup.isol", 0x0638, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("ain.onedotup.isol", 0x063A, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("alef.wasla.isol", 0x0671, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("noon.onedotup.isol", 0x0646, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("feh.onedotup.isol", 0x0641, m_layout->glyphNamePerCode.lastKey() + 1);
  addFake("qaf.twodotsup.isol", 0x0642, m_layout->glyphNamePerCode.lastKey() + 1);

  m_layout->glyphs = glyphs;
}

void OldMadina::addEndOfAyas(QString ayaName, bool isColored, int maxWidth) {
  for (int ayaNumber = 1; ayaNumber <= 286; ayaNumber++) {
    QString setcolored;
    if (isColored) {
      setcolored = QString("coloredglyph:=\"%1.colored%2\"").arg(ayaName).arg(ayaNumber);
    }
    QString data = QString("beginchar(%1%2,-1,-1,2,-1);\n%%beginbody\ngenAyaNumber(%1, %2,%4);%3;endchar;").arg(ayaName).arg(ayaNumber).arg(setcolored).arg(maxWidth);
    m_layout->font->executeMetaPost(data);
    addedGlyphs[QString("%1%2").arg(ayaName).arg(ayaNumber).toStdString()] = data.toStdString();
    if (isColored) {
      data = QString("beginchar(%1.colored%2,-1,-1,5,-1);\n%%beginbody\ngenAyaNumber(%1.colored, %2,%3);endchar;").arg(ayaName).arg(ayaNumber).arg(maxWidth);
      m_layout->font->executeMetaPost(data);
      addedGlyphs[QString("%1.colored%2").arg(ayaName).arg(ayaNumber).toStdString()] = data.toStdString();
    }
  }
}

OldMadina::OldMadina(OtLayout* layout, Font* font, bool extended) : Automedina{layout, font, extended} {
  // m_metafont = layout->m_font;
  classes["marks"] = {
      "onedotup",
      "onedotdown",
      "twodotsup",
      "twodotsdown",
      "three_dots",
      "fathatanidgham",
      "kasratanidgham",
      "dammatanidgham",
      "fatha",
      "damma",
      "kasra",
      "shadda",
      "headkhah",
      "sukun",
      "dammatan",
      "maddahabove",
      "fathatan",
      "kasratan",
      "smallalef",
      "smallalef.replacement",
      "smallalef.joined",
      "meemiqlab",
      "smalllowmeem",
      "smallhighyeh",
      "smallhighwaw",
      "wasla",
      "hamzaabove",
      "hamzaabove.lamalef",
      "hamzaabove.small",
      "hamzaabove.joined",
      "hamzabelow",
      "smallhighroundedzero",
      "rectangularzero",
      "smallhighseen",
      "smalllowseen",
      "smallhighnoon",
      "waqf.meem",
      "waqf.lam",
      "waqf.qaf",
      "waqf.jeem",
      "waqf.sad",
      "waqf.smallhighthreedots",
      "roundedfilledhigh",
      "roundedfilledlow",
      "space.ii"};

  classes["topmarks"] = {
      //"onedotup",
      //"twodotsup",
      //"three_dots",
      "fathatanidgham",
      "dammatanidgham",
      "fatha",
      "damma",
      "shadda",
      "headkhah",
      "sukun",
      "dammatan",
      "maddahabove",
      "fathatan",
      "smallalef",
      "smallalef.replacement",
      "smallalef.joined",
      "meemiqlab",
      "smallhighyeh",
      "smallhighwaw",
      "wasla",
      "hamzaabove",
      "hamzaabove.joined",
      //"hamzaabove.lamalef",
      "smallhighroundedzero",
      "rectangularzero",
      "smallhighseen",
      "smallhighnoon",
      "roundedfilledhigh",
      "hamzaabove.joined",
  };

  classes["lowmarks"] = {
      //"onedotdown",
      //"twodotsdown",
      "kasratanidgham",
      "kasra",
      "kasratan",
      "hamzabelow",
      "smalllowseen",
      "roundedfilledlow",
      "smalllowmeem"};

  classes["kasras"] = {
      "kasratanidgham",
      "kasra",
      "kasratan"};

  classes["waqfmarks"] = {
      "waqf.meem",
      "waqf.lam",
      "waqf.qaf",
      "waqf.jeem",
      "waqf.sad",
      "waqf.smallhighthreedots"};

  classes["dotmarks"] = {
      "onedotup",
      "onedotdown",
      "twodotsup",
      "twodotsdown",
      "three_dots"};

  classes["topdotmarks"] = {
      "onedotup",
      "twodotsup",
      "three_dots"};

  classes["downdotmarks"] = {
      "onedotdown",
      "twodotsdown"};

  classes["digits"] = {
      "zeroindic",
      "oneindic",
      "twoindic",
      "threeindic",
      "fourindic",
      "fiveindic",
      "sixindic",
      "sevenindic",
      "eightindic",
      "nineindic"};

  initchar = {
      "behshape",
      //"teh" ,
      //"tehmarbuta" ,
      //"theh" ,
      //"jeem" ,
      "hah",
      //"khah" ,
      //"dal" ,
      //"thal" ,
      //"reh" ,
      //"zain" ,
      "seen",
      //"sheen" ,
      "sad",
      //"dad" ,
      "tah",
      //"zah" ,
      "ain",
      //"ghain" ,
      "fehshape",
      //"qaf" ,
      "kaf",
      "lam",
      "meem",
      //"noon" ,
      "heh",
      //"waw" ,
      //"yeh" ,
      //"yehwithoutdots" ,
      //"alefmaksura"
  };

  medichar = {
      //"alef" ,
      "behshape",
      //"teh" ,
      //"tehmarbuta" ,
      //"theh" ,
      //"jeem" ,
      "hah",
      //"khah" ,
      //"dal" ,
      //"thal" ,
      //"reh" ,
      //"zain" ,
      "seen",
      //"sheen" ,
      "sad",
      //"dad" ,
      "tah",
      //"zah" ,
      "ain",
      //"ghain" ,
      "fehshape",
      //"qaf" ,
      "kaf",
      "lam",
      "meem",
      //"noon" ,
      "heh",
      //"waw" ,
      //"yeh" ,
      //"yehwithoutdots" ,
      //"alefmaksura"
  };

  auto useColoredAya = font->getBoolVariable("useColoredAya");

  addEndOfAyas("endofaya", useColoredAya, 630);

  generateGlyphs();

  // setAnchorCalcFunctions();

  layout->expandableGlyphs["alef.isol"] = {20, -2, 0, 0};
  layout->expandableGlyphs["alef.fina"] = {20, -2, 20, -0.4};

  layout->expandableGlyphs["behshape.isol"] = {3, -2, 0, 0};

  layout->expandableGlyphs["behshape.init.beforenoon"] = {20, -0.5, 0, 0};

  layout->expandableGlyphs["behshape.isol.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["behshape.fina.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["kaf.fina.expa"] = {20, -1, 20, -0.3};
  layout->expandableGlyphs["kaf.fina.afterlam.expa"] = {20, 0, 20, 0};
  layout->expandableGlyphs["noon.isol.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["noon.fina.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["noon.fina.expa.afterbeh"] = {20, 0, 0, 0};
  layout->expandableGlyphs["alefmaksura.isol.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["yehshape.isol.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["yehshape.fina.ii.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["yehshape.fina.afterbeh.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["yehshape.fina.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["sad.isol.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["sad.fina.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["seen.isol.expa"] = {20, 0, 0, 0};
  layout->expandableGlyphs["seen.fina.expa"] = {20, 0, 20, -0.4};
  layout->expandableGlyphs["feh.isol.expa"] = {20, -1, 0, 0};
  layout->expandableGlyphs["feh.isol"] = {2, -2, 0, 0};
  layout->expandableGlyphs["feh.fina.expa"] = {20, 0, 20, -0.4};
  layout->expandableGlyphs["qaf.isol.expa"] = {20, 0, 0, 0};

  layout->expandableGlyphs["lam.isol"] = {0, -0.5, 0, 0};

  layout->expandableGlyphs["behshape.init"] = {20, -1, 0, 0};
  layout->expandableGlyphs["behshape.init.beforereh"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["hah.init"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["seen.init"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["sad.init"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["tah.init"] = {20, 0, 0, 0};
  layout->expandableGlyphs["ain.init"] = {20, -0.7, 0, 0};
  layout->expandableGlyphs["fehshape.init"] = {20, -1, 0, 0};
  layout->expandableGlyphs["kaf.init"] = {20, -1.5, 0, 0};
  layout->expandableGlyphs["kaf.init.ii"] = {20, -1.5, 6, -1};
  layout->expandableGlyphs["kaf.init.iii"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["kaf.init.short"] = {20, -1.5, 0, 0};

  layout->expandableGlyphs["lam.init"] = {20, -1, 0, 0};
  layout->expandableGlyphs["meem.init"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["heh.init"] = {20, -0.5, 0, 0};

  layout->expandableGlyphs["heh.medi"] = {20, -0.3, 0, 0};
  layout->expandableGlyphs["heh.medi.beforeyeh"] = {0, 0, 20, -0.5};

  layout->expandableGlyphs["behshape.medi"] = {20, -0.5, 20, -0.5};
  layout->expandableGlyphs["behshape.medi.afterbeh"] = {20, -1, 0, 0};
  layout->expandableGlyphs["behshape.medi.afterlam"] = {20, -1, 0, 0};
  layout->expandableGlyphs["behshape.medi.beforeseen"] = {20, -0.3, 20, -0.3};
  layout->expandableGlyphs["behshape.medi.beforereh"] = {20, -0.3, 20, -0.3};
  layout->expandableGlyphs["behshape.medi.beforenoon"] = {20, -0.4, 20, -0.4};
  layout->expandableGlyphs["behshape.medi.beforeyeh"] = {0, 0, 20, -1};

  layout->expandableGlyphs["hah.medi"] = {20, -0.5, 20, 0};
  layout->expandableGlyphs["hah.medi.afterbeh"] = {20, -1, 0, 0};
  layout->expandableGlyphs["hah.medi.lam_hah"] = {20, -1, 0, 0};
  layout->expandableGlyphs["hah.medi.aftermeem"] = {20, -1, 0, 0};
  layout->expandableGlyphs["hah.medi.afterfeh"] = {20, -1, 0, 0};
  layout->expandableGlyphs["hah.medi.aftersad"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["hah.medi.ii"] = {0, 0, 20, -0.3};
  layout->expandableGlyphs["hah.medi.beforeyeh"] = {0, 0, 20, -0.5};
  layout->expandableGlyphs["heh.medi.afterbehinit"] = {20, 0, 0, 0};
  layout->expandableGlyphs["seen.medi"] = {20, -0.2, 20, -0.2};
  layout->expandableGlyphs["seen.medi.afterbeh"] = {20, -0.3, 20, -0.3};
  layout->expandableGlyphs["seen.medi.beforereh"] = {0, 0, 20, -0.5};
  layout->expandableGlyphs["seen.medi.beforeyeh"] = {0, 0, 20, -0.4};
  layout->expandableGlyphs["sad.medi"] = {20, -0.5, 20, -0.5};
  layout->expandableGlyphs["tah.medi"] = {20, -0.5, 20, -0.5};
  layout->expandableGlyphs["ain.medi"] = {20, -0.1, 20, -0.1};
  layout->expandableGlyphs["ain.medi.beforeyeh"] = {0, 0, 20, -0.3};
  layout->expandableGlyphs["fehshape.medi"] = {20, -0.5, 20, -0.7};
  layout->expandableGlyphs["fehshape.medi.beforeyeh"] = {0, 0, 20, -0.5};

  layout->expandableGlyphs["kaf.medi"] = {20, -1.2, 20, -1.5};
  layout->expandableGlyphs["kaf.medi.beforemeem"] = {0, 0, 20, 0};
  layout->expandableGlyphs["kaf.medi.beforeyeh"] = {0, 0, 20, -1};
  layout->expandableGlyphs["kaf.medi.beforelam"] = {0, 0, 20, -1};
  layout->expandableGlyphs["kaf.medi.ii"] = {20, -0.5, 20, -0.5};
  layout->expandableGlyphs["lam.medi"] = {20, -0.5, 20, -0.5};
  layout->expandableGlyphs["lam.medi.beforeyeh"] = {0, 0, 20, -0.5};
  layout->expandableGlyphs["lam.medi.beforeheh"] = {0, 0, 20, -0.5};
  layout->expandableGlyphs["lam.medi.afterkaf"] = {20, -1, 0, 0};
  layout->expandableGlyphs["meem.medi"] = {20, -0.5, 20, -0.5};
  layout->expandableGlyphs["meem.medi.afterseen"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["meem.medi.afterhah"] = {20, -0.5, 0, 0};
  layout->expandableGlyphs["meem.medi.beforeyeh"] = {0, -0.5, 20, -0.3};

  layout->expandableGlyphs["lam.medi.laf"] = {0.0, 0.0, 20, -0.5};
  layout->expandableGlyphs["dal.fina"] = {0.0, -1, 20, -0.5};
  layout->expandableGlyphs["heh.fina"] = {0.0, 0.0, 20, -0.5};
  layout->expandableGlyphs["hah.fina"] = {0.0, 0.0, 20, -0.5};
  layout->expandableGlyphs["seen.fina"] = {0, 0, 20, -0.4};
  layout->expandableGlyphs["feh.fina"] = {20, -2, 20, -0.2};
  layout->expandableGlyphs["meem.fina"] = {0.0, 0.0, 20, -0.3};
  layout->expandableGlyphs["meem.fina.ii"] = {0.0, 0.0, 20, -0.3};
  layout->expandableGlyphs["behshape.fina"] = {2.0, -1.0, 20, -0.1};
  layout->expandableGlyphs["qaf.fina"] = {0.0, -1, 20, -0.5};
  layout->expandableGlyphs["lam.fina"] = {0.0, -1, 20, -0.5};
  layout->expandableGlyphs["lam.fina.afterkaf"] = {0.0, -1, 0, 0};
  layout->expandableGlyphs["kaf.fina"] = {0.0, -1, 20, -0.3};
  layout->expandableGlyphs["kaf.fina.afterlam"] = {0.0, -1, 0, 0};
  layout->expandableGlyphs["noon.fina"] = {0.0, -1.0, 20, -0.1};
  layout->expandableGlyphs["noon.fina.basmala"] = {20, 0.0, 0, 0};
  layout->expandableGlyphs["reh.fina"] = {0.0, 0.0, 20, -0.5};
  layout->expandableGlyphs["ain.fina"] = {0.0, 0.0, 20, -0.3};

  layout->expandableGlyphs["fatha"] = {20, -1.0, 0, 0};
  layout->expandableGlyphs["kasra"] = {20, -1.0, 0, 0};
  layout->expandableGlyphs["space"] = {20, -2, 0.0, 0.0};
  layout->expandableGlyphs["kasratan"] = {20, -0.7, 0.0, 0.0};

  layout->expandableGlyphs["yehshape.fina.ii"] = {1, -1, 0.0, 0.0};
  layout->expandableGlyphs["alefmaksura.isol"] = {1, -1, 0.0, 0.0};
  layout->expandableGlyphs["yehshape.isol"] = {1, -1, 0.0, 0.0};
  layout->expandableGlyphs["yehshape.fina.afterbeh"] = {0, -1, 0, 0};
  layout->expandableGlyphs["noon.fina.afterbeh"] = {0, -1, 0, 0};
  layout->expandableGlyphs["noon.isol"] = {0, -1, 0, 0};
  layout->expandableGlyphs["dal.isol"] = {0, -1, 0, 0};

  // kashida_ii

  layout->expandableGlyphs["behshape.medi.expa"] = {20, -1, 20, -0.8};

  // Basmala
  layout->expandableGlyphs["behshape.medi.basmala"] = {20, -1, 0, 0};
  layout->expandableGlyphs["seen.medi.basmala"] = {20, -1, 0, 0};
  layout->expandableGlyphs["meem.fina.basmala"] = {0, 0, 20, -1};
}

CalcAnchor OldMadina::getanchorCalcFunctions(std::string functionName,
                                             Subtable* subtable) {
  CalcAnchor ret;
  if (functionName == "defaultmarkabovemark") {
    return Defaultmarkabovemark(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "defaultopmarkanchor") {
    return Defaultopmarkanchor(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "defaultmarkbelowmark") {
    return Defaultmarkbelowmark(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "defaullowmarkanchor") {
    return Defaullowmarkanchor(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "defaultbaseanchorforlow") {
    return Defaulbaseanchorforlow(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "defaulbaseanchorfortop") {
    return Defaulbaseanchorfortop(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "joinedsmalllettersbaseanchor") {
    return Joinedsmalllettersbaseanchor(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "DefaultBaseOfWaqfToMark") {
    return DefaultBaseOfWaqfToMark(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "DefaultBaseOfWaqfToBase") {
    return DefaultBaseOfWaqfToBase(*this, *(MarkBaseSubtable*)(subtable));
  } else if (functionName == "DefaultMarkOfWaqfToBase") {
    return DefaultMarkOfWaqfToBase(*this, *(MarkBaseSubtable*)(subtable));
  } else {
    return ret;
  }
}

class MediYehShapeFinaii {
 public:
  MediYehShapeFinaii(Automedina& y, PairAdjustmentSubtable& subtable) : _y(y), _subtable(subtable) {}
  ValueRecord operator()(GlyphVis* glyph1, GlyphVis* glyph2) {
    if (glyph2->conatinsAnchor("ltrcursive", GlyphVis::AnchorType::EntryAnchorRTL)) {
      if (glyph1->conatinsAnchor("ltrcursive", GlyphVis::AnchorType::ExitAnchorRTL)) {
        auto entryAnchor = glyph2->getAnchor("ltrcursive", GlyphVis::AnchorType::EntryAnchorRTL);
        auto exitAnchor = glyph1->getAnchor("ltrcursive", GlyphVis::AnchorType::ExitAnchorRTL);
        short vKern = exitAnchor.y() - entryAnchor.y();
        return {0, vKern, 0, 0};
      }
    }

    return {};
  };

 private:
  Automedina& _y;
  PairAdjustmentSubtable& _subtable;
};

PairAdjustFunc OldMadina::getPairAdjustFunction(std::string functionName,
                                                Subtable* subtable) {
  PairAdjustFunc ret;

  if (functionName == "medi_yehshape_fina_ii") {
    return MediYehShapeFinaii(*this, *(PairAdjustmentSubtable*)(subtable));
  } else {
    return ret;
  }
}

Lookup* OldMadina::getLookup(std::string lookupName) {
  if (lookupName == "defaultmarkpositioncpp") {
    return defaultmarkposition();
  } else if (lookupName == "defaultwaqfmarktobase") {
    return defaultwaqfmarktobase();
  } else if (lookupName == "forsmalllalef") {
    return forsmalllalef();
  } else if (lookupName == "forhamza") {
    return forhamza();
  } else if (lookupName == "forheh") {
    return forheh();
  } else if (lookupName == "forwaw") {
    return forwaw();
  } else if (lookupName == "rehwawcursivecpp") {
    return rehwawcursivecpp();
  } else if (lookupName == "cursivejoin") {
    return cursivejoin();
  } else if (lookupName == "defaultdotmarks") {
    return defaultdotmarks();
  } else if (lookupName == "pointmarks") {
    return pointmarks();
  } else if (lookupName == "defaultwaqfmarkabovemarkprecise") {
    return defaultwaqfmarkabovemarkprecise();
  } else if (lookupName == "defaultmarkdotmarks") {
    return defaultmarkdotmarks();
  } else if (lookupName == "defaultmkmk") {
    return defaultmkmk();
  } else if (lookupName == "ayanumbers") {
    return ayanumbers();
  } else if (lookupName == "ayanumberskern") {
    return ayanumberskern();
  } else if (lookupName == "shrinkstretchlt") {
    return shrinkstretchlt();
  } else if (lookupName == "tajweedcolorcpp") {
    return tajweedcolorcpp();
  } else if (lookupName == "forsmallhighwaw") {
    return forsmallhighwaw();
  } else if (lookupName == "populatecvxx") {
    return populatecvxx();
  } else if (lookupName == "glyphalternates") {
    return glyphalternates();
  }

  return nullptr;
}

Lookup* OldMadina::rehwawcursivecpp() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "rehwawcursivecpp";
  lookup->feature = "curs";
  lookup->type = Lookup::cursive;
  lookup->flags = Lookup::Flags::IgnoreMarks;  // | Lookup::Flags::RightToLeft;

  int kern = 100;

  class CustomCursiveSubtable : public CursiveSubtable {
   public:
    CustomCursiveSubtable(Lookup* lookup) : CursiveSubtable(lookup) {}

    virtual QPoint calculateEntry(GlyphVis* originalglyph, GlyphVis* extendedglyph, QPoint defaultEntry) {
      QPoint entry = entryParameters[originalglyph->charcode];

      entry += QPoint(extendedglyph->width, 0);

      return entry;
    }
  };

  CursiveSubtable* rehfinaafterbehshape = new CursiveSubtable(lookup);
  lookup->subtables.append(rehfinaafterbehshape);
  rehfinaafterbehshape->name = "rehfinaafterbehshape";
  rehfinaafterbehshape->anchors[glyphs["reh.fina.afterbehshape"].charcode].exit = QPoint(kern, 0);

  CursiveSubtable* rehfinaafterseen = new CursiveSubtable(lookup);
  lookup->subtables.append(rehfinaafterseen);
  rehfinaafterseen->name = "rehfinaafterseen";
  rehfinaafterseen->anchors[glyphs["reh.fina.afterseen"].charcode].exit = QPoint(kern, 0);

  CursiveSubtable* rehisol = new CursiveSubtable(lookup);
  lookup->subtables.append(rehisol);
  rehisol->name = "rehisol";
  rehisol->anchors[glyphs["reh.isol"].charcode].exit = QPoint(kern, 0);

  CursiveSubtable* wawisol = new CursiveSubtable(lookup);
  lookup->subtables.append(wawisol);
  wawisol->name = "wawisol";
  wawisol->anchors[glyphs["waw.isol"].charcode].exit = QPoint(kern, 0);

  CursiveSubtable* rehfina = new CustomCursiveSubtable(lookup);
  lookup->subtables.append(rehfina);
  rehfina->name = "rehfina";

  auto glyphcodes = m_layout->classtoUnicode("^reh.fina$|^reh.fina[.]added");

  for (auto glyphcode : glyphcodes) {
    rehfina->anchors[glyphcode].exit = QPoint(kern, 0);
  }

  CursiveSubtable* wawfina = new CustomCursiveSubtable(lookup);
  lookup->subtables.append(wawfina);
  wawfina->name = "wawfina";

  glyphcodes = m_layout->classtoUnicode("^waw.fina$|^waw.fina[.]added");

  for (auto glyphcode : glyphcodes) {
    wawfina->anchors[glyphcode].exit = QPoint(kern, 0);
  }

  glyphcodes = m_layout->classtoUnicode("[.]isol|[.]init");  //"((?<!reh|waw)[.]isol)|init"

  for (auto glyphcode : glyphcodes) {
    QString glyphName = m_layout->glyphNamePerCode[glyphcode];
    auto& glyph = glyphs[glyphName];

    rehisol->anchors[glyphcode].entry = QPoint(glyph.width, 0);
    wawisol->anchors[glyphcode].entry = QPoint(glyph.width, 0);
    rehfina->anchors[glyphcode].entry = QPoint(glyph.width, 0);
    wawfina->anchors[glyphcode].entry = QPoint(glyph.width, 0);
    rehfinaafterbehshape->anchors[glyphcode].entry = QPoint(glyph.width, 0);
    rehfinaafterseen->anchors[glyphcode].entry = QPoint(glyph.width, 0);
  }

  return lookup;
}
Lookup* OldMadina::cursivejoin() {
  auto lookup = new Lookup(m_layout);
  lookup->name = "cursivejoinrtl";
  lookup->feature = "curs";
  lookup->type = Lookup::cursive;
  lookup->flags = Lookup::Flags::IgnoreMarks | Lookup::Flags::RightToLeft;

  for (auto& [cursiveNameStr, entries] : entryAnchorsRTL) {
    auto& exits = exitAnchorsRTL[cursiveNameStr];

    CursiveSubtable* newsubtable = new CursiveSubtable(lookup);
    lookup->subtables.append(newsubtable);
    newsubtable->name = cursiveNameStr;

    for (auto& [glyphCode, point] : entries) {
      newsubtable->anchors[glyphCode].entry = point;
    }

    for (auto& [glyphCode, point] : exits) {
      newsubtable->anchors[glyphCode].exit = point;
    }
  }

  m_layout->addLookup(lookup);

  lookup = new Lookup(m_layout);
  lookup->name = "cursivejoin";
  lookup->feature = "curs";
  lookup->type = Lookup::cursive;
  lookup->flags = Lookup::Flags::IgnoreMarks;

  for (auto& [cursiveNameStr, entries] : entryAnchors) {
    auto& exits = exitAnchors[cursiveNameStr];

    CursiveSubtable* newsubtable = new CursiveSubtable(lookup);
    lookup->subtables.append(newsubtable);
    newsubtable->name = cursiveNameStr;

    for (auto& [glyphCode, point] : entries) {
      newsubtable->anchors[glyphCode].entry = point;
    }

    for (auto& [glyphCode, point] : exits) {
      newsubtable->anchors[glyphCode].exit = point;
    }
  }

  return lookup;
}
Lookup* OldMadina::defaultmarkposition() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "defaultmarkposition";
  lookup->feature = "mark";
  lookup->type = Lookup::mark2base;
  lookup->flags = 0;

  auto topmarks = classes["topmarks"];

  topmarks.erase("smallalef");
  topmarks.erase("smallalef.joined");
  topmarks.erase("smallalef.replacement");
  topmarks.erase("smallhighyeh");
  topmarks.erase("smallhighwaw");
  topmarks.erase("smallhighnoon");
  topmarks.erase("roundedfilledhigh");
  topmarks.erase("hamzaabove");
  topmarks.erase("hamzaabove.small");
  topmarks.erase("hamzaabove.joined");
  topmarks.erase("wasla");
  topmarks.erase("maddahabove");
  topmarks.erase("smallhighseen");
  topmarks.erase("shadda");

  auto lowmarks = classes["lowmarks"];
  lowmarks.erase("hamzabelow");
  lowmarks.erase("smalllowseen");

  // meem.fina.afterkaf

  MarkBaseSubtable* newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "meemfinaafterkaf";
  newsubtable->base = {"meem.fina.afterkaf"};
  newsubtable->classes["sukun"].mark = {"sukun"};
  newsubtable->classes["sukun"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["sukun"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // tah
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "tah";
  newsubtable->base = {"^tah"};

  newsubtable->classes["fathadamma"].mark = {"fatha", "damma", "shadda"};
  newsubtable->classes["fathadamma"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["fathadamma"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable->classes["sukun"].mark = {"sukun"};
  newsubtable->classes["sukun"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["sukun"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable->classes["fathatandammatan"].mark = {"fathatan", "dammatan"};
  newsubtable->classes["fathatandammatan"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["fathatandammatan"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable->classes["idgham"].mark = {"fathatanidgham", "dammatanidgham"};
  newsubtable->classes["idgham"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["idgham"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // default
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "topmarks";
  newsubtable->base = {"bases"};
  newsubtable->classes["topmarks"].mark = toStdStringSet(topmarks);
  newsubtable->classes["topmarks"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["topmarks"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);
  newsubtable->name = "lowmarks";
  newsubtable->base = {"bases"};
  newsubtable->classes["lowmarks"].mark = toStdStringSet(lowmarks);
  newsubtable->classes["lowmarks"].basefunction = Defaulbaseanchorforlow(*this, *newsubtable);
  newsubtable->classes["lowmarks"].markfunction = Defaullowmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  newsubtable->name = "smallletters";
  newsubtable->base = {"bases"};
  lookup->subtables.append(newsubtable);
  newsubtable->classes["smallletters"].mark = {"smallalef.joined", "smallhighwaw"};
  newsubtable->classes["smallletters"].basefunction = Defaulbaseanchorforsmallalef(*this, *newsubtable);
  newsubtable->classes["smallletters"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  newsubtable->name = "joinedmarks";
  newsubtable->base = {"bases"};
  lookup->subtables.append(newsubtable);
  newsubtable->classes["hamzaabove"].mark = {"hamzaabove.joined"};
  newsubtable->classes["hamzaabove"].basefunction = Defaulbaseanchorforsmallalef(*this, *newsubtable);
  newsubtable->classes["hamzaabove"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // default
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);
  newsubtable->name = "smallhighyeh";
  newsubtable->base = {"bases"};  // TODO minimize

  newsubtable->classes["smallhighyeh"].mark = {"smallhighyeh"};
  newsubtable->classes["smallhighyeh"].basefunction = Defaulbaseanchorforsmallalef(*this, *newsubtable);
  newsubtable->classes["smallhighyeh"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // shadda

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "shadda";
  newsubtable->base = {"bases"};
  newsubtable->classes["shadda"].mark = {"shadda"};
  newsubtable->classes["shadda"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["shadda"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // maddahabove

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "maddahabove";
  newsubtable->base = {"bases"};
  newsubtable->classes["maddahabove"].mark = {"maddahabove"};
  newsubtable->classes["maddahabove"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["maddahabove"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // hamzaabove

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "hamzaabove";
  newsubtable->base = {"alef|waw|yehshape|behshape"};
  newsubtable->classes["hamzaabove"].mark = {"hamzaabove", "hamzaabove.small"};
  newsubtable->classes["hamzaabove"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["hamzaabove"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // smallalef.replacement

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "smallalefreplacement";
  newsubtable->base = {"alef|waw|yehshape|behshape"};
  newsubtable->classes["smallalefreplacement"].mark = {"smallalef.replacement"};
  newsubtable->classes["smallalefreplacement"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["smallalefreplacement"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // roundedfilledhigh

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "roundedfilledhigh";
  newsubtable->base = {"alef[.]isol.*|meem[.]init.*"};
  newsubtable->classes["roundedfilledhigh"].mark = {"roundedfilledhigh"};
  newsubtable->classes["roundedfilledhigh"].basefunction = Defaulbaseanchorforsmallalef(*this, *newsubtable);
  newsubtable->classes["roundedfilledhigh"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // smallhighnoon
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "smallhighnoon";
  newsubtable->base = {"behshape[.]init.*"};
  newsubtable->classes["smallhighnoon"].mark = {"smallhighnoon"};
  newsubtable->classes["smallhighnoon"].basefunction = Defaulbaseanchorforsmallalef(*this, *newsubtable);
  newsubtable->classes["smallhighnoon"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // smallhighseen
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "smallhighseen";
  newsubtable->base = {"sad[.]medi|^alef.fina|^heh.fina|^lam.fina|^noon.fina"};
  newsubtable->classes["smallhighseen"].mark = {"smallhighseen"};
  newsubtable->classes["smallhighseen"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["smallhighseen"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // hamzaabove.lamalef
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "hamzaabove.lamalef";
  newsubtable->base = {"lam.init.lamalef", "^lam.medi.laf"};
  newsubtable->classes["hamzaabove"].mark = {"hamzaabove.lamalef"};
  newsubtable->classes["hamzaabove"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["hamzaabove"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // hamzabelow
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "hamzabelow";
  newsubtable->base = {"^alef[.]"};
  newsubtable->classes["hamzabelow"].mark = {"hamzabelow"};
  newsubtable->classes["hamzabelow"].basefunction = Defaulbaseanchorforlow(*this, *newsubtable);
  newsubtable->classes["hamzabelow"].markfunction = Defaullowmarkanchor(*this, *newsubtable);

  // wasla
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "wasla";
  newsubtable->base = {"^alef[.]"};
  newsubtable->classes["wasla"].mark = {"wasla"};
  newsubtable->classes["wasla"].basefunction = Defaulbaseanchorfortop(*this, *newsubtable);
  newsubtable->classes["wasla"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  // smalllowseen
  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "smalllowseen";
  newsubtable->base = {"^sad[.]medi"};
  newsubtable->classes["smalllowseen"].mark = {"smalllowseen"};
  newsubtable->classes["smalllowseen"].basefunction = Defaulbaseanchorforlow(*this, *newsubtable);
  newsubtable->classes["smalllowseen"].markfunction = Defaullowmarkanchor(*this, *newsubtable);

  return lookup;
}
Lookup* OldMadina::defaultwaqfmarktobase() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "defaultwaqfmarktobase";
  lookup->feature = "mark";
  lookup->type = Lookup::mark2base;

  MarkBaseSubtable* newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "defaultwaqfmarktobase";
  newsubtable->base = {"isol|fina|smallwaw|smallyeh"};

  newsubtable->classes["waqfmarks"].mark = {"waqfmarks"};
  newsubtable->classes["waqfmarks"].basefunction = DefaultBaseOfWaqfToBase(*this, *newsubtable);
  newsubtable->classes["waqfmarks"].markfunction = DefaultMarkOfWaqfToBase(*this, *newsubtable);

  return lookup;
}
Lookup* OldMadina::defaultdotmarks() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "defaultdotmarks";
  lookup->feature = "mark";
  lookup->type = Lookup::mark2base;
  lookup->flags = 0;

  MarkBaseSubtable* newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "onedotup";
  newsubtable->base = {"^behshape|^hah|^feh|^dal|^reh|^sad|^tah|^ain|^noon"};
  newsubtable->classes["onedotup"].mark = {"onedotup"};
  newsubtable->classes["onedotup"].basefunction = Defaulbaseanchorfortopdots(*this, *newsubtable);
  newsubtable->classes["onedotup"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);
  newsubtable->name = "twodotsup";
  newsubtable->base = {"^behshape|^fehshape|^heh|^qaf"};
  newsubtable->classes["twodotsup"].mark = {"twodotsup"};
  newsubtable->classes["twodotsup"].basefunction = Defaulbaseanchorfortopdots(*this, *newsubtable);
  newsubtable->classes["twodotsup"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);
  newsubtable->name = "three_dots";
  newsubtable->base = {"^behshape|^seen"};
  newsubtable->classes["three_dots"].mark = {"three_dots"};
  newsubtable->classes["three_dots"].basefunction = Defaulbaseanchorfortopdots(*this, *newsubtable);
  newsubtable->classes["three_dots"].markfunction = Defaultopmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);
  newsubtable->name = "onedotdown";
  newsubtable->base = {"^behshape|^hah"};
  newsubtable->classes["onedotdown"].mark = {"onedotdown"};
  newsubtable->classes["onedotdown"].basefunction = Defaulbaseanchorforlowdots(*this, *newsubtable);
  newsubtable->classes["onedotdown"].markfunction = Defaullowmarkanchor(*this, *newsubtable);

  newsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(newsubtable);
  newsubtable->name = "twodotsdown";
  newsubtable->base = {"^behshape"};
  newsubtable->classes["twodotsdown"].mark = {"twodotsdown"};
  newsubtable->classes["twodotsdown"].basefunction = Defaulbaseanchorforlowdots(*this, *newsubtable);
  newsubtable->classes["twodotsdown"].markfunction = Defaullowmarkanchor(*this, *newsubtable);

  return lookup;
}
Lookup* OldMadina::defaultmkmk() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "defaultmkmk";
  lookup->feature = "mkmk";
  lookup->type = Lookup::mark2mark;
  lookup->flags = 0;

  MarkBaseSubtable* subtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(subtable);

  subtable->name = "defaultmkmktop";
  subtable->base = {"hamzaabove", "hamzaabove.small", "hamzaabove.joined", "hamzaabove.lamalef", "shadda", "smallalef", "smallalef.joined", "smallalef.replacement", "smallhighseen", "smallhighwaw", "smallhighyeh"};

  subtable->classes["topmarks"].mark = {"topmarks"};
  subtable->classes["topmarks"].basefunction = Defaultmarkabovemark(*this, *subtable);
  subtable->classes["topmarks"].markfunction = Defaultopmarkanchor(*this, *subtable);

  subtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(subtable);

  subtable->name = "defaultmkmkbottom";
  subtable->base = {"hamzabelow", "hamzaabove.joined", "smallhighyeh"};

  subtable->classes["lowmarks"].mark = {"lowmarks"};
  subtable->classes["lowmarks"].basefunction = Defaulbaseanchorforlow(*this, *subtable);
  subtable->classes["lowmarks"].markfunction = Defaullowmarkanchor(*this, *subtable);

  subtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(subtable);

  subtable->name = "defaultmkmkmeemiqlab";
  subtable->base = {"fatha", "damma"};  // "kasra"

  subtable->classes["meemiqlab"].mark = {"meemiqlab"};
  subtable->classes["meemiqlab"].basefunction = Defaultmarkabovemark(*this, *subtable);
  subtable->classes["meemiqlab"].markfunction = Defaultopmarkanchor(*this, *subtable);

  subtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(subtable);

  subtable->name = "defaultmkmksmalllowmeem";
  subtable->base = {"kasra"};

  subtable->classes["smalllowmeem"].mark = {"smalllowmeem"};
  subtable->classes["smalllowmeem"].basefunction = Defaultmarkbelowmark(*this, *subtable);
  subtable->classes["smalllowmeem"].markfunction = Defaullowmarkanchor(*this, *subtable);

  // hamzaabove.joined
  // subtable = new MarkBaseSubtable(lookup);
  // lookup->subtables.append(subtable);

  // subtable->name = "hamzaabovejoined";
  // subtable->base = {"maddahabove"};

  // subtable->classes["hamzaabove.joined"].mark = {"hamzaabove.joined"};
  // subtable->classes["hamzaabove.joined"].basefunction = nullptr;  //;new Defaultmarkabovemark(*this, *smallhighseen);
  // subtable->classes["hamzaabove.joined"].markfunction = nullptr;  // new Defaultopmarkanchor(*this, *smallhighseen);

  // waqf

  /*subtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(subtable);

  subtable->name = "waqfsubtable";
  subtable->base = {"topmarks"};

  auto basefunctionwaqf = [this](QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) -> QPoint {
    GlyphVis* curr = &glyphs[glyphName];
    curr = curr->getAlternate(parameters);

    int width = curr->width * 0.5;
    int height = curr->height + 30;

    width = width + adjust.x();
    height = height + adjust.y();

    return QPoint(width, height);
  };

  subtable->classes["waqf"].mark = {"waqfmarks"};
  subtable->classes["waqf"].basefunction = basefunctionwaqf;
  subtable->classes["waqf"].markfunction = Defaultopmarkanchor(*this, *subtable);*/

  m_layout->addLookup(lookup);

  // hamzaabove.joined

  lookup = new Lookup(m_layout);
  lookup->name = "smallalefjoined";
  lookup->feature = "mkmk";
  lookup->type = Lookup::mark2mark;
  lookup->markGlyphSetIndex = m_layout->addMarkSet({(std::uint16_t)glyphs["smallalef.joined"].charcode, (std::uint16_t)glyphs["hamzaabove.joined"].charcode});
  lookup->flags = lookup->flags | Lookup::Flags::UseMarkFilteringSet;

  subtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(subtable);

  subtable->name = "smallalefjoined";
  subtable->base = {"hamzaabove.joined"};

  subtable->classes["smallalef.joined"].mark = {"smallalef.joined"};
  // subtable->classes["smallalef.joined"].baseanchors = { { "smallalef.joined", 1 } }
  subtable->classes["smallalef.joined"].markanchors = {{"smallalef.joined", QPoint(200, 0)}};

  return lookup;
}
Lookup* OldMadina::defaultmarkdotmarks() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "defaultmarkdotmarkstop";
  lookup->feature = "mkmk";
  lookup->type = Lookup::mark2mark;
  lookup->flags = 0;

  MarkBaseSubtable* topsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(topsubtable);

  topsubtable->name = "defaultmarkdotmarkstop";
  topsubtable->base = {"topdotmarks"};

  auto basetopfunction = [this, topsubtable](QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) -> QPoint {
    GlyphVis& curr = glyphs[glyphName];

    int width = curr.width * 0.5;
    int height = (int)curr.height + 80;

    width = width + adjust.x();
    height = height + adjust.y();

    return QPoint(width, height);
  };

  auto topmarks = classes["topmarks"];
  topmarks.erase("shadda");

  topsubtable->classes["topmarks"].mark = toStdStringSet(topmarks);
  topsubtable->classes["topmarks"].basefunction = basetopfunction;
  topsubtable->classes["topmarks"].markfunction = Defaultopmarkanchor(*this, *topsubtable);

  topsubtable->classes["shadda"].mark = {"shadda"};
  topsubtable->classes["shadda"].basefunction = basetopfunction;
  topsubtable->classes["shadda"].markfunction = Defaultopmarkanchor(*this, *topsubtable);

  m_layout->addLookup(lookup);

  lookup = new Lookup(m_layout);
  lookup->name = "defaultmarkdotmarksbottom";
  lookup->feature = "mkmk";
  lookup->type = Lookup::mark2mark;
  lookup->flags = 0;
  lookup->setGlyphSet({"downdotmarks", "lowmarks"});

  MarkBaseSubtable* bottomsubtable = new MarkBaseSubtable(lookup);
  lookup->subtables.append(bottomsubtable);

  bottomsubtable->name = "defaultmarkdotmarksbottom";
  bottomsubtable->base = {"downdotmarks"};

  auto basedownfunction = [this, bottomsubtable](QString glyphName, QString className, QPoint adjust, GlyphParameters parameters) -> QPoint {
    GlyphVis& curr = glyphs[glyphName];

    int depth = -(int)curr.depth + 50;
    int width = curr.width * 0.5;

    width = width + adjust.x();
    depth = depth - adjust.y();

    return QPoint(width, -depth);
  };

  bottomsubtable->classes["lowmarks"].mark = {"lowmarks"};
  bottomsubtable->classes["lowmarks"].basefunction = basedownfunction;
  bottomsubtable->classes["lowmarks"].markfunction = Defaullowmarkanchor(*this, *bottomsubtable);

  return lookup;
}
Lookup* OldMadina::defaultwaqfmarkabovemarkprecise() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "defaultwaqfmarkabovemarkprecise";
  lookup->feature = "mark";
  lookup->type = Lookup::chainingpos;
  lookup->flags = 0;

  std::unordered_set<std::uint16_t> waqfmarks = classtoUnicode("waqfmarks");
  std::unordered_set<std::uint16_t> bases = classtoUnicode("bases");

  for (auto& topmark : classes["topmarks"]) {
    QString sublookupName = QString::fromStdString(topmark);

    Lookup* sublookup = new Lookup(m_layout);
    sublookup->name = lookup->name + "." + sublookupName;
    sublookup->feature = "";
    sublookup->type = Lookup::mark2base;
    sublookup->flags = 0;

    m_layout->addLookup(sublookup);

    MarkBaseSubtable* marksubtable = new MarkBaseSubtable(sublookup);
    sublookup->subtables.append(marksubtable);

    marksubtable->name = asStdString(sublookup->name);
    marksubtable->base = {"bases"};

    marksubtable->classes["waqfmarks"].mark = {"waqfmarks"};
    marksubtable->classes["waqfmarks"].basefunction = Defaulbaseanchorfortop(*this, *marksubtable);
    marksubtable->classes["waqfmarks"].markfunction = Defaultopmarkanchor(*this, *marksubtable);

    ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
    lookup->subtables.append(newsubtable);

    newsubtable->name = asStdString("topmarks_" + QString::fromStdString(topmark));

    newsubtable->compiledRule = ChainingSubtable::CompiledRule();

    newsubtable->compiledRule.backtrack.push_back(bases);
    newsubtable->compiledRule.backtrack.push_back(std::unordered_set{(std::uint16_t)glyphs[QString::fromStdString(topmark)].charcode});
    newsubtable->compiledRule.input.push_back(waqfmarks);

    newsubtable->compiledRule.lookupRecords.push_back({0, asStdString(sublookupName)});
  }

  return lookup;
}
Lookup* OldMadina::tajweedcolorcpp() {
  Lookup* single = new Lookup(m_layout);
  single->name = "tajweedcolor.green";
  single->feature = "";
  single->type = Lookup::singleadjustment;
  m_layout->addLookup(single);

  ValueRecord green{99, 200, 77, 0};
  ValueRecord gray{200, 200, 200, 0};
  ValueRecord lkalkala{200, 200, 200, 0};

  SingleAdjustmentSubtable* newsubtable = new SingleAdjustmentSubtable(single, 3);
  single->subtables.append(newsubtable);
  newsubtable->name = asStdString(single->name);
  for (auto className : {"bases", "marks"}) {
    auto unicodes = m_layout->classtoUnicode(className);
    for (auto unicode : unicodes) {
      newsubtable->singlePos[unicode] = green;
    }
  }

  single = new Lookup(m_layout);
  single->name = "tajweedcolor.lgray";
  single->feature = "";
  single->type = Lookup::singleadjustment;
  m_layout->addLookup(single);

  newsubtable = new SingleAdjustmentSubtable(single, 3);
  single->subtables.append(newsubtable);
  newsubtable->name = asStdString(single->name);
  for (auto className : {"^meem|^behshape|onedotup|^noon", "marks"}) {
    auto unicodes = m_layout->classtoUnicode(className);
    for (auto unicode : unicodes) {
      newsubtable->singlePos[unicode] = gray;
    }
  }

  single = new Lookup(m_layout);
  single->name = "tajweedcolor.lkalkala";
  single->feature = "";
  single->type = Lookup::singleadjustment;
  m_layout->addLookup(single);

  newsubtable = new SingleAdjustmentSubtable(single, 3);
  single->subtables.append(newsubtable);
  newsubtable->name = asStdString(single->name);
  for (auto className : {"^tah|^behshape|^dal|^hah|^kaf|^fehshape", "marks"}) {
    auto unicodes = m_layout->classtoUnicode(className);
    for (auto unicode : unicodes) {
      newsubtable->singlePos[unicode] = lkalkala;
    }
  }

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "tajweedcolor";
  lookup->feature = "mkmk";
  lookup->type = Lookup::chainingpos;
  lookup->flags = 0;

  // tajweedcolor_meemiqlab1
  ChainingSubtable* chainingsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(chainingsubtable);

  chainingsubtable->name = "tajweedcolor_meemiqlab1";

  chainingsubtable->compiledRule = ChainingSubtable::CompiledRule();

  chainingsubtable->compiledRule.input.push_back(classtoUnicode("^noon"));
  chainingsubtable->compiledRule.input.push_back(classtoUnicode("meemiqlab"));

  chainingsubtable->compiledRule.lookupRecords.push_back({0, "lgray"});
  chainingsubtable->compiledRule.lookupRecords.push_back({1, "green"});

  // tajweedcolor_meemiqlab2
  chainingsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(chainingsubtable);

  chainingsubtable->name = "tajweedcolor_meemiqlab2";

  chainingsubtable->compiledRule = ChainingSubtable::CompiledRule();

  chainingsubtable->compiledRule.input.push_back(classtoUnicode("^behshape"));
  chainingsubtable->compiledRule.input.push_back(classtoUnicode("onedotup"));
  chainingsubtable->compiledRule.input.push_back(classtoUnicode("meemiqlab"));

  chainingsubtable->compiledRule.lookupRecords.push_back({0, "lgray"});
  chainingsubtable->compiledRule.lookupRecords.push_back({1, "lgray"});
  chainingsubtable->compiledRule.lookupRecords.push_back({2, "green"});

  // tajweedcolor_meemnoon
  chainingsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(chainingsubtable);

  chainingsubtable->name = "tajweedcolor_meemnoon";

  chainingsubtable->compiledRule = ChainingSubtable::CompiledRule();

  chainingsubtable->compiledRule.input.push_back(classtoUnicode("^meem|^noon"));
  chainingsubtable->compiledRule.input.push_back(classtoUnicode("shadda"));
  chainingsubtable->compiledRule.input.push_back(classtoUnicode("marks"));

  chainingsubtable->compiledRule.lookupRecords.push_back({0, "green"});
  chainingsubtable->compiledRule.lookupRecords.push_back({1, "green"});
  chainingsubtable->compiledRule.lookupRecords.push_back({2, "green"});

  return lookup;
}
Lookup* OldMadina::pointmarks() {
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "pointmarks";
  lookup->feature = "mark";
  lookup->type = Lookup::chainingpos;
  lookup->flags = 0;
  // lookup->markGlyphSetIndex = m_layout->addMarkSet({ (std::uint16_t)glyphs["smallalef"].charcode });
  // lookup->flags = lookup->flags | Lookup::Flags::UseMarkFilteringSet;

  for (auto& pointmark : classes["dotmarks"]) {
    QString sublookupName = QString::fromStdString(pointmark);

    Lookup* sublookup = new Lookup(m_layout);
    sublookup->name = lookup->name + "." + sublookupName;
    sublookup->feature = "";
    sublookup->type = Lookup::mark2base;
    sublookup->flags = 0;

    m_layout->addLookup(sublookup);

    MarkBaseSubtable* marksubtable = new MarkBaseSubtable(sublookup);
    sublookup->subtables.append(marksubtable);

    marksubtable->name = asStdString(sublookup->name);
    marksubtable->base = {"bases"};

    marksubtable->classes["topmarks"].mark = {"topmarks"};
    marksubtable->classes["topmarks"].basefunction = Defaulbaseanchorfortop(*this, *marksubtable);
    marksubtable->classes["topmarks"].markfunction = Defaultopmarkanchor(*this, *marksubtable);

    marksubtable->classes["lowmarks"].mark = {"lowmarks"};
    marksubtable->classes["lowmarks"].basefunction = Defaulbaseanchorforlow(*this, *marksubtable);
    marksubtable->classes["lowmarks"].markfunction = Defaullowmarkanchor(*this, *marksubtable);

    ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
    lookup->subtables.append(newsubtable);

    newsubtable->name = asStdString("pointmarks_" + QString::fromStdString(pointmark));

    newsubtable->compiledRule = ChainingSubtable::CompiledRule();

    newsubtable->compiledRule.backtrack.push_back({classtoUnicode("bases")});
    newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs[QString::fromStdString(pointmark)].charcode});
    newsubtable->compiledRule.input.push_back(classtoUnicode("marks"));

    newsubtable->compiledRule.lookupRecords.push_back({1, asStdString(sublookupName)});
  }

  return lookup;
}

Lookup* OldMadina::ayanumberskern() {
  auto& ayaGlyph = glyphs["endofaya"];
  auto digitySet = classtoUnicode("digits");
  qint16 yoffset = 120;

  // three digits
  Lookup* sublookup = new Lookup(m_layout);
  sublookup->name = "ayanumberskern.l1";
  sublookup->feature = "";
  sublookup->type = Lookup::singleadjustment;
  m_layout->addLookup(sublookup);

  SingleAdjustmentSubtable* singleadjsubtable = new SingleAdjustmentSubtable(sublookup);
  sublookup->subtables.append(singleadjsubtable);

  singleadjsubtable->name = asStdString(sublookup->name);

  for (auto digit : digitySet) {
    auto& onesglyph = glyphs[m_layout->glyphNamePerCode.value(digit)];
    qint16 kern = -(ayaGlyph.width / 2 - onesglyph.width / 2);
    singleadjsubtable->singlePos[digit] = {700, yoffset, 0, 0};
  }

  // two digits
  sublookup = new Lookup(m_layout);
  sublookup->name = "ayanumberskern.l2";
  sublookup->feature = "";
  sublookup->type = Lookup::singleadjustment;
  m_layout->addLookup(sublookup);

  singleadjsubtable = new SingleAdjustmentSubtable(sublookup);
  sublookup->subtables.append(singleadjsubtable);

  singleadjsubtable->name = asStdString(sublookup->name);

  for (auto digit : digitySet) {
    singleadjsubtable->singlePos[digit] = {500, yoffset, 0, 0};
  }

  // 1 digit
  sublookup = new Lookup(m_layout);
  sublookup->name = "ayanumberskern.l3";
  sublookup->feature = "";
  sublookup->type = Lookup::singleadjustment;
  m_layout->addLookup(sublookup);

  singleadjsubtable = new SingleAdjustmentSubtable(sublookup);
  sublookup->subtables.append(singleadjsubtable);

  singleadjsubtable->name = asStdString(sublookup->name);

  for (auto digit : digitySet) {
    auto& onesglyph = glyphs[m_layout->glyphNamePerCode.value(digit)];
    int leftBearing = 0;
    qint16 kern = leftBearing + (ayaGlyph.width - leftBearing) / 2 + onesglyph.width / 2;
    singleadjsubtable->singlePos[digit] = {kern, yoffset, 0, 0};
  }

  // up
  sublookup = new Lookup(m_layout);
  sublookup->name = "ayanumberskern.up";
  sublookup->feature = "";
  sublookup->type = Lookup::singleadjustment;
  m_layout->addLookup(sublookup);

  singleadjsubtable = new SingleAdjustmentSubtable(sublookup);
  sublookup->subtables.append(singleadjsubtable);

  singleadjsubtable->name = asStdString(sublookup->name);

  for (auto digit : digitySet) {
    singleadjsubtable->singlePos[digit] = {0, yoffset, 0, 0};
  }

  // main lokkup

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "ayanumberskern";
  lookup->feature = "kern";
  lookup->type = Lookup::chainingpos;
  lookup->flags = 0;
  // lookup->markGlyphSetIndex = m_layout->addMarkSet({ (std::uint16_t)glyphs["smallalef"].charcode });
  // lookup->flags = lookup->flags | Lookup::Flags::IgnoreMarks;

  ChainingSubtable* subtable = new ChainingSubtable(lookup);
  lookup->subtables.append(subtable);
  subtable->name = "ayanumbers3digits";
  subtable->compiledRule = ChainingSubtable::CompiledRule();
  // subtable->compiledRule.backtrack = {{(int16_t)ayaGlyph.charcode}};
  subtable->compiledRule.input = {{(uint16_t)ayaGlyph.charcode}, digitySet, digitySet, digitySet};
  subtable->compiledRule.lookupRecords.push_back({1, "l1"});
  subtable->compiledRule.lookupRecords.push_back({2, "l1"});
  subtable->compiledRule.lookupRecords.push_back({3, "l1"});

  subtable = new ChainingSubtable(lookup);
  lookup->subtables.append(subtable);
  subtable->name = "ayanumbers2digits";
  // subtable->compiledRule.backtrack = {{(int16_t)ayaGlyph.charcode}};
  subtable->compiledRule = ChainingSubtable::CompiledRule();
  subtable->compiledRule.input = {{(uint16_t)ayaGlyph.charcode}, digitySet, digitySet};
  subtable->compiledRule.lookupRecords.push_back({1, "l2"});
  subtable->compiledRule.lookupRecords.push_back({2, "l2"});

  subtable = new ChainingSubtable(lookup);
  lookup->subtables.append(subtable);
  subtable->name = "ayanumbers1digit";
  // subtable->compiledRule.backtrack = {{(std::uint16_t)ayaGlyph.charcode}};
  subtable->compiledRule = ChainingSubtable::CompiledRule();
  subtable->compiledRule.input = {{(uint16_t)ayaGlyph.charcode}, digitySet};
  subtable->compiledRule.lookupRecords.push_back({1, "l3"});

  return lookup;
}

Lookup* OldMadina::ayanumbers() {
  QString ayaName = "endofaya";

  std::uint16_t endofaya = m_layout->glyphCodePerName[ayaName];

  // ligature
  Lookup* ligature = new Lookup(m_layout);
  ligature->name = "ayanumbers.l1";
  ligature->feature = "";
  ligature->type = Lookup::ligature;
  m_layout->addLookup(ligature);

  LigatureSubtable* ligaturesubtable = new LigatureSubtable(ligature);
  ligature->subtables.append(ligaturesubtable);
  ligaturesubtable->name = asStdString(ligature->name);

  for (std::uint16_t i = 286; i > 99; i--) {
    std::uint16_t code = m_layout->glyphCodePerName[QString("%1%2").arg(ayaName).arg(i)];

    int onesdigit = i % 10;
    int tensdigit = (i / 10) % 10;
    int hundredsdigit = i / 100;
    if (extended) {
      ligaturesubtable->ligatures.push_back({code, {endofaya, (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + hundredsdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + tensdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + onesdigit))}});
    } else {
      ligaturesubtable->ligatures.push_back({code, {(std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + onesdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + tensdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + hundredsdigit)), endofaya}});
      ligaturesubtable->ligatures.push_back({code, {endofaya, (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + hundredsdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + tensdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + onesdigit))}});
    }
  }

  // ligature
  ligature = new Lookup(m_layout);
  ligature->name = "ayanumbers.l2";
  ligature->feature = "";
  ligature->type = Lookup::ligature;
  m_layout->addLookup(ligature);

  ligaturesubtable = new LigatureSubtable(ligature);
  ligature->subtables.append(ligaturesubtable);
  ligaturesubtable->name = asStdString(ligature->name);

  for (std::uint16_t i = 99; i > 9; i--) {
    std::uint16_t code = m_layout->glyphCodePerName[QString("%1%2").arg(ayaName).arg(i)];
    int onesdigit = i % 10;
    int tensdigit = i / 10;
    if (extended) {
      ligaturesubtable->ligatures.push_back({code, {endofaya, (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + tensdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + onesdigit))}});
    } else {
      ligaturesubtable->ligatures.push_back({code, {(std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + onesdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + tensdigit)), endofaya}});
      ligaturesubtable->ligatures.push_back({code, {endofaya, (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + tensdigit)), (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + onesdigit))}});
    }
  }

  // ligature
  ligature = new Lookup(m_layout);
  ligature->name = "ayanumbers.l3";
  ligature->feature = "";
  ligature->type = Lookup::ligature;
  m_layout->addLookup(ligature);

  ligaturesubtable = new LigatureSubtable(ligature);
  ligature->subtables.append(ligaturesubtable);
  ligaturesubtable->name = asStdString(ligature->name);

  for (int i = 1; i < 10; i++) {
    std::uint16_t code = m_layout->glyphCodePerName[QString("%1%2").arg(ayaName).arg(i)];
    ligaturesubtable->ligatures.push_back({code, {endofaya, (std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + i))}});
    ligaturesubtable->ligatures.push_back({code, {(std::uint16_t)(m_layout->unicodeToGlyphCode.value(1632 + i)), endofaya}});
  }

  // main lokkup

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "ayanumbers";
  lookup->feature = "rlig";
  lookup->type = Lookup::chainingsub;
  lookup->flags = 0;
  // lookup->markGlyphSetIndex = m_layout->addMarkSet({ (std::uint16_t)glyphs["smallalef"].charcode });
  // lookup->flags = lookup->flags | Lookup::Flags::IgnoreMarks;

  auto digitySet = classtoUnicode("digits");

  auto digitySetplusendofaya = digitySet;
  digitySetplusendofaya.insert(endofaya);

  ChainingSubtable* subtable = new ChainingSubtable(lookup);
  lookup->subtables.append(subtable);
  subtable->name = "ayanumbers3digits";
  subtable->compiledRule = ChainingSubtable::CompiledRule();
  if (extended) {
    subtable->compiledRule.input = {{endofaya}, digitySet, digitySet, digitySet};
  } else {
    // subtable->compiledRule.input = {digitySet,digitySet,digitySet,{endofaya} };
    subtable->compiledRule.input = {digitySetplusendofaya, digitySet, digitySet, digitySetplusendofaya};
  }

  subtable->compiledRule.lookupRecords.push_back({0, "l1"});

  subtable = new ChainingSubtable(lookup);
  lookup->subtables.append(subtable);
  subtable->name = "ayanumbers2digits";
  subtable->compiledRule = ChainingSubtable::CompiledRule();
  if (extended) {
    subtable->compiledRule.input = {{endofaya}, digitySet, digitySet};
  } else {
    subtable->compiledRule.input = {digitySetplusendofaya, digitySet, digitySetplusendofaya};
  }
  subtable->compiledRule.lookupRecords.push_back({0, "l2"});

  subtable = new ChainingSubtable(lookup);
  lookup->subtables.append(subtable);
  subtable->name = "ayanumbers1digit";
  subtable->compiledRule = ChainingSubtable::CompiledRule();
  if (extended) {
    subtable->compiledRule.input = {{endofaya}, digitySet};
  } else {
    subtable->compiledRule.input = {digitySetplusendofaya, digitySetplusendofaya};
  }
  subtable->compiledRule.lookupRecords.push_back({0, "l3"});

  return lookup;
}
Lookup* OldMadina::forheh() {
  Lookup* single = new Lookup(m_layout);
  single->name = "forheh.l1";
  single->feature = "";
  single->type = Lookup::single;
  m_layout->addLookup(single);

  SingleSubtable* singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  for (auto& glyph : glyphs) {
    if (classes["haslefttatweel"].contains(glyph.name)) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)((glyph.charlt + 2) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    } else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt + 2) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    }
  }

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "forheh";
  lookup->feature = "rlig";
  lookup->type = Lookup::chainingsub;
  lookup->flags = 0;
  // lookup->markGlyphSetIndex = m_layout->addMarkSet({ (std::uint16_t)glyphs["smallalef"].charcode });
  lookup->flags = lookup->flags | Lookup::Flags::IgnoreMarks;

  ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "forheh";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  auto keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  // newsubtable->compiledRule.input.push_back({ (std::uint16_t)glyphs["heh.medi"].charcode,(std::uint16_t)glyphs["heh.medi.forsmalllalef"].charcode });
  newsubtable->compiledRule.lookahead.push_back(classtoUnicode("^heh.medi"));  //  { (std::uint16_t)glyphs["heh.medi"].charcode });

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});

  return lookup;
}
Lookup* OldMadina::forhamza() {
  Lookup* single = new Lookup(m_layout);
  single->name = "forhamza.l1";
  single->feature = "";
  single->type = Lookup::single;

  m_layout->addLookup(single);

  SingleSubtable* singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  int tatweel = 2;

  for (auto& glyph : glyphs) {
    if (classes["haslefttatweel"].contains(glyph.name)) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    } else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    }
  }

  // ligature
  Lookup* ligature = new Lookup(m_layout);
  ligature->name = "forhamza.l2";
  ligature->feature = "";
  ligature->type = Lookup::ligature;
  // ligature->markGlyphSetIndex = m_layout->addMarkSet({ (std::uint16_t)glyphs["hamzaabove"].charcode,(std::uint16_t)glyphs["smallhighyeh"].charcode,(std::uint16_t)glyphs["smallhighwaw"].charcode ,(std::uint16_t)glyphs["smallhighnoon"].charcode });
  // ligature->flags = ligature->flags | Lookup::Flags::UseMarkFilteringSet;
  m_layout->addLookup(ligature);

  LigatureSubtable* ligaturesubtable = new LigatureSubtable(ligature);
  ligature->subtables.append(ligaturesubtable);
  ligaturesubtable->name = asStdString(ligature->name);

  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["hamzaabove"].charcode, {(std::uint16_t)glyphs["hamzaabove"].charcode, 0x200D}});
  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["hamzaabove.joined"].charcode, {0x200D, (std::uint16_t)glyphs["hamzaabove"].charcode}});
  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["hamzaabove.joined"].charcode, {(std::uint16_t)glyphs["tatweel"].charcode, (std::uint16_t)glyphs["hamzaabove"].charcode}});
  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["smallhighyeh"].charcode, {0x200D, (std::uint16_t)glyphs["smallhighyeh"].charcode}});
  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["smallhighyeh"].charcode, {(std::uint16_t)glyphs["tatweel"].charcode, (std::uint16_t)glyphs["smallhighyeh"].charcode}});
  // ligaturesubtable->ligatures.push_back({ (std::uint16_t)glyphs["smallhighwaw"].charcode,{ 0x200D,(std::uint16_t)glyphs["smallhighwaw"].charcode } });
  // ligaturesubtable->ligatures.push_back({ (std::uint16_t)glyphs["smallhighwaw"].charcode,{ (std::uint16_t)glyphs["tatweel"].charcode,(std::uint16_t)glyphs["smallhighwaw"].charcode } });

  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["smallhighnoon"].charcode, {0x200D, (std::uint16_t)glyphs["smallhighnoon"].charcode}});
  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["smallhighnoon"].charcode, {(std::uint16_t)glyphs["tatweel"].charcode, (std::uint16_t)glyphs["smallhighnoon"].charcode}});

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "forhamza";
  lookup->feature = "rlig";
  lookup->type = Lookup::chainingsub;
  lookup->markGlyphSetIndex = m_layout->addMarkSet({//(std::uint16_t)glyphs["smallhighwaw"].charcode,
                                                    (std::uint16_t)glyphs["hamzaabove"].charcode,
                                                    (std::uint16_t)glyphs["smallhighyeh"].charcode,
                                                    (std::uint16_t)glyphs["smallhighnoon"].charcode,
                                                    (std::uint16_t)glyphs["roundedfilledhigh"].charcode});
  lookup->flags = lookup->flags | Lookup::Flags::UseMarkFilteringSet;
  // lookup->flags = lookup->flags | Lookup::Flags::IgnoreMarks;

  ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "forhamza";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  auto keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.input.push_back({0x200D, (std::uint16_t)glyphs["tatweel"].charcode});
  newsubtable->compiledRule.input.push_back({(std::uint16_t)glyphs["hamzaabove"].charcode, (std::uint16_t)glyphs["smallhighyeh"].charcode, (std::uint16_t)glyphs["smallhighnoon"].charcode});

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});
  newsubtable->compiledRule.lookupRecords.push_back({1, "l2"});

  // roundedfilledhigh
  newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "roundedfilledhigh";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.input.push_back(std::unordered_set{
      (std::uint16_t)glyphs["roundedfilledhigh"].charcode,
  });

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});

  return lookup;
}
Lookup* OldMadina::shrinkstretchlt() {
  Lookup* lookup;
  int count = 1;
  for (float i = -0.1; i >= -0.7; i = i - 0.1) {
    lookup = shrinkstretchlt(i, QString("shr%1").arg(count));
    m_layout->addLookup(lookup);
    count++;
  }

  return nullptr;
}
Lookup* OldMadina::shrinkstretchlt(float lt, QString featureName) {
  // m_layout->addLookup(forwaw(), false);

  QString lookupName;

  if (lt < 0) {
    lookupName = QString("minuslt_%1").arg(lt * -100);
  } else {
    lookupName = QString("pluslt_%1").arg(lt * -100);
  }

  Lookup* single = new Lookup(m_layout);
  single->name = lookupName + ".l1";
  single->feature = "";
  single->type = Lookup::single;

  m_layout->addLookup(single);

  SingleSubtable* singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  for (auto& glyph : glyphs) {
    // QRegularExpression reg2("beginchar\\((.*?),(.*?),(.*?),(.*?)\\);");
    QRegularExpression regname("(.*)[.](minuslt|pluslt)_(.*)");
    QRegularExpressionMatch match = regname.match(QString::fromStdString(glyph.name));
    if (match.hasMatch()) {
      QString name = match.captured(1);
      QString plusminus = match.captured(2);
      int value = match.captured(3).toInt();
    } else if (classes["haslefttatweel"].contains(glyph.name)) {
      if (lt < 0) {
        QString destName = QStringLiteral("%1.minuslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)(lt * -100));
        if (glyphs.contains(destName)) {
          singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
        }
      } else {
        QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)(lt * 100));
        if (glyphs.contains(destName)) {
          singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
        }
      }
    }
    /*
                if (match.hasMatch()) {
                        int w1 = match.captured(1).toInt();
                        double w2 = match.captured(2).toDouble();

                if (classes["haslefttatweel"].contains(glyph.name)) {
                        QString destName = QStringLiteral("%1.minuslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)(lt * 100));
                        if (glyphs.contains(destName)) {
                                singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
                        }
                }
                else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
                        QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt - shrink) * 100));
                        if (glyphs.contains(destName)) {
                                singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
                        }
                }*/
  }

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = lookupName;
  lookup->feature = featureName;
  lookup->type = Lookup::chainingsub;
  lookup->flags = 0;

  ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = asStdString(lookupName);

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  auto keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});

  return lookup;
}
Lookup* OldMadina::forsmallhighwaw() {
  Lookup* single = new Lookup(m_layout);
  single->name = "forsmallhighwaw.l1";
  single->feature = "";
  single->type = Lookup::single;

  m_layout->addLookup(single);

  float tatweel = 1;

  SingleSubtable* singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  for (auto& glyph : glyphs) {
    if (classes["haslefttatweel"].contains(glyph.name)) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    } else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    }
  }

  // ligature
  Lookup* ligature = new Lookup(m_layout);
  ligature->name = "forsmallhighwaw.l2";
  ligature->feature = "";
  ligature->type = Lookup::ligature;
  m_layout->addLookup(ligature);

  LigatureSubtable* ligaturesubtable = new LigatureSubtable(ligature);
  ligature->subtables.append(ligaturesubtable);
  ligaturesubtable->name = asStdString(ligature->name);

  ligaturesubtable->ligatures.push_back({(std::uint16_t)glyphs["smallhighwaw"].charcode, {0x034F, (std::uint16_t)glyphs["smallhighwaw"].charcode}});

  // main lookup
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "forsmallhighwaw";
  lookup->feature = "rlig";
  lookup->type = Lookup::chainingsub;
  lookup->markGlyphSetIndex = m_layout->addMarkSet(QList{(std::uint16_t)glyphs["smallhighwaw"].charcode});
  lookup->flags = lookup->flags | Lookup::Flags::UseMarkFilteringSet;

  // forsmallalefwithmaddah
  ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "subtable1";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  auto keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }
  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)0x034F});
  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["smallhighwaw"].charcode});

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});
  newsubtable->compiledRule.lookupRecords.push_back({1, "l2"});

  return lookup;
}
Lookup* OldMadina::forsmalllalef() {
  Lookup* single = new Lookup(m_layout);
  single->name = "forsmallalef.l1";
  single->feature = "";
  single->type = Lookup::single;

  m_layout->addLookup(single);

  float tatweel = 1;

  SingleSubtable* singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  for (auto& glyph : glyphs) {
    if (classes["haslefttatweel"].contains(glyph.name)) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    } else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    }
  }

  singlesubtable->subst[glyphs["smallalef"].charcode] = glyphs["smallalef.joined"].charcode;

  // followed by maddahabove
  single = new Lookup(m_layout);
  single->name = "forsmallalef.l2";
  single->feature = "";
  single->type = Lookup::single;

  m_layout->addLookup(single);

  tatweel = 2;

  singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  for (auto& glyph : glyphs) {
    if (classes["haslefttatweel"].contains(glyph.name)) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    } else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    }
  }

  // main lookup
  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "forsmallalef";
  lookup->feature = "rlig";
  lookup->type = Lookup::chainingsub;
  lookup->flags = 0;
  lookup->markGlyphSetIndex = m_layout->addMarkSet({(std::uint16_t)glyphs["smallalef"].charcode, (std::uint16_t)glyphs["maddahabove"].charcode});
  lookup->flags = lookup->flags | Lookup::Flags::UseMarkFilteringSet;

  // forsmallalefwithmaddah
  ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "forsmallalefwithmaddah";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  auto keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["smallalef"].charcode});
  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["maddahabove"].charcode});

  newsubtable->compiledRule.lookupRecords.push_back({0, "l2"});
  newsubtable->compiledRule.lookupRecords.push_back({1, "l1"});

  // forsmallalef
  newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "forsmallalef";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["smallalef"].charcode});

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});
  newsubtable->compiledRule.lookupRecords.push_back({1, "l1"});

  // forsmallalef
  newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "forsmallalef";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["maddahabove"].charcode});
  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["smallalef"].charcode});

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});
  newsubtable->compiledRule.lookupRecords.push_back({2, "l1"});

  return lookup;
}

Lookup* OldMadina::forwaw() {
  Lookup* single = new Lookup(m_layout);
  single->name = "forwaw.l1";
  single->feature = "";
  single->type = Lookup::single;

  m_layout->addLookup(single);

  SingleSubtable* singlesubtable = new SingleSubtable(single);
  single->subtables.append(singlesubtable);
  singlesubtable->name = asStdString(single->name);

  float tatweel = 1;

  for (auto& glyph : glyphs) {
    if (classes["haslefttatweel"].contains(glyph.name)) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.name)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    } else if (classes["haslefttatweel"].contains(glyph.originalglyph) && glyph.name.find("pluslt") != std::string::npos) {
      QString destName = QStringLiteral("%1.pluslt_%2").arg(QString::fromStdString(glyph.originalglyph)).arg((int)((glyph.charlt + tatweel) * 100));
      if (glyphs.contains(destName)) {
        singlesubtable->subst[glyphs[QString::fromStdString(glyph.name)].charcode] = glyphs[destName].charcode;
      }
    }
  }

  Lookup* lookup = new Lookup(m_layout);
  lookup->name = "forwaw";
  lookup->feature = "rlig";
  lookup->type = Lookup::chainingsub;
  lookup->flags = 0;
  // lookup->markGlyphSetIndex = m_layout->addMarkSet({ (std::uint16_t)glyphs["smallalef"].charcode });
  // lookup->flags = lookup->flags | Lookup::Flags::UseMarkFilteringSet;
  lookup->flags = lookup->flags | Lookup::Flags::IgnoreMarks;

  ChainingSubtable* newsubtable = new ChainingSubtable(lookup);
  lookup->subtables.append(newsubtable);

  newsubtable->name = "forwaw";

  newsubtable->compiledRule = ChainingSubtable::CompiledRule();

  // newsubtable->compiledRule.input.push_back(stdMapKeys(singlesubtable->subst).toSet());
  auto keys = stdMapKeys(singlesubtable->subst);
  if (!keys.empty()) {
    newsubtable->compiledRule.input.push_back(std::unordered_set(keys.begin(), keys.end()));
  }

  newsubtable->compiledRule.input.push_back(std::unordered_set{(std::uint16_t)glyphs["waw.fina"].charcode});

  newsubtable->compiledRule.lookupRecords.push_back({0, "l1"});

  return lookup;
}

Lookup* OldMadina::populatecvxx() {
  int cvNumber = 1;

  for (auto& alternates : cvxxfeatures) {
    Lookup* alternate = new Lookup(m_layout);
    alternate->name = QString("cv%1").arg(cvNumber, 2, 10, QLatin1Char('0'));
    alternate->feature = alternate->name;
    alternate->type = Lookup::alternate;

    m_layout->addLookup(alternate);

    AlternateSubtable* alternateSubtable = new AlternateSubtable(alternate);
    alternate->subtables.append(alternateSubtable);
    alternate->name = alternate->name;

    alternateSubtable->alternates = alternates;

    cvNumber++;
  }

  return nullptr;
}

Lookup* OldMadina::glyphalternates() {
  bool isExtended = m_layout->isExtended();

  struct AltFeature {
    struct Subst {
      std::string glyph;
      std::string substitute;
    };
    std::string featureName;
    std::vector<Subst> alternates;
  };

  std::vector<AltFeature> altfeatures;

  altfeatures.push_back({"cv10", {{"behshape.medi", "behshape.medi.expa"}}});
  altfeatures.push_back({"cv11", {{"heh.init.beforemeem", "heh.init"}, {"meem.fina.afterheh", "meem.fina"}}});
  altfeatures.push_back({"cv12", {{"behshape.init.beforehah", "behshape.init"}, {"hah.medi.afterbeh", "hah.medi"}, {"hah.medi.afterbeh.beforeyeh", "hah.medi.beforeyeh"}}});
  altfeatures.push_back({"cv13", {{"meem.init.beforehah", "meem.init"}, {"hah.medi.aftermeem", "hah.medi"}}});
  altfeatures.push_back({"cv14", {{"fehshape.init.beforehah", "fehshape.init"}, {"hah.medi.afterfeh", "hah.medi"}}});
  altfeatures.push_back({"cv15", {{"lam.init.lam_hah", "lam.init"}, {"hah.medi.lam_hah", "hah.medi"}}});
  altfeatures.push_back({"cv16", {{"hah.init.ii", "hah.init"}, {"hah.medi.ii", "hah.medi"}, {"ain.init.finjani", "ain.init"}}});
  altfeatures.push_back({"cv17", {{"seen.init.beforereh", "seen.init"}, {"seen.medi.beforereh", "seen.medi"}, {"reh.fina.afterseen", "reh.fina"}, {"sad.medi.beforereh", "sad.medi"}, {"sad.init.beforereh", "sad.init"}}});
  altfeatures.push_back({"cv18", {{"hah.init.beforemeem", "hah.init"}, {"meem.medi.afterhah", "meem.medi"}}});
  altfeatures.push_back({"cv19", {{"lam.init.beforedal", "lam.init"}, {"dal.fina.afterlam", "dal.fina"}}});
  // altfeatures.push_back({"cv20", {{"kaf.init.beforelam", "kaf.init.ii"}, {"kaf.init.beforelam.ii", "kaf.init.ii"}, {"kaf.medi.beforelam", "kaf.medi.ii"}, {"kaf.medi.beforelam.ii", "kaf.medi.ii"}}});

  for (auto& feature : altfeatures) {
    Lookup* alternate = new Lookup(m_layout);
    alternate->name = QString::fromStdString(feature.featureName);
    alternate->feature = alternate->name;
    alternate->type = Lookup::alternate;

    m_layout->addLookup(alternate);

    AlternateSubtableWithTatweel* alternateSubtable = new AlternateSubtableWithTatweel(alternate);
    alternate->subtables.append(alternateSubtable);
    alternate->name = alternate->name;

    for (auto mapping : feature.alternates) {
      std::vector<ExtendedGlyph> alternates;
      const auto glyphName = QString::fromStdString(mapping.glyph);
      const auto substituteName = QString::fromStdString(mapping.substitute);
      int code = m_layout->glyphCodePerName[glyphName];
      int substcode = m_layout->glyphCodePerName[substituteName];
      auto& valueLimits = m_layout->expandableGlyphs[glyphName];

      if (code == 0 || substcode == 0) {
        throw new std::runtime_error("Glyph name invalid");
      }
      alternates.push_back({substcode, 0, 0});
      alternateSubtable->alternates[code] = alternates;

      for (double leftTatweel = 0.5; leftTatweel <= std::min(valueLimits.maxLeft, 6.0); leftTatweel += 0.5) {
        GlyphParameters parameters;
        parameters.lefttatweel = leftTatweel;
        parameters.righttatweel = 0.0;
        GlyphVis* newglyph = m_layout->getAlternate(code, parameters, !isExtended, !isExtended);
        if (newglyph != nullptr) {
          std::vector<ExtendedGlyph> alternates2;
          alternates2.push_back({substcode, leftTatweel, 0});
          alternateSubtable->alternates[newglyph->charcode] = alternates2;
        }
      }
    }
  }

  // decomp
  std::unordered_map<QString, QString> mappingsdecomp;

  mappingsdecomp.insert({"behshape.medi", "behshape.medi.expa"});

  mappingsdecomp.insert({"heh.init.beforemeem", "heh.init"});
  mappingsdecomp.insert({"meem.fina.afterheh", "meem.fina"});

  mappingsdecomp.insert({"behshape.init.beforehah", "behshape.init"});
  mappingsdecomp.insert({"hah.medi.afterbeh", "hah.medi"});

  mappingsdecomp.insert({"meem.init.beforehah", "meem.init"});
  mappingsdecomp.insert({"hah.medi.aftermeem", "hah.medi"});

  mappingsdecomp.insert({"fehshape.init.beforehah", "fehshape.init"});
  mappingsdecomp.insert({"hah.medi.afterfeh", "hah.medi"});
  mappingsdecomp.insert({"hah.medi.afterbeh.beforeyeh", "hah.medi"});

  mappingsdecomp.insert({"lam.init.lam_hah", "lam.init"});
  mappingsdecomp.insert({"hah.medi.lam_hah", "hah.medi"});

  mappingsdecomp.insert({"hah.init.ii", "hah.init"});
  mappingsdecomp.insert({"hah.medi.ii", "hah.medi"});

  mappingsdecomp.insert({"seen.init.beforereh", "seen.init"});
  mappingsdecomp.insert({"reh.fina.afterseen", "reh.fina"});

  mappingsdecomp.insert({"hah.init.beforemeem", "hah.init"});
  mappingsdecomp.insert({"meem.medi.afterhah", "meem.medi"});
  mappingsdecomp.insert({"sad.medi.beforereh", "sad.medi"});
  mappingsdecomp.insert({"sad.init.beforereh", "sad.init"});

  mappingsdecomp.insert({"ain.init.finjani", "ain.init"});

  // kafs
  mappingsdecomp.insert({"kaf.init.beforelam", "kaf.init.ii"});
  mappingsdecomp.insert({"kaf.init.beforelam.ii", "kaf.init.ii"});
  mappingsdecomp.insert({"kaf.medi.beforelam", "kaf.medi.ii"});
  mappingsdecomp.insert({"kaf.medi.beforelam.ii", "kaf.medi.ii"});
  mappingsdecomp.insert({"lam.fina.afterkaf", "lam.fina"});
  mappingsdecomp.insert({"lam.medi.afterkaf", "lam.medi"});
  mappingsdecomp.insert({"alef.fina.afterkaf", "alef.fina"});
  mappingsdecomp.insert({"kaf.init", "kaf.init.ii"});
  mappingsdecomp.insert({"kaf.init.iii", "kaf.init.ii"});
  mappingsdecomp.insert({"kaf.init.short", "kaf.init.ii"});
  mappingsdecomp.insert({"kaf.medi", "kaf.medi.ii"});
  mappingsdecomp.insert({"kaf.medi.beforemeem", "kaf.medi.ii"});
  mappingsdecomp.insert({"meem.fina.afterkaf", "meem.fina"});

  Lookup* alternate = new Lookup(m_layout);
  alternate->name = "cv03";
  alternate->feature = alternate->name;
  alternate->type = Lookup::alternate;

  m_layout->addLookup(alternate);

  AlternateSubtableWithTatweel* alternateSubtable = new AlternateSubtableWithTatweel(alternate);
  alternate->subtables.append(alternateSubtable);
  alternate->name = alternate->name;

  for (auto mapping : mappingsdecomp) {
    std::vector<ExtendedGlyph> alternates;
    int code = m_layout->glyphCodePerName[mapping.first];
    int substcode = m_layout->glyphCodePerName[mapping.second];
    auto& valueLimits = m_layout->expandableGlyphs[mapping.first];

    if (code == 0 || substcode == 0) {
      throw new std::runtime_error("Glyph name invalid");
    }
    alternates.push_back({substcode, 0, 0});
    alternateSubtable->alternates[code] = alternates;

    for (double leftTatweel = 0.5; leftTatweel <= std::min(valueLimits.maxLeft, 6.0); leftTatweel += 0.5) {
      GlyphParameters parameters;
      parameters.lefttatweel = leftTatweel;
      parameters.righttatweel = 0.0;
      GlyphVis* newglyph = m_layout->getAlternate(code, parameters, !isExtended, !isExtended);
      if (newglyph != nullptr) {
        std::vector<ExtendedGlyph> alternates2;
        alternates2.push_back({substcode, leftTatweel, 0});
        alternateSubtable->alternates[newglyph->charcode] = alternates2;
      }
    }
  }

  int cvNumber = 1;

  // cv01
  alternate = new Lookup(m_layout);
  // alternate->name = QString("cv%1").arg(cvNumber++, 2, 10, QLatin1Char('0'));
  alternate->name = "cv01";
  alternate->feature = alternate->name;
  alternate->type = Lookup::alternate;

  m_layout->addLookup(alternate);

  alternateSubtable = new AlternateSubtableWithTatweel(alternate);
  alternate->subtables.append(alternateSubtable);
  alternateSubtable->name = asStdString(alternate->name);

  std::unordered_map<QString, QString> mappings;

  mappings.insert({"noon.isol", "noon.isol.expa"});
  mappings.insert({"behshape.isol", "behshape.isol.expa"});
  mappings.insert({"feh.isol", "feh.isol.expa"});
  mappings.insert({"qaf.isol", "qaf.isol.expa"});
  mappings.insert({"seen.isol", "seen.isol.expa"});
  mappings.insert({"sad.isol", "sad.isol.expa"});
  mappings.insert({"yehshape.isol", "yehshape.isol.expa"});
  mappings.insert({"alefmaksura.isol", "alefmaksura.isol.expa"});

  mappings.insert({"noon.fina", "noon.fina.expa"});
  mappings.insert({"noon.fina.afterbeh", "noon.fina.expa.afterbeh"});
  mappings.insert({"kaf.fina", "kaf.fina.expa"});
  mappings.insert({"kaf.fina.afterlam", "kaf.fina.afterlam.expa"});
  mappings.insert({"behshape.fina", "behshape.fina.expa"});
  mappings.insert({"feh.fina", "feh.fina.expa"});
  mappings.insert({"qaf.fina", "qaf.fina.expa"});
  mappings.insert({"seen.fina", "seen.fina.expa"});
  mappings.insert({"sad.fina", "sad.fina.expa"});
  mappings.insert({"alef.fina", "alef.fina"});
  mappings.insert({"yehshape.fina", "yehshape.fina.expa"});
  mappings.insert({"yehshape.fina.ii", "yehshape.fina.ii.expa"});
  mappings.insert({"yehshape.fina.afterbeh", "yehshape.fina.afterbeh.expa"});

  for (auto mapping : mappings) {
    std::vector<ExtendedGlyph> alternates;
    int code = m_layout->glyphCodePerName[mapping.first];
    int substcode = m_layout->glyphCodePerName[mapping.second];

    if (code == 0 || substcode == 0) {
      throw new std::runtime_error("Glyph name invalid");
    }
    alternates.push_back({substcode, 0, 0});
    alternates.push_back({substcode, 1, 0});
    alternates.push_back({substcode, 2, 0});
    alternates.push_back({substcode, 3, 0});
    alternates.push_back({substcode, 4, 0});
    alternates.push_back({substcode, 5, 0});
    alternates.push_back({substcode, 6, 0});
    alternates.push_back({substcode, 7, 0});
    alternates.push_back({substcode, 8, 0});
    alternates.push_back({substcode, 9, 0});
    alternates.push_back({substcode, 10, 0});
    alternates.push_back({substcode, 11, 0});
    alternateSubtable->alternates[code] = alternates;
  }

  std::unordered_map<QString, QString> mappingLigaRightOnlys;

  mappingLigaRightOnlys.insert({"ain.init.finjani", "ain.init"});
  mappingLigaRightOnlys.insert({"hah.init.ii", "hah.init"});
  mappingLigaRightOnlys.insert({"hah.medi.ii", "hah.medi"});
  mappingLigaRightOnlys.insert({"behshape.init.beforereh", "behshape.init"});

  for (auto mapping : mappingLigaRightOnlys) {
    std::vector<ExtendedGlyph> alternates;
    int code = m_layout->glyphCodePerName[mapping.first];
    int substcode = m_layout->glyphCodePerName[mapping.second];

    if (code == 0 || substcode == 0) {
      throw new std::runtime_error("Glyph name invalid");
    }
    alternates.push_back({substcode, 1, 0});
    alternates.push_back({substcode, 2, 0});
    alternates.push_back({substcode, 3, 0});
    alternates.push_back({substcode, 4, 0});
    alternates.push_back({substcode, 5, 0});
    alternates.push_back({substcode, 6, 0});
    alternateSubtable->alternates[code] = alternates;
  }

  // behshape.medi
  auto& valueLimits = m_layout->expandableGlyphs["behshape.medi"];
  auto glyphCode = m_layout->glyphCodePerName["behshape.medi"];
  int substcode = m_layout->glyphCodePerName["behshape.medi.expa"];

  for (double leftTatweel = 0.5; leftTatweel <= std::min(valueLimits.maxLeft, 3.0); leftTatweel += 0.5) {
    std::vector<ExtendedGlyph> alternates;
    GlyphParameters parameters;
    parameters.lefttatweel = leftTatweel;
    parameters.righttatweel = 0.0;
    GlyphVis* newglyph = m_layout->getAlternate(glyphCode, parameters, !isExtended, !isExtended);
    for (double leftTatweel2 = leftTatweel + 1; leftTatweel2 <= std::min(valueLimits.maxLeft, 6.0); leftTatweel2 += 1) {
      alternates.push_back({substcode, leftTatweel2, 0});
    }
    alternateSubtable->alternates[newglyph->charcode] = alternates;
  }

  for (auto& glyph : m_layout->expandableGlyphs) {
    if (!m_layout->glyphCodePerName.contains(glyph.first)) continue;

    if (mappings.find(glyph.first) != mappings.end()) continue;

    if (glyph.first == "kasra") continue;

    auto glyphCode = m_layout->glyphCodePerName[glyph.first];
    auto valueLimits = glyph.second;

    if (valueLimits.maxLeft > 0) {
      for (double leftTatweel = 0; leftTatweel <= std::min(valueLimits.maxLeft, 3.0); leftTatweel += 0.5) {
        std::vector<ExtendedGlyph> alternates;
        GlyphParameters parameters;
        parameters.lefttatweel = leftTatweel;
        parameters.righttatweel = 0.0;
        GlyphVis* newglyph = m_layout->getAlternate(glyphCode, parameters, !isExtended, !isExtended);
        auto newCode = newglyph->charcode;
        if (leftTatweel == 0) {
          newCode = glyphCode;
        }
        auto leftTatweel2 = leftTatweel;
        for (int i = 1; i <= 6; i++) {
          leftTatweel2++;
          if (leftTatweel2 > 6) {
            leftTatweel2 = 6;
          }
          alternates.push_back({glyphCode, leftTatweel2, 0});
        }
        /*
        for (double leftTatweel2 = leftTatweel + 1; leftTatweel2 <= std::min(valueLimits.maxLeft, 6.0F); leftTatweel2 += 1) {
          alternates.push_back({ glyphCode,leftTatweel2,0 });
        }*/
        alternateSubtable->alternates[newCode] = alternates;
      }
    }
  }

  alternate = new Lookup(m_layout);
  // alternate->name = QString("cv%1").arg(cvNumber++, 2, 10, QLatin1Char('0'));
  alternate->name = "cv02";
  alternate->feature = alternate->name;
  alternate->type = Lookup::alternate;

  // m_layout->addLookup(alternate);

  alternateSubtable = new AlternateSubtableWithTatweel(alternate);
  alternate->subtables.append(alternateSubtable);
  alternate->name = alternate->name;

  for (auto& glyph : m_layout->expandableGlyphs) {
    if (!m_layout->glyphCodePerName.contains(glyph.first)) continue;
    auto glyphCode = m_layout->glyphCodePerName[glyph.first];
    auto valueLimits = glyph.second;

    if (valueLimits.maxRight > 0) {
      std::vector<ExtendedGlyph> alternates;
      for (double righttatweel = 0.5; righttatweel <= std::min(valueLimits.maxRight, 6.0); righttatweel += 0.5) {
        alternates.push_back({glyphCode, 0, righttatweel});
      }
      alternateSubtable->alternates[glyphCode] = alternates;

      if (valueLimits.maxLeft > 0) {
        for (double leftTatweel = 0.5; leftTatweel <= std::min(valueLimits.maxLeft, 6.0); leftTatweel += 0.5) {
          std::vector<ExtendedGlyph> alternates;
          GlyphParameters parameters;
          parameters.lefttatweel = leftTatweel;
          parameters.righttatweel = 0.0;
          GlyphVis* newglyph = m_layout->getAlternate(glyphCode, parameters, !isExtended, !isExtended);
          for (double righttatweel = 0.5; righttatweel <= std::min(valueLimits.maxRight, 6.0); righttatweel += 0.5) {
            alternates.push_back({glyphCode, leftTatweel, righttatweel});
          }
          alternateSubtable->alternates[newglyph->charcode] = alternates;
        }
      }
    };
  }

  // for shrinking
  /*alternate = new Lookup(m_layout);
  alternate->name = "cv04";
  alternate->feature = alternate->name;
  alternate->type = Lookup::alternate;

  // m_layout->addLookup(alternate);

  alternateSubtable = new AlternateSubtableWithTatweel(alternate);
  alternate->subtables.append(alternateSubtable);
  alternateSubtable->name = asStdString(alternate->name);
  for (auto& glyph : m_layout->expandableGlyphs) {
    if (!m_layout->glyphCodePerName.contains(glyph.first)) continue;
    auto glyphCode = m_layout->glyphCodePerName[glyph.first];
    auto valueLimits = glyph.second;

    std::vector<ExtendedGlyph> alternates;

    for (double tatweel = -0.1; tatweel >= -0.5; tatweel += -0.1) {
      alternates.push_back({glyphCode, std::max(tatweel, valueLimits.minLeft), std::max(tatweel, valueLimits.minRight)});
    }
    if (alternates.size() > 0) {
      alternateSubtable->alternates[glyphCode] = alternates;
    }
  }*/

  return alternate;
}
