﻿#pragma once

#include <vector>
#include <string>

namespace lua {
	std::vector<std::string> squareInitLua = { R"(

		dofile('UI\\GlobalVar.lua')
		dofile('UI\\mnemonic.lua')
		dofile('UI\\StringTable.lua')
		dofile('UI\\common_res.lua')
		dofile('UI\\square_id.lua')

		SCREEN_WIDTH = $SCREEN_WIDTH
		SCREEN_HEIGHT = $SCREEN_HEIGHT

		MAINBAR_OFFX = 1074
		MAINBAR_OFFY = SCREEN_HEIGHT - 69

		MAINMENU_OFFX = 1111
		MAINMENU_OFFY = 1

		SQMINIMAP_OFFX = SCREEN_WIDTH - 225
		SQMINIMAP_OFFY = 35

		SQUARE_NAME_OFFX = 531
		SQUARE_NAME_WIDTH = 0

		SQTIP_OFFX = 0
		SQTIP_OFFY = SCREEN_HEIGHT - 74
		SQTIP_WIDTH = SCREEN_WIDTH - 236

		FIRSTSQ_UPPER_OFFX = 240
		FIRSTSQ_UPPER_OFFY = 0

		FIRSTSQ_LOWER_OFFX = 240
		FIRSTSQ_LOWER_OFFY = 784

		MSG_CONNECTFRIEND_OFFX = 599
		MSG_CONNECTFRIEND_OFFY = 410

		FUNCITEM_OFFX = 339
		FUNCITEM_OFFY = 263

		MY_INVEN_OFFX = 50
		MY_INVEN_OFFY = 271

		OTHER_TRADE_OFFX = 1071
		OTHER_TRADE_OFFY = 271

		CARDSLOT_OFFX = 493
		CARDSLOT_OFFY = 230

		SURVEY_VIEW_OFFX = 319
		SURVEY_VIEW_OFFY = 112

		SURVEY_CONF_OFFX = 339
		SURVEY_CONF_OFFY = 324

		SCREEN_SHOT_OFFX = 501
		SCREEN_SHOT_OFFY = 710

		NPC_TALK_OFFX = 112
		NPC_TALK_OFFY = 590

		SQCHATVIEW_OFFX = 240
		SQCHATVIEW_OFFY = 860 - 22

		SQCHATEDIT_OFFX = 240
		SQCHATEDIT_OFFY = 962 - 22

		MSG_OFFX = SCREEN_WIDTH / 2 + 795 / 2 - 287
		MSG_OFFY = SCREEN_HEIGHT - 368

		MSG_FRLIST_OFFX = MSG_OFFX - 322
		MSG_FRLIST_OFFY = 679

		MSG_MEMO_OFFX = 535
		MSG_MEMO_OFFY = 679

		MSG_MEMOVIEW_OFFX = 483
		MSG_MEMOVIEW_OFFY = 378

		MSG_MEMOEDIT_OFFX = 483
		MSG_MEMOEDIT_OFFY = 378

		INVENTORY_OFFX = SCREEN_WIDTH / 2 - 330 / 2
		INVENTORY_OFFY = SCREEN_HEIGHT / 2 - 500 / 2

		CHARVIEW_OFFX = SCREEN_WIDTH / 2 - 230 - 330 / 2
		CHARVIEW_OFFY = SCREEN_HEIGHT / 2 - 500 / 2

		NOTEBOX_OFFX = 1101
		NOTEBOX_OFFY = 937

		dofile('UI\\common_ui.lua')
		dofile('UI\\square_screen.lua')

	)" };
}