#pragma once

#include <iostream>
#include <fstream>

#include "helpers/globals.h"

#include "lua/squareinit.h"
#include "lua/ingameinit.h"

namespace hooks {
	typedef int(__cdecl* tLuaTinkerDoFile)(DWORD*, const char*);
	inline tLuaTinkerDoFile oLuaTinkerDoFile = nullptr;

	void replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if (from.empty())
			return;

		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
	}

	int __cdecl hkLuaTinkerDoFile(DWORD* lua_state, const char* filename) {
		std::cout << filename << std::endl;

		if (strstr(filename, "square_init")) {
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string squareInitLuaPart : lua::squareInitLua) {
				replaceAll(squareInitLuaPart, "$SCREEN_WIDTH", std::to_string(globals::targetWidth));
				replaceAll(squareInitLuaPart, "$SCREEN_HEIGHT", std::to_string(globals::targetHeight));
				out << squareInitLuaPart;
			}

			out.close();

			return oLuaTinkerDoFile(lua_state, path.c_str());
		} else if (strstr(filename, "ingame_init")) {
			std::string path = std::tmpnam(nullptr);
			std::ofstream out(path);

			for (std::string ingameInitLuaPart : lua::ingameInitLua) {
				replaceAll(ingameInitLuaPart, "$SCREEN_WIDTH", std::to_string(globals::targetWidth));
				replaceAll(ingameInitLuaPart, "$SCREEN_HEIGHT", std::to_string(globals::targetHeight));
				out << ingameInitLuaPart;
			}

			out.close();

			return oLuaTinkerDoFile(lua_state, path.c_str());
		}

		return oLuaTinkerDoFile(lua_state, filename);
	}
}