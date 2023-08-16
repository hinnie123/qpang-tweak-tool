#include <Windows.h>
#include <d3d9.h>

#include "minhook/minhook.h"

#include "hooks/getcommandlinew.h"
#include "hooks/getcommandlinea.h"
#include "hooks/sendspveroundstart.h"
#include "hooks/handlejoinsandroundend.h"
#include "hooks/handlestartandpvestart.h"
#include "hooks/fillgcroompacket.h"
#include "hooks/neteventgcmasterlog.h"
#include "hooks/handlegcjoin.h"
#include "hooks/clientgamecgmove.h"
#include "hooks/setuistate.h"
#include "hooks/elementshoulddraw.h"
#include "hooks/createapp.h"
#include "hooks/rendermessage.h"
#include "hooks/setunknownposition.h"
#include "hooks/setcursorbounds.h"
#include "hooks/setresolution.h"
#include "hooks/setworldtoscreenresolution.h"
#include "hooks/luatinkerdofile.h"

#include "hooks/setrect.h"
#include "hooks/wndproc.h"
#include "hooks/getfocus.h"
#include "hooks/present.h"
#include "hooks/reset.h"

#include "helpers/settings.h"
#include "helpers/utils.h"

#include "features/ingame.h"

#define HOOK(from, to, original) if (MH_CreateHook((void*)from, (void*)to, (void**)&original) == MH_OK) { MH_EnableHook((void*)from); }

HINSTANCE mainModule;
void setupQpangHooks() {
	globals::qpangModule = GetModuleHandleA(nullptr);
	if (!globals::qpangModule) {
		return;
	}

#ifdef V2013
	auto sendsPveRoundStartFn = (uintptr_t)globals::qpangModule + 0x35e00;
	auto handleJoinsAndRoundEndFn = (uintptr_t)globals::qpangModule + 0x37290;
	auto handleStartAndPveStartFn = (uintptr_t)globals::qpangModule + 0x37340;
	auto fillCGRoomPacketFn = (uintptr_t)globals::qpangModule + 0x250370;
	auto netEventGCMasterLogFn = (uintptr_t)globals::qpangModule + 0xbfbe0;
	auto handleGCJoinFn = (uintptr_t)globals::qpangModule + 0x350d0;
	auto clientGameCGMoveFn = (uintptr_t)globals::qpangModule + 0x25f210;
	auto setUiStateFn = (uintptr_t)globals::qpangModule + 0x61720;
	auto elementShouldDrawFn = (uintptr_t)globals::qpangModule + 0x13c700;
	auto createAppFn = (uintptr_t)globals::qpangModule + 0x1430;
	auto setWorldToScreenResolutionFn = (uintptr_t)globals::qpangModule + 0xc0300;
	auto setCursorBoundsFn = (uintptr_t)globals::qpangModule + 0x1e9d0;
	auto setResolutionFn = (uintptr_t)globals::qpangModule + 0xf7d70;
	auto setUnknownPositionFn = (uintptr_t)globals::qpangModule + 0x13c630;
	auto renderMessageFn = (uintptr_t)globals::qpangModule + 0x19e9b0;
	auto luaTinkerDoFileFn = (uintptr_t)globals::qpangModule + 0x1da910;
#else
	auto sendsPveRoundStartFn = (uintptr_t)globals::qpangModule + 0x35a70;
	auto handleJoinsAndRoundEndFn = (uintptr_t)globals::qpangModule + 0x36f00;
	auto handleStartAndPveStartFn = (uintptr_t)globals::qpangModule + 0x36fb0;
	auto fillCGRoomPacketFn = (uintptr_t)globals::qpangModule + 0x24e6d0;
	auto netEventGCMasterLogFn = (uintptr_t)globals::qpangModule + 0xbebb0;
	auto handleGCJoinFn = (uintptr_t)globals::qpangModule + 0x34d40;
	auto clientGameCGMoveFn = (uintptr_t)globals::qpangModule + 0x25d620;
	auto setUiStateFn = (uintptr_t)globals::qpangModule + 0x609b0;
	auto elementShouldDrawFn = (uintptr_t)globals::qpangModule + 0x13b360;
	auto createAppFn = (uintptr_t)globals::qpangModule + 0x1410;
	auto setWorldToScreenResolutionFn = (uintptr_t)globals::qpangModule + 0xbf2d0;
	auto setCursorBoundsFn = (uintptr_t)globals::qpangModule + 0x1e760;
	auto setResolutionFn = (uintptr_t)globals::qpangModule + 0xf6aa0;
	auto setUnknownPositionFn = (uintptr_t)globals::qpangModule + 0x13b290;
	auto renderMessageFn = (uintptr_t)globals::qpangModule + 0x19d280;
	auto luaTinkerDoFileFn = (uintptr_t)globals::qpangModule + 0x1d8da0;
#endif

	HOOK(GetCommandLineA, hooks::hkGetCommandLineA, hooks::oGetCommandLineA);
	HOOK(GetCommandLineW, hooks::hkGetCommandLineW, hooks::oGetCommandLineW);
	HOOK(sendsPveRoundStartFn, hooks::hkSendsPveRoundStartFn, hooks::oSendsPveRoundStartFn);
	HOOK(handleJoinsAndRoundEndFn, hooks::hkHandleJoinsAndRoundEnd, hooks::oHandleJoinsAndRoundEnd);
	HOOK(handleStartAndPveStartFn, hooks::hkHandleStartAndPveStart, hooks::oHandleStartAndPveStart);
	HOOK(fillCGRoomPacketFn, hooks::hkFillCGRoomPacket, hooks::oFillCGRoomPacket);
	HOOK(netEventGCMasterLogFn, hooks::hkNetEventGCMasterLog, hooks::oNetEventGCMasterLog);
	HOOK(handleGCJoinFn, hooks::hkHandleGCJoin, hooks::oHandleGCJoin);
	HOOK(clientGameCGMoveFn, hooks::hkClientGameCGMove, hooks::oClientGameCGMove);
	HOOK(setUiStateFn, hooks::hkSetUiState, hooks::oSetUiState);
	HOOK(elementShouldDrawFn, hooks::hkElementShouldDraw, hooks::oElementShouldDraw);
	HOOK(createAppFn, hooks::hkCreateApp, hooks::oCreateApp);
	HOOK(setWorldToScreenResolutionFn, hooks::hkSetWorldToScreenResolution, hooks::oSetWorldToScreenResolution);
	HOOK(setCursorBoundsFn, hooks::hkSetCursorBounds, hooks::oSetCursorBounds);
	HOOK(setResolutionFn, hooks::hkSetResolution, hooks::oSetResolution);
	HOOK(setUnknownPositionFn, hooks::hkSetUnknownPosition, hooks::oSetUnknownPosition);
	HOOK(renderMessageFn, hooks::hkRenderMessage, hooks::oRenderMessage);
	HOOK(luaTinkerDoFileFn, hooks::hkLuaTinkerDoFile, hooks::oLuaTinkerDoFile);

	// The tool is now ready for the launcher to resume the process, let's tell the launcher that by setting this data value to 1337
#ifdef V2013
	*(int*)0x7D64D4 = 1337;
#else
	*(int*)0x7D34AC = 1337;
#endif
}

