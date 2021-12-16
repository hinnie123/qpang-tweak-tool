#include "ingame.h"

#include "../helpers/globals.h"

namespace features {
	void setSensitivity(int sensitivity) {
		static const auto applySensitivityFn = (int(__cdecl*)(int))((uintptr_t)globals::qpangModule + 0x287c0);
		applySensitivityFn(sensitivity);
	}

	void sensitivity() {
		if (sensitivityEnabled) {
			if (globals::currentUiState == eUIState::GAME) {
				setSensitivity((int)(sensitivityValue / 0.33333334));
			}
		}
	}

	void restoreSensitivity() {
		if (globals::currentUiState == eUIState::GAME) {
			// Sets the sensitivity to the games sensitivity if you turn of the override
			// whilst being in a match.
			setSensitivity(*(int*)((uintptr_t)globals::qpangModule + 0x3b3d10));
		}
	}
}