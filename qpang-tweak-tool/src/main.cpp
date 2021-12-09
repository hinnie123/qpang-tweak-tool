#include <Windows.h>
#include <d3d9.h>

#include "minhook/minhook.h"

#include "hooks/setcursorbounds.h"
#include "hooks/setresolution.h"
#include "hooks/setworldtoscreenresolution.h"

#include "hooks/luatinkerdofile.h"

#include "hooks/wndproc.h"
#include "hooks/endscene.h"
#include "hooks/reset.h"

void setupQpangHooks() {
	globals::qpangModule = GetModuleHandleA(nullptr);
	if (!globals::qpangModule)
		return;

	auto setWorldToScreenResolutionFn = (uintptr_t)globals::qpangModule + 0xbf2d0;
	auto setCursorBoundsFn = (uintptr_t)globals::qpangModule + 0x1e760;
	auto setResolutionFn = (uintptr_t)globals::qpangModule + 0xf6aa0;
	auto luaTinkerDoFileFn = (uintptr_t)globals::qpangModule + 0x1d8da0;

	MH_CreateHook((void*)setWorldToScreenResolutionFn, (void*)hooks::hkSetWorldToScreenResolution, (void**)&hooks::oSetWorldToScreenResolution);
	MH_CreateHook((void*)setCursorBoundsFn, (void*)hooks::hkSetCursorBounds, (void**)&hooks::oSetCursorBounds);
	MH_CreateHook((void*)setResolutionFn, (void*)hooks::hkSetResolution, (void**)&hooks::oSetResolution);

	MH_CreateHook((void*)luaTinkerDoFileFn, (void*)hooks::hkLuaTinkerDoFile, (void**)&hooks::oLuaTinkerDoFile);
}

void setupApiHooks() {
	HMODULE on3DModule = GetModuleHandleA("On3D.dll");
	if (!on3DModule)
		return;

	auto getOnnet3DEngine = (uintptr_t*(*)())(GetProcAddress(on3DModule, "?GetSingleton@?$Singleton@VOnNet3DEngine@OnNet3D@@@OnNet3D@@SAAAVOnNet3DEngine@2@XZ"));
	auto getOnnetRenderSystem = (uintptr_t*(*)(uintptr_t*))(GetProcAddress(on3DModule, "?GetRenderSystem@OnNet3DEngine@OnNet3D@@QAEPAVRenderSystem@2@XZ"));

	if (!getOnnet3DEngine || !getOnnetRenderSystem)
		return;

	auto onnet3DEngine = getOnnet3DEngine();
	globals::onnetRenderSystem = getOnnetRenderSystem(onnet3DEngine);
	auto onnet3DDevice = globals::onnetRenderSystem + 141;
	auto d3d9Device = *(IDirect3DDevice9**)(onnet3DDevice + 1);

	auto d3d9DeviceVtable = *(void***)d3d9Device;

	MH_CreateHook(d3d9DeviceVtable[42], (void*)hooks::hkEndscene, (void**)&hooks::oEndscene);
	MH_CreateHook(d3d9DeviceVtable[16], (void*)hooks::hkReset, (void**)&hooks::oReset);

	hooks::oWndProc = (WNDPROC)SetWindowLongPtrA(globals::qpangWindow, GWL_WNDPROC, (LONG_PTR)hooks::wndProc);
}

void setupHooks() {
	MH_Initialize();

	setupQpangHooks();
	setupApiHooks();

	MH_EnableHook(MH_ALL_HOOKS);
}

void init() {
	globals::qpangWindow = FindWindowA(0, "QPang");

	// Removes the 10 pixel offset of the window
	SetWindowPos(globals::qpangWindow, (HWND)-1, 0, 0, -1, -1, SWP_NOSIZE | SWP_NOZORDER);
}

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD fdwReason,
	_In_ LPVOID lpvReserved
) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		// Uncomment if you want to open a console that you can print to

		AllocConsole();
		AttachConsole(GetCurrentProcessId());
		freopen("CON", "w", stdout);

		init();
		setupHooks();
	}

	return 1;
}