void setupApiHooks() {
	globals::qpangWindow = FindWindowA("QPang", "QPang");
	while (!globals::qpangWindow) {
		globals::qpangWindow = FindWindowA("QPang", "QPang");
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

	HOOK(GetFocus, hooks::hkGetFocus, hooks::oGetFocus);
	HOOK(SetRect, hooks::hkSetRect, hooks::oSetRect);
	HOOK(d3d9DeviceVtable[17], hooks::hkPresent, hooks::oPresent);
	HOOK(d3d9DeviceVtable[16], hooks::hkReset, hooks::oReset);

	hooks::oWndProc = (WNDPROC)SetWindowLongPtrA(globals::qpangWindow, GWL_WNDPROC, (LONG_PTR)hooks::wndProc);
}

void setupHooks() {
	if (MH_Initialize() == MH_OK) {
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

void disableGlitchedPvESound()
{
#ifdef V2013
	void* address = (void*)0x736bc4;
#else
	void* address = (void*)0x733bbc;
#endif

	DWORD oldProtection = 0;
	VirtualProtect((LPVOID)address, sizeof(wchar_t), PAGE_EXECUTE_READWRITE, &oldProtection);

	*(wchar_t*)(address) = L'\0';

	VirtualProtect((LPVOID)address, sizeof(wchar_t), oldProtection, &oldProtection);
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

	disableGlitchedPvESound();
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
		mainModule = hinstDLL;

		auto threadHandle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startThread, nullptr, 0, nullptr);
		if (threadHandle) {
			CloseHandle(threadHandle);
		}
	}

	return 1;
}