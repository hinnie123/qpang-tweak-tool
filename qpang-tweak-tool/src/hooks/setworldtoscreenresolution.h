#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef int(__thiscall* tSetWorldToScreenResolution)(void*);
	inline tSetWorldToScreenResolution oSetWorldToScreenResolution = nullptr;

	int __fastcall hkSetWorldToScreenResolution(void* _this, void*) {
		int retVal = oSetWorldToScreenResolution(_this);
		features::fixWorldToScreen(_this);
		return retVal;
	}
}