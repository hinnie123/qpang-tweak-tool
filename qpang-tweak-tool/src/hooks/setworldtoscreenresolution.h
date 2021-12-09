#pragma once

#include "helpers/globals.h"

namespace hooks {
	typedef int(__thiscall* tSetWorldToScreenResolution)(void*);
	inline tSetWorldToScreenResolution oSetWorldToScreenResolution = nullptr;

	int __fastcall hkSetWorldToScreenResolution(void* _this, void*) {
		int retVal = oSetWorldToScreenResolution(_this);

		*(int*)((uintptr_t)_this + 0x218) = globals::targetWidth;
		*(int*)((uintptr_t)_this + 0x21c) = globals::targetHeight;

		return retVal;
	}
}