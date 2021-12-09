#pragma once

#include <vector>
#include <string>

namespace lua {
	inline std::vector<std::string> loadingLua = { R"(

		SCREEN_WIDTH = $SCREEN_WIDTH
		SCREEN_HEIGHT = $SCREEN_HEIGHT

		LD_PICTURE_OFFX = 31
		LD_PICTURE_OFFY = SCREEN_HEIGHT - 76

		LD_PROCESS1_OFFX = 246
		LD_PROCESS2_OFFX = 273
		LD_PROCESS3_OFFX = 300
		LD_PROCESS_OFFY = SCREEN_HEIGHT - 76

		LD_GAUGE_OFFY = SCREEN_HEIGHT - 33

		dofile("UI\\loading_id.lua")
		dofile("UI\\loading_res.lua")
		dofile("UI\\loading_screen.lua")

	)" };
}