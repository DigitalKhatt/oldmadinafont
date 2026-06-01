
#include "shared.h"

__declspec(dllexport) Automedina* font_create(OtLayout* layout, Font* font, bool extended) {
    try {
        return new OldMadina(layout, font, extended);
    }
    catch (...) {
        return nullptr;
    };
}