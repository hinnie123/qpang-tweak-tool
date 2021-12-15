#pragma once

#include <iostream>
#include <fstream>

#include "helpers/globals.h"

#include "lua/login.h"
#include "lua/squareinit.h"
#include "lua/ingameinit.h"
#include "lua/loadinglua.h"
#include "lua/waitroom.h"

#include "features/resolution.h"
#include "features/gui.h"

namespace hooks {
	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty())
			return;

		size_t startPos = 0;
		while ((startPos = str.find(from, startPos)) != std::string::npos) {
			str.replace(startPos, from.length(), to);
			startPos += to.length();
		}
	}

	typedef int(__cdecl* tLuaTinkerDoFile)(DWORD*, const char*);
	inline tLuaTinkerDoFile oLuaTinkerDoFile = nullptr;

	int __cdecl hkLuaTinkerDoFile(DWORD* lua_state, const char* filename) {
#ifdef _DEBUG
		std::cout << filename << std::endl;
#endif

		features::resetUiVisibility();

		if (strstr(filename, "login")) {
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string loginLuaPart : lua::loginLua) {
				replaceAll(loginLuaPart, "$SCREEN_WIDTH", std::to_string(features::targetWidth));
				replaceAll(loginLuaPart, "$SCREEN_HEIGHT", std::to_string(features::targetHeight));
				out << loginLuaPart;
			}

			out.close();

			auto retValue = oLuaTinkerDoFile(lua_state, path.c_str());
			features::hideUi();
			return retValue;
		}
		if (strstr(filename, "square_init")) {
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string squareInitLuaPart : lua::squareInitLua) {
				replaceAll(squareInitLuaPart, "$SCREEN_WIDTH", std::to_string(features::targetWidth));
				replaceAll(squareInitLuaPart, "$SCREEN_HEIGHT", std::to_string(features::targetHeight));
				out << squareInitLuaPart;
			}

			out.close();

			auto retValue = oLuaTinkerDoFile(lua_state, path.c_str());
			features::hideUi();
			return retValue;
		} else if (strstr(filename, "ingame_init")) {
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string ingameInitLuaPart : lua::ingameInitLua) {
				replaceAll(ingameInitLuaPart, "$SCREEN_WIDTH", std::to_string(features::targetWidth));
				replaceAll(ingameInitLuaPart, "$SCREEN_HEIGHT", std::to_string(features::targetHeight));
				out << ingameInitLuaPart;
			}

			out.close();

			auto retValue = oLuaTinkerDoFile(lua_state, path.c_str());
			features::hideUi();
			return retValue;
		} else if (strstr(filename, "loading0") || strstr(filename, "loading1")) {  // loading0800, loading1024, loading1280
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string loadingLuaPart : lua::loadingLua) {
				replaceAll(loadingLuaPart, "$SCREEN_WIDTH", std::to_string(features::targetWidth));
				replaceAll(loadingLuaPart, "$SCREEN_HEIGHT", std::to_string(features::targetHeight));
				out << loadingLuaPart;
			}

			out.close();

			auto retValue = oLuaTinkerDoFile(lua_state, path.c_str());
			features::hideUi();
			return retValue;
		} else if (strstr(filename, "WaitRoom")) {
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string waitRoomLuaPart : lua::waitRoomLua) {
				replaceAll(waitRoomLuaPart, "$SCREEN_WIDTH", std::to_string(features::targetWidth));
				replaceAll(waitRoomLuaPart, "$SCREEN_HEIGHT", std::to_string(features::targetHeight));
				out << waitRoomLuaPart;
			}

			out.close();

			auto retValue = oLuaTinkerDoFile(lua_state, path.c_str());
			features::hideUi();
			return retValue;
		}

		auto retValue = oLuaTinkerDoFile(lua_state, filename);
		features::hideUi();
		return retValue;
	}
}