#include "ingame.h"

#include "../helpers/globals.h"

namespace features {
	void setSensitivity(int sensitivity) {
		// Instantly applies sensitivity
		static auto applySensitivityFn = (int(__cdecl*)(int))((uintptr_t)globals::qpangModule + 0x287c0);
		applySensitivityFn(sensitivity);
	}
}