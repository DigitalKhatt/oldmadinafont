#pragma once

#include "oldmadina.h"

extern "C" __declspec(dllexport) Automedina* __stdcall font_create(OtLayout* layout, Font* font, bool extended);

extern "C" void __stdcall font_delete(OldMadina* p_obj) {
	try {
		delete p_obj;
	}
	catch (...) {};
};