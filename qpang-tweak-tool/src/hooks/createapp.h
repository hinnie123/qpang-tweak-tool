#pragma once

#include "helpers/globals.h"

namespace hooks {
	typedef bool(__thiscall* tCreateApp)(void*, HINSTANCE, int);
	inline tCreateApp oCreateApp = nullptr;

	bool __fastcall hkCreateApp(void* _this, void*, HINSTANCE instance, int unknownArg) {
		// Force target width and height when creating the window
		*(int*)((uintptr_t)_this + 0x14) = globals::targetWidth;
		*(int*)((uintptr_t)_this + 0x18) = globals::targetHeight;

		return oCreateApp(_this, instance, unknownArg);
	}
}