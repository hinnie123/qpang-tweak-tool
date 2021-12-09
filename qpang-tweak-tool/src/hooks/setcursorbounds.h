#pragma once

#include "helpers/globals.h"

namespace hooks {
	typedef int(__thiscall* tSetCursorBounds)(void*, int, int);
	inline tSetCursorBounds oSetCursorBounds = nullptr;

	int __fastcall hkSetCursorBounds(void* _this, void*, int width, int height) {
		// Original function doesn't really do anything interesting, we don't need to call it.

		*(int*)((uintptr_t)_this + 0x38c) = globals::targetWidth;
		*(int*)((uintptr_t)_this + 0x390) = globals::targetHeight;

		return width;
	}
}