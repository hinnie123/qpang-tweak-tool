#pragma once

#include "utils.h"

#include <d3d9types.h>
#include <random>

#include "globals.h"

#include "sdk/guimanager.h"
#include "sdk/lua.h"

namespace utils {
	bool setUiColor(DWORD dwColor) {
		auto uiManager = GUIManager::getInstance();
		if (!uiManager)
			return false;

		if (uiManager->getNumElements() == 0)
			return false;

		uiManager->setGlobalColor(dwColor);
		return true;
	}

	bool setUiColor(float color[4]) {
		int r = color[0] * 255.f;
		int g = color[1] * 255.f;
		int b = color[2] * 255.f;
		int a = color[3] * 255.f;

		DWORD dwColor = D3DCOLOR_RGBA(r, g, b, a);
		return setUiColor(dwColor);
	}

	float randomFloat(float min, float max) {
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_real_distribution<float> distr(min, max);
		return distr(eng);
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
}