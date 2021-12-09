#include "ui.h"

#include <Windows.h>
#include <string>
#include <fstream>

#include "helpers/globals.h"

#include "features/resolution.h"

#include "lua/squareinit.h"

namespace ui {
	IDirect3DDevice9* _device = nullptr;
	IDirect3DSwapChain9* _swapchain = nullptr;

	void init(IDirect3DDevice9* device) {
		/*_device = device;
		device->GetSwapChain(0, &_swapchain);

		D3DPRESENT_PARAMETERS presentationParameters;
		_swapchain->GetPresentParameters(&presentationParameters);

		globals::fullScreen = !presentationParameters.Windowed;*/

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImGui::StyleColorsDark();

		ImGui_ImplWin32_Init(globals::qpangWindow);
		ImGui_ImplDX9_Init(device);
	}

	void begin() {
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	bool changedVideoSettings = false;
	void render() {
		features::fixStretch();

		if (!renderWindow) {
			ImGui::GetIO().MouseDrawCursor = false;
			return;
		}

		ImGui::GetIO().MouseDrawCursor = true;

		/* Bad "fixes" for mouse input not going through wndproc */ {
			POINT cursorPos = { };
			GetCursorPos(&cursorPos);

			ImGui::GetIO().MouseDown[0] = GetAsyncKeyState(VK_LBUTTON) & 1;
			ImGui::GetIO().MouseDown[1] = GetAsyncKeyState(VK_RBUTTON) & 1;
		}

		static bool resolutionTab = true, miscTab = false;

		RECT rect;
		GetWindowRect(globals::qpangWindow, &rect);

		ImGui::SetNextWindowPos({ (float)(rect.right - rect.left) / 2 - (float)ui::width / 2, (float)(rect.bottom - rect.top) / 2 - (float)ui::height / 2 });
		ImGui::SetNextWindowSize({ (float)ui::width, (float)ui::height });

		ImGui::Begin("QPang Tweak Tool v0.1 - by Hinnie"); {
			if (ImGui::BeginTabBar("#tabBar")) {
				if (ImGui::BeginTabItem("Resolution", &resolutionTab)) {
					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Misc", &miscTab)) {
					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
			}

			if (resolutionTab) {
				if (ImGui::InputInt("Width", &globals::targetWidth) ||
					ImGui::InputInt("Height", &globals::targetHeight)) {
					// TODO: Force reset here
				}

				//if (ImGui::Checkbox("Fullscreen", &globals::fullScreen)) {
				//	// set or unset fullscreen
				//	
				//}

				/*if (ImGui::Button("Apply")) {
					changedVideoSettings = true;
				}*/
			}

			ImGui::End();
		}
	}

	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty())
			return;

		size_t startPos = 0;
		while ((startPos = str.find(from, startPos)) != std::string::npos) {
			str.replace(startPos, from.length(), to);
			startPos += to.length();
		}
	}

	void end() {
		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		//if (changedVideoSettings) {
		//	changedVideoSettings = false;

		//	// this works, however, the ui needs to be reloaded, and I got no idea how to do that yet
		//	{
		//		uintptr_t* renderWindow = *(uintptr_t**)((uintptr_t)globals::onnetRenderSystem + 0x240);

		//		static auto reSizeFn = (void(__thiscall*)(void*, uint32_t, uint32_t))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?ReSize@D3DRenderWindow@OnNet3D@@UAEXII@Z"));
		//		static auto resetDeviceFn = (void(__thiscall*)(void*))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?ResetDevice@D3DRenderSystem@OnNet3D@@QAEXXZ"));

		//		reSizeFn(renderWindow, globals::targetWidth, globals::targetHeight);
		//		resetDeviceFn(globals::onnetRenderSystem);

		//		ImGui_ImplDX9_InvalidateDeviceObjects();
		//		ImGui_ImplDX9_CreateDeviceObjects();
		//	}

		//	std::string path = std::tmpnam(nullptr);
		//	std::ofstream out(path);

		//	for (std::string squareInitLuaPart : lua::squareInitLua) {
		//		replaceAll(squareInitLuaPart, "$SCREEN_WIDTH", std::to_string(globals::targetWidth));
		//		replaceAll(squareInitLuaPart, "$SCREEN_HEIGHT", std::to_string(globals::targetHeight));
		//		out << squareInitLuaPart;
		//	}

		//	out.close();

		//	static auto getLuaStateFn = (DWORD**(*)())((uintptr_t)globals::qpangModule + 0x21cb0);
		//	static auto luaTinkerDoFileFn = (int(*)(DWORD*, const char*))((uintptr_t)globals::qpangModule + 0x1d8da0);

		//	*(int*)((uintptr_t)globals::qpangModule + 0x3c1d14) = 0;
		//	luaTinkerDoFileFn(getLuaStateFn()[1], path.c_str());
		//}

		/*if (changedVideoSettings) {
			changedVideoSettings = false;

			D3DPRESENT_PARAMETERS presentationParameters;
			_swapchain->GetPresentParameters(&presentationParameters);

			presentationParameters.BackBufferWidth = globals::targetWidth;
			presentationParameters.BackBufferHeight = globals::targetHeight;
			presentationParameters.Windowed = !globals::fullScreen;

			static auto lostDeviceFn = (void(__thiscall*)(void*))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?LostDevice@D3DRenderSystem@OnNet3D@@QAEXXZ"));
			static auto restoreDeviceFn = (void(__thiscall*)(void*))(GetProcAddress(GetModuleHandleA("On3D.dll"), "?RestoreDevice@D3DRenderSystem@OnNet3D@@QAEXXZ"));

			lostDeviceFn(globals::onnetRenderSystem);

			_device->Reset(&presentationParameters);

			restoreDeviceFn(globals::onnetRenderSystem);
		}*/
	}
}