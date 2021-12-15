#include "gui.h"

#include <format>
#include <array>
#include <unordered_map>

#include "../helpers/utils.h"

#include "sdk/guimanager.h"

#include "imgui/imgui.h"

namespace features {
	void rainbowUi() {
		if (!rainbowUiEnabled) {
			return;
		}

		static float rainbow = 0.f;

		float speed = ((float)rainbowUiSpeed / 75.f) * ImGui::GetIO().DeltaTime;

		rainbow += speed;
		if (rainbow > 1.f) {
			rainbow = 0.f;
		}

		float color[4] = { 1.f, 1.f, 1.f, 1.f };
		ImGui::ColorConvertHSVtoRGB(rainbow, 1.f, 1.f, color[0], color[1], color[2]);
		utils::setUiColor(color);
	}

	void showFps() {
		if (!showFpsEnabled) {
			return;
		}

		auto drawList = ImGui::GetWindowDrawList();
		drawList->AddRectFilled({ 0.f, 0.f }, { 70.f, 30.f }, 0x7f000000);
		drawList->AddText({ 6.f, 8.f }, 0xffffffff, std::format("FPS: {}", (int)ImGui::GetIO().Framerate).c_str());
	}

	void hideUi() {
		static const std::array<eUIElements, 16> ingameUiElements = {
			UI_IDD_SCORE,
			UI_IDD_NULLDLG,
			UI_IDD_HITMARK,
			UI_IDD_BULLET_INFO,
			UI_IDD_ESSENSE_SLOT,
			UI_IDD_SNIPING,
			UI_IDD_WEAPON_SLOT,
			UI_IDD_PLAYER_STAT,
			UI_IDD_PLAYER_PVESTAT,
			UI_IDD_MINIMAP,
			UI_IDD_WORLDMAP,
			UI_IDD_ONELINE_MSG,
			UI_IDD_CURRENT_SCORE,
			UI_IDD_SKILL_HEHLP,
			UI_IDD_GAME_PVE_FAIL,
			UI_IDD_CHATTING,
		};

		static std::unordered_map<eUIElements, bool> wasElementEnabled = {};

		auto uiManager = GUIManager::getInstance();
		if (uiManager) {
			for (const auto id : ingameUiElements) {
				auto uiElement = uiManager->findElementById(id);
				if (!uiElement)
					continue;

				if (features::hideUiEnabled) {
					wasElementEnabled[id] = uiElement->bDraw;
					uiElement->bDraw = false;
				}
				else if (wasElementEnabled[id]) {
					uiElement->bDraw = true;
				}
			}
		}
	}
}