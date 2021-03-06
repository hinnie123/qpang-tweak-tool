#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef wchar_t* (__stdcall* tGetCommandLineW)();
	inline tGetCommandLineW oGetCommandLineW = nullptr;

	wchar_t* __stdcall hkGetCommandLineW() {
		return features::fixCmdLineW();
	}
}