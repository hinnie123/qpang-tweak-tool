#include <Windows.h>
#include <d3d9.h>

#include "minhook/minhook.h"

#include "hooks/createapp.h"
#include "hooks/rendermessage.h"
#include "hooks/setunknownposition.h"
#include "hooks/setcursorbounds.h"
#include "hooks/setresolution.h"
#include "hooks/setworldtoscreenresolution.h"
#include "hooks/luatinkerdofile.h"

#include "hooks/setrect.h"
#include "hooks/wndproc.h"
#include "hooks/getdevicedata.h"
#include "hooks/endscene.h"
#include "hooks/reset.h"

#include "helpers/settings.h"
#include "helpers/utils.h"

void setupQpangHooks() {
	globals::qpangModule = GetModuleHandleA(nullptr);
	if (!globals::qpangModule) {
		return;
	}

	auto createAppFn = (uintptr_t)globals::qpangModule + 0x1410;
	auto setWorldToScreenResolutionFn = (uintptr_t)globals::qpangModule + 0xbf2d0;
	auto setCursorBoundsFn = (uintptr_t)globals::qpangModule + 0x1e760;
	auto setResolutionFn = (uintptr_t)globals::qpangModule + 0xf6aa0;
	auto setUnknownPositionFn = (uintptr_t)globals::qpangModule + 0x13b290;
	auto renderMessageFn = (uintptr_t)globals::qpangModule + 0x19d280;
	auto luaTinkerDoFileFn = (uintptr_t)globals::qpangModule + 0x1d8da0;

	MH_CreateHook((void*)createAppFn, (void*)hooks::hkCreateApp, (void**)&hooks::oCreateApp);
	MH_EnableHook((void*)createAppFn);

	MH_CreateHook((void*)setWorldToScreenResolutionFn, (void*)hooks::hkSetWorldToScreenResolution, (void**)&hooks::oSetWorldToScreenResolution);
	MH_EnableHook((void*)setWorldToScreenResolutionFn);

	MH_CreateHook((void*)setCursorBoundsFn, (void*)hooks::hkSetCursorBounds, (void**)&hooks::oSetCursorBounds);
	MH_EnableHook((void*)setCursorBoundsFn);

	MH_CreateHook((void*)setResolutionFn, (void*)hooks::hkSetResolution, (void**)&hooks::oSetResolution);
	MH_EnableHook((void*)setResolutionFn);

	MH_CreateHook((void*)setUnknownPositionFn, (void*)hooks::hkSetUnknownPosition, (void**)&hooks::oSetUnknownPosition);
	MH_EnableHook((void*)setUnknownPositionFn);

	MH_CreateHook((void*)renderMessageFn, (void*)hooks::hkRenderMessage, (void**)&hooks::oRenderMessage);
	MH_EnableHook((void*)renderMessageFn);

	MH_CreateHook((void*)luaTinkerDoFileFn, (void*)hooks::hkLuaTinkerDoFile, (void**)&hooks::oLuaTinkerDoFile);
	MH_EnableHook((void*)luaTinkerDoFileFn);

	// The tool is now ready for the launcher to resume the process, let's tell the launcher that by setting this data value to 1337
	*(int*)((uintptr_t)globals::qpangModule + 0x3c0ef8) = 1337;
}

void setupApiHooks() {
	globals::qpangWindow = FindWindowA(0, "QPang");
	while (!globals::qpangWindow) {
		globals::qpangWindow = FindWindowA(0, "QPang");
		Sleep(10);
	}

	HMODULE on3DModule = GetModuleHandleA("On3D.dll");
	while (!on3DModule) {
		on3DModule = GetModuleHandleA("On3D.dll");
		Sleep(10);
	}

	auto getOnnet3DEngine = (uintptr_t * (__thiscall*)())(GetProcAddress(on3DModule, "?GetSingleton@?$Singleton@VOnNet3DEngine@OnNet3D@@@OnNet3D@@SAAAVOnNet3DEngine@2@XZ"));
	auto getOnnetRenderSystem = (uintptr_t * (__thiscall*)(uintptr_t*))(GetProcAddress(on3DModule, "?GetRenderSystem@OnNet3DEngine@OnNet3D@@QAEPAVRenderSystem@2@XZ"));

	auto onnet3DEngine = getOnnet3DEngine();
	while (!onnet3DEngine) {
		onnet3DEngine = getOnnet3DEngine();
		Sleep(10);
	}

	globals::onnetRenderSystem = getOnnetRenderSystem(onnet3DEngine);
	while (!globals::onnetRenderSystem) {
		globals::onnetRenderSystem = getOnnetRenderSystem(onnet3DEngine);
		Sleep(10);
	}

	auto onnet3DDevice = globals::onnetRenderSystem + 141;
	auto d3d9Device = *(IDirect3DDevice9**)(onnet3DDevice + 1);

	auto d3d9DeviceVtable = *(void***)d3d9Device;
	
	auto keyBoardInputDevice = (IDirectInputDevice8*)((uintptr_t)globals::qpangModule + 0x3a8ce8 + 0x20);
	auto inputDeviceVtable = **(void****)keyBoardInputDevice;

	MH_CreateHook(SetRect, (void*)hooks::hkSetRect, (void**)&hooks::oSetRect);
	MH_EnableHook(SetRect);

	MH_CreateHook(inputDeviceVtable[10], (void*)hooks::hkGetDeviceData, (void**)&hooks::oGetDeviceData);
	MH_EnableHook(inputDeviceVtable[10]);

	MH_CreateHook(d3d9DeviceVtable[42], (void*)hooks::hkEndscene, (void**)&hooks::oEndscene);
	MH_EnableHook(d3d9DeviceVtable[42]);

	MH_CreateHook(d3d9DeviceVtable[16], (void*)hooks::hkReset, (void**)&hooks::oReset);
	MH_EnableHook(d3d9DeviceVtable[16]);

	hooks::oWndProc = (WNDPROC)SetWindowLongPtrA(globals::qpangWindow, GWL_WNDPROC, (LONG_PTR)hooks::wndProc);
}

void setupHooks() {
	if (MH_Initialize() == MB_OK) {
		setupQpangHooks();
		setupApiHooks();
	}
}

void setupTargetResolution() {
	// QPang is not dpi aware... smh Onnet. Here you go:
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE);

	features::targetWidth = GetSystemMetrics(SM_CXSCREEN);
	features::targetHeight = GetSystemMetrics(SM_CYSCREEN);
}

void startThread() {
	// Uncomment if you want to open a console that you can print to
#ifdef _DEBUG
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
#endif

	setupTargetResolution();
	settings::loadAll();
	setupHooks();

	// setUiColor returns false if the instance doesn't have any ui elements yet to change the color of
	// meaning it hasn't initialized yet, because we're in another thread we can just keep trying it
	// untill it succesfully changed color
	while (!utils::setUiColor(features::uiColor))
		continue;
}

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD fdwReason,
	_In_ LPVOID lpvReserved
) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		auto threadHandle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startThread, nullptr, 0, nullptr);
		if (threadHandle) {
			CloseHandle(threadHandle);
		}
	}

	return 1;
}