#pragma once

#include "settings.h"

#include <Windows.h>
#include <dbghelp.h>
#include <fstream>

#include "features/resolution.h"
#include "features/gui.h"

namespace settings {
	const std::string settingsName = "TweakToolSettings.json";
	std::string targetDir = "";

	void ensureDirExists() {
		if (targetDir.empty()) {
			targetDir = "Launcher/Settings/";
		}

		MakeSureDirectoryPathExists(targetDir.c_str());
	}

	void jsonToFile(const nlohmann::json& j, std::string fileName) {
		std::ofstream stream(targetDir + settingsName);
		stream << std::setw(4) << j << std::endl;
	}

	nlohmann::json fileToJson(std::string fileName) {
		nlohmann::json j;
		std::ifstream stream(targetDir + fileName);
		stream >> j;
		return j;
	}

	void saveAll() {
		nlohmann::json j = {
			{"resolution", {
				{"targetWidth", features::targetWidth},
				{"targetHeight", features::targetHeight}
			}},
			{"gui", {
				{"uiColor", features::uiColor},
				{"rainbowUiEnabled", features::rainbowUiEnabled},
				{"rainbowUiSpeed", features::rainbowUiSpeed},
				{"showFpsEnabled", features::showFpsEnabled}
			}}
		};

		ensureDirExists();
		jsonToFile(j, settingsName);
	}

	void loadAll() {
		ensureDirExists();

		if (std::filesystem::exists(targetDir + settingsName)) {
			nlohmann::json j = fileToJson(settingsName);

			j.at("resolution").at("targetWidth").get_to(features::targetWidth);
			j.at("resolution").at("targetHeight").get_to(features::targetHeight);

			j.at("gui").at("uiColor").get_to(features::uiColor);
			j.at("gui").at("rainbowUiEnabled").get_to(features::rainbowUiEnabled);
			j.at("gui").at("rainbowUiSpeed").get_to(features::rainbowUiSpeed);
			j.at("gui").at("showFpsEnabled").get_to(features::showFpsEnabled);
		}
	}
}