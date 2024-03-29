#pragma once

#include "settings.h"

#include <Windows.h>
#include <dbghelp.h>
#include <fstream>

#include "features/resolution.h"
#include "features/gui.h"
#include "features/ingame.h"

#define SAFE_JSON(x) try { x; } catch (nlohmann::json::exception& ex) {}

namespace settings {
	const std::string settingsName = "Settings.json";
	std::string targetDir = "QPangTweakTool/";

	void ensureDirExists() {
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
			{"ingame", {
				{"higherFov", features::higherFov},
				{"sensitivityEnabled", features::sensitivityEnabled},
				{"sensitivityValue", features::sensitivityValue}
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

			SAFE_JSON(j.at("resolution").at("targetWidth").get_to(features::targetWidth));
			SAFE_JSON(j.at("resolution").at("targetHeight").get_to(features::targetHeight));

			SAFE_JSON(j.at("ingame").at("higherFov").get_to(features::higherFov));
			SAFE_JSON(j.at("ingame").at("sensitivityEnabled").get_to(features::sensitivityEnabled));
			SAFE_JSON(j.at("ingame").at("sensitivityValue").get_to(features::sensitivityValue));

			SAFE_JSON(j.at("gui").at("uiColor").get_to(features::uiColor));
			SAFE_JSON(j.at("gui").at("rainbowUiEnabled").get_to(features::rainbowUiEnabled));
			SAFE_JSON(j.at("gui").at("rainbowUiSpeed").get_to(features::rainbowUiSpeed));
			SAFE_JSON(j.at("gui").at("showFpsEnabled").get_to(features::showFpsEnabled));
		}
	}
}