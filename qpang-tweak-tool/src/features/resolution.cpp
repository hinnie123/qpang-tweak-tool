#include "resolution.h"

#include "../helpers/globals.h"
#include "../helpers/settings.h"

#include <Psapi.h>

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
		if (wcsstr(message, L"quit?") || wcsstr(message, L"verlaten?") || wcsstr(message, L"tutorial?") || wcsstr(message, L"training") || wcsstr(message, L"coin?")
			|| wcsstr(message, L"munt?")) {
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

	wchar_t* cachedCmdLineW = nullptr;
	wchar_t* fixCmdLineW() {
		settings::ensureDirExists();

		if (cachedCmdLineW == nullptr) {
			std::array<std::wstring, 3> locales = {
				L"Dutch",
				L"English",
				L"German"
			};

			int fullscreen = 0;
			int locale = 1;
			int forceVSync = 0;

			int width = features::targetWidth;
			int height = features::targetHeight;

			nlohmann::json j = settings::fileToJson("GameSettings.json");
			j.at("DisplayMode").get_to(fullscreen);
			j.at("GameLanguage").get_to(locale);
			j.at("ForceVSync").get_to(forceVSync);

			wchar_t moduleName[MAX_PATH] = {};
			GetModuleBaseNameW((HANDLE)-1, globals::qpangModule, moduleName, sizeof(moduleName) * 2);

			std::wstring cmdLine = std::wstring(moduleName) + L" -fullscreen:" + std::to_wstring(fullscreen) + L" -locale:" + locales[locale] + L" -width:" +
				std::to_wstring(width) + L" -height:" + std::to_wstring(height) + L" -forcevsync:" + std::to_wstring(forceVSync);

			// now copy it over to c-style wchar_t* global
			cachedCmdLineW = new wchar_t[cmdLine.length() + 1];
			wcscpy(cachedCmdLineW, cmdLine.c_str());
		}

		return cachedCmdLineW;
	}

	char* cachedCmdLineA = nullptr;
	char* fixCmdLineA() {
		settings::ensureDirExists();

		if (cachedCmdLineA == nullptr) {
			std::array<std::string, 3> locales = {
				"Dutch",
				"English",
				"German"
			};

			int fullscreen = 0;
			int locale = 1;
			int forceVSync = 0;

			int width = features::targetWidth;
			int height = features::targetHeight;

			nlohmann::json j = settings::fileToJson("GameSettings.json");
			j.at("DisplayMode").get_to(fullscreen);
			j.at("GameLanguage").get_to(locale);
			j.at("ForceVSync").get_to(forceVSync);

			char moduleName[MAX_PATH] = {};
			GetModuleBaseNameA((HANDLE)-1, globals::qpangModule, moduleName, sizeof(moduleName));

			std::string cmdLine = std::string(moduleName) + " -fullscreen:" + std::to_string(fullscreen) + " -locale:" + locales[locale] + " -width:" +
				std::to_string(width) + " -height:" + std::to_string(height) + " -forcevsync:" + std::to_string(forceVSync);

			// now copy it over to c-style wchar_t* global
			cachedCmdLineA = new char[cmdLine.length() + 1];
			strcpy(cachedCmdLineA, cmdLine.c_str());
		}

		return cachedCmdLineA;
	}

	void positionUiElement(UIElement* element) {
		if (element->id == 0) {
			element->setDimensions(targetWidth, targetHeight);
		}

		if (element->hasId(eUIElements::UI_IDD_LOGIN)) {
			element->setPos(targetWidth / 2, targetHeight - 158 * 2);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT)) {
			element->setPos(targetWidth / 2, targetHeight / 2);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT_SVR1)) {
			element->setPos(targetWidth / 2 - 148, targetHeight / 2 - 125);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT_SVR2)) {
			element->setPos(targetWidth / 2 - 148, targetHeight / 2 - 125 + 84);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT_CHN1)) {
			element->setPos(targetWidth / 2 + 192, targetHeight / 2 - 118);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT_CHN2)) {
			element->setPos(targetWidth / 2 + 192, targetHeight / 2 - 118 + 52 * 1);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT_CHN3)) {
			element->setPos(targetWidth / 2 + 192, targetHeight / 2 - 118 + 52 * 2);
		}

		if (element->hasId(eUIElements::UI_IDD_SERVER_SELECT_CHN4)) {
			element->setPos(targetWidth / 2 + 192, targetHeight / 2 - 118 + 52 * 3);
		}
	}

	void positionUiElements() {
		auto uiManager = GUIManager::getInstance();
		if (!uiManager)
			return;

		for (size_t i = 0; i < uiManager->getNumElements(); ++i) {
			auto element = uiManager->uiElements[i];
			if (!element)
				continue;

			positionUiElement(element);
		}
	}
}