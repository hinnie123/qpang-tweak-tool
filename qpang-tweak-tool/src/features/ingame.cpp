#include "ingame.h"

#include "../helpers/globals.h"

namespace features {
	void setHighFov() {
#ifdef V2013
		void* fovPtr = (void*)0x7384f0;
#else
		void* fovPtr = (void*)0x7354e8;
#endif

		if (globals::currentUiState == eUIState::GAME) {
			float fov = *(float*)(fovPtr);
			float targetFov = higherFov ? 0.375 : 0.25;

			if (fov != targetFov) {
				DWORD oldProtection = 0;
				VirtualProtect((LPVOID)fovPtr, sizeof(wchar_t), PAGE_EXECUTE_READWRITE, &oldProtection);

				*(float*)(fovPtr) = targetFov;

				VirtualProtect((LPVOID)fovPtr, sizeof(wchar_t), oldProtection, &oldProtection);
			}
		}
	}

	void setSensitivity(int sensitivity) {
#ifdef V2013
		static const auto applySensitivityFn = (int(__cdecl*)(int))((uintptr_t)globals::qpangModule + 0x28ab0);
#else
		static const auto applySensitivityFn = (int(__cdecl*)(int))((uintptr_t)globals::qpangModule + 0x287c0);
#endif

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
#ifdef V2013
			setSensitivity(*(int*)((uintptr_t)globals::qpangModule + 0x3b6d10));
#else
			setSensitivity(*(int*)((uintptr_t)globals::qpangModule + 0x3b3d10));
#endif
		}
	}
}