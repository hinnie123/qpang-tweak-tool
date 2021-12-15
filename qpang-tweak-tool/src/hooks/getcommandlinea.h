#pragma once

#include "features/resolution.h"

namespace hooks {
	typedef char* (__stdcall* tGetCommandLineA)();
	inline tGetCommandLineA oGetCommandLineA = nullptr;

	char* __stdcall hkGetCommandLineA() {
		return features::fixCmdLineA();
	}
}