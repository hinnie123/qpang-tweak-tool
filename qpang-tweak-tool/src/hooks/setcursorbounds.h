#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef int(__thiscall* tSetCursorBounds)(void*, int, int);
	inline tSetCursorBounds oSetCursorBounds = nullptr;

	int __fastcall hkSetCursorBounds(void* _this, void*, int width, int height) {
		// Original function doesn't really do anything interesting, we don't need to call it.
		features::fixCursorBounds(_this);
		return width;
	}
}