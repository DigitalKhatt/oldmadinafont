#pragma once

#include "fontplugin.h"
#include "oldmadina.h"

extern "C" DIGITALKHATT_FONT_EXPORT Automedina* font_create(OtLayout* layout, MPFont* font, bool extended);

extern "C" void font_delete(OldMadina* p_obj) {
	try {
		delete p_obj;
	}
	catch (...) {};
};
