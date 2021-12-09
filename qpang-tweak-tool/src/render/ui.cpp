#include "ui.h"

#include "helpers/globals.h"

namespace ui {
	IDirect3DDevice9* _device;
	void init(IDirect3DDevice9* device) {
		_device = device;

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

	void render() {
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
			}

			ImGui::End();
		}
	}

	void end() {
		ImGui::EndFrame();
		ImGui::Render();

		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}
}