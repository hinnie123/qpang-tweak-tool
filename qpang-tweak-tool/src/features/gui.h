#pragma once

namespace features {
	inline float uiColor[4] = { 1.f, 1.f, 1.f, 1.f };
	inline bool rainbowUiEnabled = false;
	inline int rainbowUiSpeed = 10;

	void rainbowUi();

	inline bool showFpsEnabled = false;
	void showFps();

	inline bool hideUiEnabled = false;
}