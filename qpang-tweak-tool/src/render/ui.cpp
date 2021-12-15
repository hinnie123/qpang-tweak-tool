#include "ui.h"

#include <Windows.h>
#include <string>
#include <fstream>

#include "helpers/globals.h"
#include "helpers/utils.h"
#include "helpers/settings.h"

#include "features/resolution.h"
#include "features/gui.h"
#include "features/ingame.h"

#include "lua/squareinit.h"

#include "sdk/guimanager.h"

namespace ui {
	IDirect3DDevice9* _device = nullptr;
	IDirect3DSwapChain9* _swapchain = nullptr;

	void init(IDirect3DDevice9* device) {
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

	void renderOverlay() {
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });

		ImGui::SetNextWindowPos({ 0.f, 0.f });
		ImGui::SetNextWindowSize({ (float)features::targetWidth, (float)features::targetHeight });

		ImGui::Begin("#overlay", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoInputs |
			ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoNav);

		{
			features::showFps();
		}

		ImGui::End();

		ImGui::PopStyleVar(2);
	}

	void render() {
		/* Bad "fixes" for mouse input not going through wndproc */ {
			ImGui::GetIO().MouseDown[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
			ImGui::GetIO().MouseDown[1] = GetAsyncKeyState(VK_RBUTTON) & 0x8000;
		}

		renderOverlay();

		if (!renderWindow) {
			ImGui::GetIO().MouseDrawCursor = false;
			return;
		}

		SetFocus(globals::qpangWindow);
		ImGui::GetIO().MouseDrawCursor = true;

		RECT rect;
		GetWindowRect(globals::qpangWindow, &rect);

		ImGui::SetNextWindowPos({ (float)(rect.right - rect.left) / 2 - (float)ui::width / 2, (float)(rect.bottom - rect.top) / 2 - (float)ui::height / 2 });
		ImGui::SetNextWindowSize({ (float)ui::width, (float)ui::height });

		ImGui::Begin("QPang Tweak Tool v0.1 - by Hinnie", nullptr, ImGuiWindowFlags_NoSavedSettings); {
			if (ImGui::BeginTabBar("#tabBar")) {
				if (ImGui::BeginTabItem("Resolution")) {
					if (ImGui::InputInt("Width", &features::targetWidth) ||
						ImGui::InputInt("Height", &features::targetHeight)) {
						settings::saveAll();
					}

					ImGui::EndTabItem();
				}

				/*if (ImGui::BeginTabItem("Ingame")) {
					ImGui::SliderInt("Sensitivity", &features::sensitivity, 1, 300);

					ImGui::EndTabItem();
				}*/

				if (ImGui::BeginTabItem("UI")) {
#ifdef _DEBUG
					if (ImGui::Button("SHOW ALL")) {
						auto uiManager = GUIManager::getInstance();
						if (uiManager) {
							auto numElements = uiManager->getNumElements();
							for (size_t i = 0; i < numElements; ++i) {
								auto element = uiManager->uiElements[i];
								if (element) {
									element->bDraw = true;
								}
							}
						}
					}
#endif

					if (ImGui::Checkbox("Hide Ingame Ui", &features::hideUiEnabled)) {
						features::hideUi();
					}

					if (ImGui::Checkbox("Show FPS", &features::showFpsEnabled)) {
						settings::saveAll();
					}

					if (ImGui::Checkbox("Rainbow Ui", &features::rainbowUiEnabled)) {
						settings::saveAll();
					}

					if (features::rainbowUiEnabled) {
						ImGui::SliderInt("Rainbow Speed", &features::rainbowUiSpeed, 1, 100);
						settings::saveAll();
					}

					ImGui::SetNextItemWidth(150);
					if (ImGui::ColorPicker4("Ui Color", features::uiColor, ImGuiColorEditFlags_AlphaBar)) {
						utils::setUiColor(features::uiColor);
						settings::saveAll();
					}

					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
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

	void end(IDirect3DDevice9* device) {
		ImGui::EndFrame();
		ImGui::Render();

		if (device->BeginScene() == D3D_OK) {
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			device->EndScene();
		}
	}
}