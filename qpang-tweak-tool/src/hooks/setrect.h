#pragma once

#include <intrin.h>

#include "helpers/globals.h"

namespace hooks {
	typedef BOOL(__stdcall* tSetRect)(LPRECT, int, int, int, int);
	inline tSetRect oSetRect = nullptr;

	BOOL __stdcall hkSetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom) {
		uintptr_t returnAddress = (uintptr_t)_ReturnAddress();
		if (returnAddress > (uintptr_t)globals::qpangModule + 0x1abc50 && returnAddress < (uintptr_t)globals::qpangModule + 0x1abede) {
			// NOTE: This has to be the resolution of the loading screen background!
			return oSetRect(lprc, xLeft, yTop, 3840, 2160);
		}

		return oSetRect(lprc, xLeft, yTop, xRight, yBottom);
	}
}