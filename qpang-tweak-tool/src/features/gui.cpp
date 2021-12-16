#include "gui.h"

#include <format>
#include <array>
#include <unordered_map>

#include "../helpers/utils.h"

#include "sdk/guimanager.h"

#include "imgui/imgui.h"

namespace features {
	void rainbowUi() {
		if (!rainbowUiEnabled)
			return;

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
		if (!showFpsEnabled)
			return;

		auto drawList = ImGui::GetWindowDrawList();
		drawList->AddRectFilled({ 0.f, 0.f }, { 70.f, 30.f }, 0x7f000000);
		drawList->AddText({ 6.f, 8.f }, 0xffffffff, std::format("FPS: {}", (int)ImGui::GetIO().Framerate).c_str());
	}
}