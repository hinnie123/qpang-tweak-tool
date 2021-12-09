#pragma once

namespace hooks {
	typedef bool(__thiscall* tSetResolution)(void*, int);
	inline tSetResolution oSetResolution = nullptr;

	bool __fastcall hkSetResolution(void* _this, void*, int resolutionIndex) {
		bool retVal = oSetResolution(_this, resolutionIndex);

		uintptr_t v6 = *(uintptr_t*)((uintptr_t)_this + 0x5c);
		if (v6) {
			uintptr_t d3dRenderSystemInstance = *(uintptr_t*)((uintptr_t)v6 + 0x1ac);
			uintptr_t v8 = *(uintptr_t*)(v6 + 0x1a4);

			if (d3dRenderSystemInstance && v8) {
				(*(void(__thiscall**)(int, int, int))(*(uintptr_t*)v8 + 0x6c))(v8, globals::targetWidth, globals::targetHeight);

				static auto ResetDeviceFn = (void(__thiscall*)(void*))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?ResetDevice@D3DRenderSystem@OnNet3D@@QAEXXZ"));
				ResetDeviceFn((void*)d3dRenderSystemInstance);
			}
		}

		return retVal;
	}
}