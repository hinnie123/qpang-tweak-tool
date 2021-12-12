#include "resolution.h"

#include "../helpers/globals.h"

namespace features {
	void fixCursorBounds(void* unknownPointer) {
		*(int*)((uintptr_t)unknownPointer + 0x38c) = features::targetWidth;
		*(int*)((uintptr_t)unknownPointer + 0x390) = features::targetHeight;
	}

	void fixWorldToScreen(void* unknownPointer) {
		*(int*)((uintptr_t)unknownPointer + 0x218) = features::targetWidth;
		*(int*)((uintptr_t)unknownPointer + 0x21c) = features::targetHeight;
	}

	void fixResolution(void* unknownPointer) {
		uintptr_t v6 = *(uintptr_t*)((uintptr_t)unknownPointer + 0x5c);
		if (v6) {
			uintptr_t d3dRenderSystemInstance = *(uintptr_t*)((uintptr_t)v6 + 0x1ac);
			uintptr_t v8 = *(uintptr_t*)(v6 + 0x1a4);

			if (d3dRenderSystemInstance && v8) {
				(*(void(__thiscall**)(int, int, int))(*(uintptr_t*)v8 + 0x6c))(v8, features::targetWidth, features::targetHeight);

				static auto resetDeviceFn = (void(__thiscall*)(void*))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?ResetDevice@D3DRenderSystem@OnNet3D@@QAEXXZ"));
				resetDeviceFn((void*)d3dRenderSystemInstance);
			}
		}
	}

	void fixStretch() {
		*(int*)((uintptr_t)globals::qpangModule + 0x3c0f14) = features::targetWidth;
		*(int*)((uintptr_t)globals::qpangModule + 0x3c0f18) = features::targetHeight;
	}

	bool isTargettingQuitMessage = false;
	void beforeFixQuitMessage(wchar_t* message) {
		if (wcsstr(message, L"quit?") || wcsstr(message, L"verlaten?") || wcsstr(message, L"tutorial?") || wcsstr(message, L"training")) {
			isTargettingQuitMessage = true;
		}
	}

	void fixQuitMessage(float* pos) {
		if (isTargettingQuitMessage) {
			pos[0] = features::targetWidth / 2;
			pos[1] = features::targetHeight / 2;
			isTargettingQuitMessage = false;
		}
	}
}