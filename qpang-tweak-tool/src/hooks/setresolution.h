#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef bool(__thiscall* tSetResolution)(void*, int);
	inline tSetResolution oSetResolution = nullptr;

	bool __fastcall hkSetResolution(void* _this, void*, int resolutionIndex) {
		bool retVal = oSetResolution(_this, resolutionIndex);
		features::fixResolution(_this);
		return retVal;
	}
}