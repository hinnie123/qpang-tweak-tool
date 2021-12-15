#pragma once

#include "render/ui.h"

namespace hooks {
	typedef HWND(__stdcall* tGetFocus)();
	inline tGetFocus oGetFocus = nullptr;

	HWND __stdcall hkGetFocus() {
		// This blocks all input to QPang when the menu is being drawn
		if (ui::renderWindow) {
			return 0;
		}

		return oGetFocus();
	}
}