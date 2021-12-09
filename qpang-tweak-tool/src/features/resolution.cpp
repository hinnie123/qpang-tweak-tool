#include "resolution.h"

#include <cstdint>
#include <libloaderapi.h>

#include "../helpers/globals.h"

namespace resolution {
	void fixCursorBounds(void* unknownPointer) {
		*(int*)((uintptr_t)unknownPointer + 0x38c) = globals::targetWidth;
		*(int*)((uintptr_t)unknownPointer + 0x390) = globals::targetHeight;
	}

	void fixWorldToScreen(void* unknownPointer) {
		*(int*)((uintptr_t)unknownPointer + 0x218) = globals::targetWidth;
		*(int*)((uintptr_t)unknownPointer + 0x21c) = globals::targetHeight;
	}

	void fixResolution(void* unknownPointer) {
		uintptr_t v6 = *(uintptr_t*)((uintptr_t)unknownPointer + 0x5c);
		if (v6) {
			uintptr_t d3dRenderSystemInstance = *(uintptr_t*)((uintptr_t)v6 + 0x1ac);
			uintptr_t v8 = *(uintptr_t*)(v6 + 0x1a4);

			if (d3dRenderSystemInstance && v8) {
				(*(void(__thiscall**)(int, int, int))(*(uintptr_t*)v8 + 0x6c))(v8, globals::targetWidth, globals::targetHeight);

				static auto resetDeviceFn = (void(__thiscall*)(void*))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?ResetDevice@D3DRenderSystem@OnNet3D@@QAEXXZ"));
				resetDeviceFn((void*)d3dRenderSystemInstance);
			}
		}
	}

	void fixStretch() {
		*(int*)((uintptr_t)globals::qpangModule + 0x3c0f14) = globals::targetWidth;
		*(int*)((uintptr_t)globals::qpangModule + 0x3c0f18) = globals::targetHeight;
	}
}