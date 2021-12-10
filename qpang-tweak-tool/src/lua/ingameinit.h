#pragma once

#include <string>

namespace lua {
    inline std::vector<std::string> ingameInitLua = { R"(

	    SCREEN_WIDTH = $SCREEN_WIDTH
	    SCREEN_HEIGHT = $SCREEN_HEIGHT

	    dofile("UI\\GlobalVar.lua")
	    dofile("UI\\mnemonic.lua")
	    dofile("UI\\StringTable.lua")
	    dofile("UI\\common_res.lua")
	    dofile("UI\\common_ui.lua")

	    dofile("UI\\ingame_id.lua")

	    SCREEN_CENTER_X = SCREEN_WIDTH / 2
	    SCREEN_CENTER_Y = SCREEN_HEIGHT / 2

	    RESULT_ORGX = 112
	    RESULT_ORGY = 84

	    RESULT_MY_CANVAS_X = 0
	    RESULT_MY_CANVAS_Y = 0
	    RESULT_MY_CANVAS_W = 280
	    RESULT_MY_CANVAS_H = 280

	    RESULT_ALL_CANVAS_X = 0
	    RESULT_ALL_CANVAS_Y = 0
	    RESULT_ALL_CANVAS_W = SCREEN_WIDTH
	    RESULT_ALL_CANVAS_H = 225

	    RESULT_BG = UICommonImgPath.."bg-result-1280.png"
	    PVE_RESULT_BG = UICommonImgPath.."bg-PVE-result-1280.png"

	    HandCannon_Texture = UIPackingImagePath.."ui-sniping-hcannon-1024.dds"
	    Destroyer_Texture = UIPackingImagePath.."ui-sniping-destroyer-1024.dds"
	    PumaCannon_Texture = UIPackingImagePath.."ui-sniping-pcannon-1024.dds"

	    dofile("UI\\ingame_res.lua")

	    COUNT_BOUNDX = SCREEN_WIDTH / 2 - 74 / 2
	    COUNT_BOUNDY = SCREEN_HEIGHT / 4 - 25

	    MSG_APPEARX = 912
	    MSG_APPEARY = 173

	    MSG_BIRD_APPEARY = 85
	    MSG_DISAPPEARX = 112

	    RESULT_BOUNDX = SCREEN_CENTER_X - 180
	    RESULT_BOUNDY = RESULT_ORGY+74

	    CARD_ACT_BOUNDX = SCREEN_WIDTH - 98
	    CARD_ACT_BOUNDY = SCREEN_HEIGHT / 2 - 362 / 2

	    CARD_USE_BOUNDX = SCREEN_WIDTH - 148
	    CARD_USE_BOUNDY = CARD_ACT_BOUNDY - 10

	    CARD_OUT_BOUNDX = SCREEN_WIDTH - 98
	    CARD_OUT_BOUNDY = CARD_ACT_BOUNDY + 20

	    MULTI_BACK_BOUNDY = 107

	    CUTIN_CHR_BOUNDY = SCREEN_HEIGHT-128
	    RIGHT_CHR_BOUNDX1 = SCREEN_WIDTH+170
	    RIGHT_CHR_BOUNDX2 = SCREEN_WIDTH-170

	    CUTIN_CUT_BOUNDY = SCREEN_HEIGHT-64
	    RIGHT_CUT_BOUNDX1 = SCREEN_WIDTH+161
	    RIGHT_CUT_BOUNDX2 = SCREEN_WIDTH-161

	    CUTIN_TEXT_BOUNDY = SCREEN_HEIGHT-93
	    RIGHT_TEXT_BOUNDX1 = SCREEN_WIDTH+170
	    RIGHT_TEXT_BOUNDX2 = SCREEN_WIDTH-303

	    LEVEL_UP_BOUNDX = 792
	    LEVEL_UP_BOUNDY = 302

	    GET_TITLE_BOUNDX = 318
	    GET_TITLE_BOUNDY = 373

	    SKILL_EXPR_POSX = SCREEN_WIDTH - 105
	    SKILL_EXPR_POSY = SCREEN_HEIGHT - 128

	    ENEMY_BOUNDX = SCREEN_WIDTH / 2 - 120 / 2
	    ENEMY_BOUNDY = SCREEN_HEIGHT / 2 - 120 / 2

	    dofile("UI\\ingame_effect.lua")

	    CROSSHAIR_OFFSETX = SCREEN_WIDTH / 2 - 2
	    CROSSHAIR_OFFSETY = SCREEN_HEIGHT / 2 - 2

	    CARDSTAT_OFFSETX = SCREEN_WIDTH - 98
	    CARDSTAT_OFFSETY = CARD_ACT_BOUNDY

	    KILLLIST_OFFSETX = 5
	    KILLLIST_OFFSETY = 275

	    ESSENSE_SLOT_OFFSETY = 75

	    SCOREBOARD_OFFSETX = SCREEN_WIDTH / 2 - 780 / 2
	    SCOREBOARD_OFFSETY = SCREEN_HEIGHT / 2 - 272 / 2

	    CURRENTSCR_OFFSETX = SCREEN_WIDTH / 2 - 119
	    CURRENTSCR_OFFSETY = 2

	    GAME_CHAT_WIDTH = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 16
        if GAME_CHAT_WIDTH > 750 then
            GAME_CHAT_WIDTH = 750
        end

        GAME_CHAT_OFFX = SCREEN_WIDTH / 2 - GAME_CHAT_WIDTH / 2
	    GAME_CHAT_OFFY = SCREEN_HEIGHT - 113 

        CreateNullDialog(UI_IDD_NULLDLG, 0, 0, SCREEN_WIDTH, SCREEN_WIDTH, 7)

        -- Cross Hair
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_UP,
            CROSSHAIR_OFFSETX - 5,
            CROSSHAIR_OFFSETY - 22,
            14,
            17,
            2,
            GAME_RES_BASE + 39,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_DOWN,
            CROSSHAIR_OFFSETX - 5,
            CROSSHAIR_OFFSETY + 9,
            14,
            17,
            2,
            GAME_RES_BASE + 40,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_LEFT,
            CROSSHAIR_OFFSETX - 22,
            CROSSHAIR_OFFSETY - 5,
            17,
            14,
            2,
            GAME_RES_BASE + 41,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_RIGHT,
            CROSSHAIR_OFFSETX + 9,
            CROSSHAIR_OFFSETY - 5,
            17,
            14,
            2,
            GAME_RES_BASE + 42,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_CENTER,
            CROSSHAIR_OFFSETX,
            CROSSHAIR_OFFSETY,
            4,
            4,
            2,
            GAME_RES_BASE + 43,
            UIRECT_ONE
        )

        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_BULLLET,
            CROSSHAIR_OFFSETX + 4,
            CROSSHAIR_OFFSETY + 4,
            47,
            47,
            3,
            GAME_RES_BASE + 44,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSSHAIR_BULLLET_FULL_EFFECT,
            CROSSHAIR_OFFSETX + 4,
            CROSSHAIR_OFFSETY + 4,
            47,
            47,
            2,
            GAME_RES_BASE + 45,
            UIRECT_ONE
        )

        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_CROSS_HAIR_XMARK,
            CROSSHAIR_OFFSETX - 14,
            CROSSHAIR_OFFSETY - 14,
            32,
            32,
            1,
            GAME_RES_BASE + 72,
            UIRECT_ONE
        )

        -- Card Slot
        CreateGauge3(UI_IDD_NULLDLG, UI_IDG_CARD1_USING, CARDSTAT_OFFSETX, CARDSTAT_OFFSETY + 2, 86, 60, 1, GAME_RES_BASE + 5)
        CreateGauge3(UI_IDD_NULLDLG, UI_IDG_CARD2_USING, CARDSTAT_OFFSETX, CARDSTAT_OFFSETY + 70, 86, 60, 1, GAME_RES_BASE + 5)
        CreateGauge3(UI_IDD_NULLDLG, UI_IDG_CARD3_USING, CARDSTAT_OFFSETX, CARDSTAT_OFFSETY + 138, 86, 60, 1, GAME_RES_BASE + 5)
        CreateGauge3(UI_IDD_NULLDLG, UI_IDG_CARD4_USING, CARDSTAT_OFFSETX, CARDSTAT_OFFSETY + 206, 86, 60, 1, GAME_RES_BASE + 5)
        CreateGauge3(UI_IDD_NULLDLG, UI_IDG_CARD5_USING, CARDSTAT_OFFSETX, CARDSTAT_OFFSETY + 274, 86, 60, 1, GAME_RES_BASE + 5)

        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL1_COVER,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY,
            90,
            64,
            3,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        SetSpriteCount(UI_IDP_SKILL1_COVER, 0)
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL2_COVER,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 68,
            90,
            64,
            3,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        SetSpriteCount(UI_IDP_SKILL2_COVER, 0)
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL3_COVER,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 136,
            90,
            64,
            3,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        SetSpriteCount(UI_IDP_SKILL3_COVER, 0)
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL4_COVER,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 204,
            90,
            64,
            3,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        SetSpriteCount(UI_IDP_SKILL4_COVER, 0)
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL5_COVER,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 272,
            90,
            64,
            3,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        SetSpriteCount(UI_IDP_SKILL5_COVER, 0)

        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL1,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY,
            90,
            64,
            2,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL2,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 68,
            90,
            64,
            2,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL3,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 136,
            90,
            64,
            2,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL4,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 204,
            90,
            64,
            2,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_SKILL5,
            CARDSTAT_OFFSETX + 8,
            CARDSTAT_OFFSETY + 272,
            90,
            64,
            2,
            GAME_RES_BASE + 21,
            UIRECT_ONE
        )

        CreatePictureBox(UI_IDD_NULLDLG, UI_IDP_I_AM_VIP, SCREEN_WIDTH / 2 - 56, SCREEN_HEIGHT / 2 - 224, 112, 51, 2, GAME_RES_BASE + 22, UIRECT_ONE)
            CreateStatic(
                UI_IDD_NULLDLG,
                UI_IDS_KEY_ADVICE,
                0,
                199,
                SCREEN_WIDTH,
                14,
                GetText('Game', 'KEY_GUIDE_MAP_OBJ'),
                2,
                COMMON_RES_BASE + 9,
                UIRECT_NONE
            )

        SetVisible(UI_IDP_I_AM_VIP, FALSE)
        StaticTextDir(UI_IDS_KEY_ADVICE, TextDir_vCenter)
        SetVisible(UI_IDS_KEY_ADVICE, FALSE)

        CreateListView(
            UI_IDD_NULLDLG,
            UI_IDV_KILL,
            KILLLIST_OFFSETX,
            KILLLIST_OFFSETY,
            235,
            150,
            5,
            GAME_RES_BASE + 0,
            UIRECT_NONE
        )
        SetTextGap(UI_IDV_KILL, 0, 0)
        LV_AddColumn(
            UI_IDV_KILL,
            200,
            0xFFFFFF,
            0xFFFFFF,
            0xFFFFFF,
            0xFFFFFF,
            TextDir_vRight,
            FONT_OUTLINE,
            0,
            0,
            UIRECT_ONE,
            -1,
            -1,
            -1,
            -1
        )
        LV_AddColumn(
            UI_IDV_KILL,
            35,
            0x000000,
            0x000000,
            0x000000,
            0x000000,
            TextDir_vCenter,
            FONT_NORMAL,
            0,
            0,
            UIRECT_ONE,
            -1,
            -1,
            -1,
            -1
        )
        LV_AddColumn(
            UI_IDV_KILL,
            200,
            0xFFFFFF,
            0xFFFFFF,
            0xFFFFFF,
            0xFFFFFF,
            TextDir_vLeft,
            FONT_OUTLINE,
            0,
            0,
            UIRECT_ONE,
            -1,
            -1,
            -1,
            -1
        )
        LV_SetLineColumnGap(UI_IDV_KILL, 3, 5)

        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_HEADSHOT1,
            KILLLIST_OFFSETX,
            KILLLIST_OFFSETY + 28 * 0,
            35,
            25,
            4,
            GAME_RES_BASE + 69,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_HEADSHOT2,
            KILLLIST_OFFSETX,
            KILLLIST_OFFSETY + 28 * 1,
            35,
            25,
            4,
            GAME_RES_BASE + 69,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_HEADSHOT3,
            KILLLIST_OFFSETX,
            KILLLIST_OFFSETY + 28 * 2,
            35,
            25,
            4,
            GAME_RES_BASE + 69,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_HEADSHOT4,
            KILLLIST_OFFSETX,
            KILLLIST_OFFSETY + 28 * 3,
            35,
            25,
            4,
            GAME_RES_BASE + 69,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_NULLDLG,
            UI_IDP_HEADSHOT5,
            KILLLIST_OFFSETX,
            KILLLIST_OFFSETY + 28 * 4,
            35,
            25,
            4,
            GAME_RES_BASE + 69,
            UIRECT_ONE
        )

         CreateNullDialog(UI_IDD_BULLET_INFO, SCREEN_WIDTH - 175, SCREEN_HEIGHT - 90, 172, 80, 8)

        CreateNumberGroup(UI_IDD_BULLET_INFO, UI_IDN_BULLET_MAGAZINE, 0, 49, 171, 38, 1, GAME_RES_BASE + 0, UIRECT_ONE)
        NumberGroup_SetValue(UI_IDN_BULLET_MAGAZINE, 2, -9, 5)
        CreatePictureBox(UI_IDD_BULLET_INFO, UI_IDP_BULLET_ESSENSE, 171 - 36, 49, 36, 38, 1, GAME_RES_BASE + 13, UIRECT_ONE)
        CreatePictureBox(UI_IDD_BULLET_INFO, UI_IDP_BULLET_INFINITE, 171 - 68, 49, 68, 38, 1, GAME_RES_BASE + 14, UIRECT_ONE)
        CreatePictureBox(UI_IDD_BULLET_INFO, UI_IDP_BULLET_IMG, 90, 0, 80, 62, 5, GAME_RES_BASE + 15, UIRECT_ONE)

        CreateNullDialog(UI_IDD_HITMARK, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 6)
        CreatePictureBox(
            UI_IDD_HITMARK,
            UI_IDP_HITWARNING_TOP,
            SCREEN_CENTER_X - 166,
            SCREEN_CENTER_Y - 243,
            332,
            92,
            1,
            GAME_RES_BASE + 20,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_HITMARK,
            UI_IDP_HITWARNING_LEFT,
            SCREEN_CENTER_X - 365,
            SCREEN_CENTER_Y - 50,
            332,
            92,
            1,
            GAME_RES_BASE + 20,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_HITMARK,
            UI_IDP_HITWARNING_RIGHT,
            SCREEN_CENTER_X + 33,
            SCREEN_CENTER_Y - 50,
            332,
            92,
            1,
            GAME_RES_BASE + 20,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_HITMARK,
            UI_IDP_HITWARNING_BOTTOM,
            SCREEN_CENTER_X - 166,
            SCREEN_CENTER_Y + 151,
            332,
            92,
            1,
            GAME_RES_BASE + 20,
            UIRECT_ONE
        )

        CreateNullDialog(UI_IDD_ESSENSE_SLOT, 0, ESSENSE_SLOT_OFFSETY, SCREEN_WIDTH, 73, 2)
        CreatePictureBox(
            UI_IDD_ESSENSE_SLOT,
            UI_IDP_ESSENSE_SLOT_BOX,
            SCREEN_CENTER_X - 32,
            0,
            64,
            46,
            5,
            GAME_RES_BASE + 0,
            UIRECT_ONE
        )
        CreatePictureBox(
            UI_IDD_ESSENSE_SLOT,
            UI_IDP_ESSENSE_SLOT_IMG,
            SCREEN_CENTER_X - 32,
            0,
            64,
            46,
            4,
            GAME_RES_BASE + 23,
            UIRECT_ONE
        )
        CreateStatic(
            UI_IDD_ESSENSE_SLOT,
            UI_IDS_ESSENSE_SLOT_MSG,
            SCREEN_CENTER_X - 50,
            49,
            100,
            21,
            STR_NULL,
            2,
            COMMON_RES_BASE + 9,
            UIRECT_NONE
        )
        StaticTextDir(UI_IDS_ESSENSE_SLOT_MSG, TextDir_Center)

        CreateNullDialog(UI_IDD_SNIPING, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 10)

        CreatePictureBox(UI_IDD_SNIPING, UI_IDP_SNIPING_CENTER, (SCREEN_WIDTH - 640) / 2, (SCREEN_HEIGHT - 460) / 2, 640, 460, 4, GAME_RES_BASE + 32, UIRECT_ONE)
        CreatePictureBox(UI_IDD_SNIPING, UI_IDP_SNIPING_TOP, 0, 0, SCREEN_WIDTH, 282, 4, GAME_RES_BASE + 31, UIRECT_ONE)
        CreatePictureBox(UI_IDD_SNIPING, UI_IDP_SNIPING_LEFT, 0, (SCREEN_HEIGHT - 460) / 2, 320, 460, 4, GAME_RES_BASE + 31, UIRECT_ONE)
        CreatePictureBox(UI_IDD_SNIPING, UI_IDP_SNIPING_RIGHT, SCREEN_WIDTH - ((SCREEN_WIDTH - 640) / 2), (SCREEN_HEIGHT - 460) / 2, 320, 460, 4, GAME_RES_BASE + 31, UIRECT_ONE)
        CreatePictureBox(
            UI_IDD_SNIPING,
            UI_IDP_SNIPING_BOTTOM,
            0,
            742,
            SCREEN_WIDTH,
            282,
            4,
            GAME_RES_BASE + 31,
            UIRECT_ONE
         )

        HideDialog(UI_IDD_SNIPING)

        CreateDialog(UI_IDD_ONELINE_MSG, 0, 210, SCREEN_WIDTH, 19, NULL_WINDOW_TITLE, 5, GAME_RES_BASE + 2, UIRECT_ONE)
        CreateStatic(
            UI_IDD_ONELINE_MSG,
            UI_IDS_ONELINE_MSG,
            0,
            5,
            SCREEN_WIDTH,
            19,
            STR_NULL,
            2,
            COMMON_RES_BASE + 9,
            UIRECT_NONE
        )
        StaticTextDir(UI_IDS_ONELINE_MSG, TextDir_Center) )"

        ,

        R"(

        -- Skill Help
        if (SCREEN_WIDTH == 800) then
            CreateNullDialog(UI_IDD_SKILL_HEHLP, 282, 138, 236, 31, 7)
        elseif (SCREEN_WIDTH == 1080) then
            CreateNullDialog(UI_IDD_SKILL_HEHLP, 394, 142, 236, 31, 7)
        else
            CreateNullDialog(UI_IDD_SKILL_HEHLP, 394, 142, 236, 31, 7)
        end
        CreatePictureBox(UI_IDD_SKILL_HEHLP, UI_IDP_SKILL_HELP, 0, 0, 236, 31, 4, GAME_RES_BASE + 38, UIRECT_ONE)
        HideDialog(UI_IDD_SKILL_HEHLP)

        -- Skill Help CutIn
        CreateDialog(UI_IDD_SKILL_HELP_CUTIN, 0, 1500, 266, 40, NULL_WINDOW_TITLE, 5, GAME_RES_BASE + 3, UIRECT_NINE)
        CreateListBox(UI_IDD_SKILL_HELP_CUTIN, UI_IDL_SKILL_HELP, 7, 8, 216, 80, 0, COMMON_RES_BASE + 2, UIRECT_NONE)
        ControlTextDir(UI_IDL_SKILL_HELP, TextDir_Left)

	    CreateNullDialog(UI_IDD_MINIMAP, SCREEN_WIDTH - 143, 5, 140, 144, 1)

	    CreateBlendingPictureBox(UI_IDD_MINIMAP ,UI_IDP_MINIMAP, 0 , 0 , 140 , 144 , 12, 10, 116 , 116 , 5, GAME_RES_BASE+10, UIRECT_ONE)

	    SetVertexColor(UI_IDP_MINIMAP, 154, 255, 255, 255)

        CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK1, 70, 72, 3, GAME_RES_BASE + 7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK2, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK3, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK4, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK5, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK6, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK7, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK8, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK9, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK10, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK11, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK12, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK13, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK14, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK15, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK16, 70, 72, 3, GAME_RES_BASE+7)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_PLMARK17, 70, 72, 3, GAME_RES_BASE+7)

	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_MYMARK, 70, 66, 1, GAME_RES_BASE+8)

	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_OBJMARK1, 70, 66, 2, GAME_RES_BASE+9)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_OBJMARK2, 70, 66, 2, GAME_RES_BASE+9)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_OBJMARK3, 70, 66, 2, GAME_RES_BASE+9)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_OBJMARK4, 70, 66, 2, GAME_RES_BASE+9)
	    CreateTextureAdaptivePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_OBJMARK5, 70, 66, 2, GAME_RES_BASE+9)

	    CreatePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_BG, 0, 0, 140, 144, 2, GAME_RES_BASE+6, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_MINIMAP, UI_IDP_MINIMAP_OVERALL, 103, 108, 37, 39, 1, GAME_RES_BASE+71, UIRECT_ONE )
	    HideDialog(UI_IDD_MINIMAP)

	    CreateDialog(UI_IDD_WORLDMAP, SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 20, 40, 40, NULL_WINDOW_TITLE, 4, GAME_RES_BASE+5, UIRECT_NINE)

	    CreatePictureBox(UI_IDD_WORLDMAP , UI_IDP_WORLDMAP_PIC, 19, 19 ,2, 2, 3, GAME_RES_BASE+37, UIRECT_ONE)
	    SetVertexColor(UI_IDP_WORLDMAP_PIC, 154, 255, 255, 255)
	    SetVisible(UI_IDP_WORLDMAP_PIC, FALSE)
		
	    for i = 0, 16, 1 do
		    ID_OFFSET = UI_IDS_WORLDMAP_NICK1+i
		    CreateStatic(UI_IDD_WORLDMAP, ID_OFFSET, 0, 0, 200, 16, "", 3, COMMON_RES_BASE+28, UIRECT_NONE)
			    ControlTextDir(ID_OFFSET, TextDir_Center)
	    end
	
	    for i = 0, 16, 1 do
		    ID_OFFSET = UI_IDP_WORLDMAP_USERMARK1+i
		    CreatePictureBox(UI_IDD_WORLDMAP, ID_OFFSET, 0, 0, 8, 8, 3, GAME_RES_BASE+7, UIRECT_ONE)
	    end	
	
	    CreateTextureAdaptivePictureBox(UI_IDD_WORLDMAP, UI_IDP_WORLDMAP_MYMARK, 70, 66, 1, GAME_RES_BASE+8)
	
	    HideDialog(UI_IDD_WORLDMAP)

	    CreateNullDialog(UI_IDD_WEAPON_SLOT , 0 , 0 , 256 , 46 , 9 )

	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT_BOX1, 3, 3, 64, 46, 5, GAME_RES_BASE+0, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT_BOX2, 69, 3, 64, 46, 5, GAME_RES_BASE+0, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT_BOX3, 135, 3, 64, 46, 5, GAME_RES_BASE+0, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT_BOX4, 201, 3, 64, 46, 5, GAME_RES_BASE+0, UIRECT_ONE )

	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT1, 3, 3, 64, 46, 5, GAME_RES_BASE+1, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT2, 69, 3, 64, 46, 5, GAME_RES_BASE+1, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT3, 135, 3, 64, 46, 5, GAME_RES_BASE+1, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_WEAPON_SLOT, UI_IDP_WEAPON_SLOT4, 201, 3, 64, 46, 5, GAME_RES_BASE+1, UIRECT_ONE )

	    CreateDialog(UI_IDD_PLAYER_STAT, 3, SCREEN_HEIGHT - 67, 163, 61, NULL_WINDOW_TITLE, 5, GAME_RES_BASE+0, UIRECT_NINE)	

	    CreatePictureBox(UI_IDD_PLAYER_STAT, UI_IDP_PLAYER_ICON, 5, 3, 17, 17, 5, GAME_RES_BASE+3, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_PLAYER_STAT, UI_IDP_PLAYER_ICON, 5, 22, 17, 17, 5, GAME_RES_BASE+4, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_PLAYER_STAT, UI_IDP_PLAYER_ICON, 5, 41, 17, 17, 5, GAME_RES_BASE+5, UIRECT_ONE )

	    CreatePictureBox(UI_IDD_PLAYER_STAT, UI_IDP_PLAYER_GAUGE_BG, 26, 3, 134, 17, 5, GAME_RES_BASE+2, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_PLAYER_STAT, UI_IDP_PLAYER_GAUGE_BG, 26, 22, 134, 17, 5, GAME_RES_BASE+2, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_PLAYER_STAT, UI_IDP_PLAYER_GAUGE_BG, 26, 41, 134, 17, 5, GAME_RES_BASE+2, UIRECT_ONE )

	    CreateGauge2(UI_IDD_PLAYER_STAT, UI_IDG_PLAYER_HP, 28, 5, 130, 13, 3 ,GAME_RES_BASE+0)
	    CreateGauge2(UI_IDD_PLAYER_STAT, UI_IDG_PLAYER_SP, 28, 24, 130, 13, 3 ,GAME_RES_BASE+1)
	    CreateGauge2(UI_IDD_PLAYER_STAT, UI_IDG_PLAYER_STM, 28, 43, 130, 13, 3 ,GAME_RES_BASE+2)
	    CreateGauge2(UI_IDD_PLAYER_STAT, UI_IDG_PLAYER_HP_DEC, 28, 5, 130, 13, 4 ,GAME_RES_BASE+3)
	    CreateGauge2(UI_IDD_PLAYER_STAT, UI_IDG_PLAYER_SP_DEC, 28, 24, 130, 13, 4 ,GAME_RES_BASE+3)
	    CreateGauge2(UI_IDD_PLAYER_STAT, UI_IDG_PLAYER_STM_DEC, 28, 43, 130, 13, 4 ,GAME_RES_BASE+3)

	    CreateNumberBox(UI_IDD_PLAYER_STAT, UI_IDN_PLAYER_HP, 79, 7,  27 , 9 , 2, GAME_RES_BASE+0, UIRECT_ONE)
	    SetVertexColor(UI_IDN_PLAYER_HP, 255, 255, 255, 255)
	    ControlTextDir(UI_IDN_PLAYER_HP, TextDir_vCenter)
	    NumberBox_SetValue( UI_IDN_PLAYER_HP, 0, -2 )
	    CreateNumberBox(UI_IDD_PLAYER_STAT, UI_IDN_PLAYER_SP, 79, 26,  27 , 9 , 2, GAME_RES_BASE+0, UIRECT_ONE)
	    SetVertexColor(UI_IDN_PLAYER_SP, 255, 255, 255, 255)
	    ControlTextDir(UI_IDN_PLAYER_SP, TextDir_vCenter)
	    NumberBox_SetValue( UI_IDN_PLAYER_SP, 0, -2 )
	    CreateNumberBox(UI_IDD_PLAYER_STAT, UI_IDN_PLAYER_STM, 79, 45,  27 , 9 , 2, GAME_RES_BASE+0, UIRECT_ONE)
	    SetVertexColor(UI_IDN_PLAYER_STM, 255, 255, 255, 255)
	    ControlTextDir(UI_IDN_PLAYER_STM, TextDir_vCenter)
	    NumberBox_SetValue( UI_IDN_PLAYER_STM, 0, -2 )

	    CreateNullDialog(UI_IDD_PLAYER_PVESTAT, 3, SCREEN_HEIGHT - 66, 163, 108, 5)

	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVEBACK, 0, 0, 163, 64, 6, GAME_RES_BASE+78, UIRECT_NINE)
	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVEBACK, 0, 66, 163, 42, 6, GAME_RES_BASE+78, UIRECT_NINE)

	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVECOIN, 4, 4, 123, 18, 5, PVE_RES_BASE+19, UIRECT_ONE )

	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVEICON, 5, 68, 17, 17, 5, GAME_RES_BASE+3, UIRECT_ONE )

	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVEICON, 5, 87, 17, 17, 5, GAME_RES_BASE+5, UIRECT_ONE )

	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVEGAUGE_BG, 26, 68, 134, 17, 5, GAME_RES_BASE+2, UIRECT_ONE )
	    CreatePictureBox(UI_IDD_PLAYER_PVESTAT, UI_IDP_PLAYER_PVEGAUGE_BG, 26, 87, 134, 17, 5, GAME_RES_BASE+2, UIRECT_ONE )

	    CreateGauge2(UI_IDD_PLAYER_PVESTAT, UI_IDG_PLAYER_PVEHP, 28, 70, 130, 13, 3, GAME_RES_BASE+0)
	    CreateGauge2(UI_IDD_PLAYER_PVESTAT, UI_IDG_PLAYER_PVESTM, 28, 89, 130, 13, 3, GAME_RES_BASE+2)
	    CreateGauge2(UI_IDD_PLAYER_PVESTAT, UI_IDG_PLAYER_PVEHP_DEC, 28, 70, 130, 13, 4, GAME_RES_BASE+3)
	    CreateGauge2(UI_IDD_PLAYER_PVESTAT, UI_IDG_PLAYER_PVESTM_DEC, 28, 89, 130, 13, 4, GAME_RES_BASE+3)

	    CreateNumberBox(UI_IDD_PLAYER_PVESTAT, UI_IDN_PLAYER_PVEHP, 79, 72, 27, 9, 2, GAME_RES_BASE+0, UIRECT_ONE)
	    SetVertexColor(UI_IDN_PLAYER_PVEHP, 255, 255, 255, 255)
	    ControlTextDir(UI_IDN_PLAYER_PVEHP, TextDir_vCenter)
	    NumberBox_SetValue(UI_IDN_PLAYER_PVEHP, 0, -2)
	    CreateNumberBox(UI_IDD_PLAYER_PVESTAT, UI_IDN_PLAYER_PVESTM, 79, 91, 27, 9, 2, GAME_RES_BASE+0, UIRECT_ONE)
	    SetVertexColor(UI_IDN_PLAYER_PVESTM, 255, 255, 255, 255)
	    ControlTextDir(UI_IDN_PLAYER_PVESTM, TextDir_vCenter)
	    NumberBox_SetValue(UI_IDN_PLAYER_PVESTM, 0, -2)
		
	    CreateNumberBox(UI_IDD_PLAYER_PVESTAT, UI_IDN_PLAYER_PVECOIN, 94, 23, 63, 38, 2, GAME_RES_BASE+1, UIRECT_ONE)
	    SetVertexColor(UI_IDN_PLAYER_PVECOIN, 255, 255, 255, 255)
	    ControlTextDir(UI_IDN_PLAYER_PVECOIN, TextDir_vRight)
	    NumberBox_SetValue(UI_IDN_PLAYER_PVECOIN, 0, -2)	
	
	    CreateNullDialog( UI_IDD_LEFT_CUTIN , 0 , 0 , 200 , 230 , -1 )
	    CreatePictureBox(UI_IDD_LEFT_CUTIN , UI_IDP_LEFT_CUTIN_BACK, 0 ,0 , 200 ,230 , 8 , GAME_RES_BASE+34, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_LEFT_CUTIN , UI_IDP_LEFT_CUTIN_CANVAS, 0 ,0 , 189 ,219 , 7 , GAME_RES_BASE+33, UIRECT_ONE)
		    SetVisible(UI_IDP_LEFT_CUTIN_CANVAS, FALSE)
	    CreatePanoramaPictureBox(UI_IDD_LEFT_CUTIN , UI_IDP_LEFT_CUTIN_EFFECT, 0 ,0 , 189 ,219 , 5 , GAME_RES_BASE+35, UIRECT_ONE)

	    CreateStatic(UI_IDD_LEFT_CUTIN , UI_IDS_LEFT_CUTIN_KILLER,5 ,8 , 189 , 19 , "" , 6 ,COMMON_RES_BASE+9,UIRECT_NONE)
        ControlTextDir(UI_IDS_LEFT_CUTIN_KILLER, TextDir_Center)

	    CreateNullDialog( UI_IDD_RIGHT_CUTIN, SCREEN_WIDTH - 200, 0, 200, 230, -1)

	    CreatePictureBox(UI_IDD_RIGHT_CUTIN , UI_IDP_RIGHT_CUTIN_BACK, 0 ,0 , 200 ,230 , 8 , GAME_RES_BASE+33, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_RIGHT_CUTIN , UI_IDP_RIGHT_CUTIN_CANVAS, 11 ,0 , 189 ,219 , 7 , GAME_RES_BASE+34, UIRECT_ONE)
		    SetVisible(UI_IDP_RIGHT_CUTIN_CANVAS, FALSE)
	    CreatePanoramaPictureBox(UI_IDD_RIGHT_CUTIN , UI_IDP_RIGHT_CUTIN_EFFECT, 11 ,0 , 189 ,219 , 6 , GAME_RES_BASE+35, UIRECT_ONE)

	    HideDialog(UI_IDD_LEFT_CUTIN)
	    HideDialog(UI_IDD_RIGHT_CUTIN)

	    UI_IDD_GAME_HELP = 31000
	    UI_IDP_GAME_HELP = UI_IDD_GAME_HELP+1
	    UI_IDC_GAME_HELP_CAPTION = UI_IDD_GAME_HELP+2
	    UI_IDP_GAME_HELP_CAPTION = UI_IDD_GAME_HELP+3

	    CreateDialog(UI_IDD_GAME_HELP, SCREEN_WIDTH / 2 - 779 / 2, SCREEN_HEIGHT / 2 - 384 / 2, 779, 384, NULL_WINDOW_TITLE, -2, LEGACY_COMMON_RES_BASE+0, UIRECT_NINE)

		    EnableSkinColor(UI_IDD_GAME_HELP)
		    CreateCaptionBar(UI_IDD_GAME_HELP , UI_IDC_GAME_HELP_CAPTION, 14 , -22 , 112 , 24 ,4, LEGACY_COMMON_RES_BASE+0 , UIRECT_THREE)
		    CreatePictureBox(UI_IDD_GAME_HELP , UI_IDP_GAME_HELP_CAPTION, 16, 2 ,108, 22, 3, GAME_RES_BASE+37, UIRECT_ONE)
		    CreatePictureBox(UI_IDD_GAME_HELP , UI_IDP_GAME_HELP, 20 ,39 , 739 ,347 , 7 , GAME_RES_BASE+36, UIRECT_ONE)
	
	    HideDialog(UI_IDD_GAME_HELP )

	    CreateNullDialog( UI_IDD_SELECT_ENEMY , SCREEN_WIDTH / 2 - 338 / 2, SCREEN_HEIGHT / 2 - 397 / 2, 338 , 397 , -1 )
		    CreatePictureBox(UI_IDD_SELECT_ENEMY , UI_IDP_SELECT_ENEMY, 0, 0 ,338, 397, 3, GAME_RES_BASE+75, UIRECT_ONE)

	    CreateNullDialog(UI_IDD_GAME_PVENAVI, SCREEN_WIDTH - 175, SCREEN_HEIGHT - 365, 170, 365, -1)

	    CreatePictureBox(UI_IDD_GAME_PVENAVI, UI_IDP_GAME_PVENAVI_HELPER, 44, 214, 119, 151, 3, GAME_RES_BASE+79, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_PVENAVI, UI_IDP_GAME_PVENAVI_BUBBLE, 0, 111, 170, 120, 3, GAME_RES_BASE+80, UIRECT_NINE)
	    CreateStatic(UI_IDD_GAME_PVENAVI, UI_IDS_GAME_PVENAVI_DESC, 7, 118, 156, 106, "", 3, COMMON_RES_BASE+9, UIRECT_NONE)

	    CreateNullDialog(UI_IDD_GAME_EVENTER, 0, 51, 617, 44, 10)
	    CreatePictureBox(UI_IDD_GAME_EVENTER, UI_IDP_GAME_EVENTER_PICTURE, 4, 4, 35, 35, 4, PVE_RES_BASE+23, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_EVENTER, UI_IDP_GAME_EVENTER_PICBG, 0, 0, 46, 44, 5, PVE_RES_BASE+27, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_EVENTER, UI_IDP_GAME_EVENTER_TAG, 50, 4, 60, 14, 4, PVE_RES_BASE+24, UIRECT_ONE)

	    CreatePictureBox(UI_IDD_GAME_EVENTER, UI_IDP_GAME_EVENTER_HPCASE, 43, 19, 572, 22, 4, PVE_RES_BASE+26, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_EVENTER, UI_IDP_GAME_EVENTER_HPSHADOW, 45, 21, 572, 22, 5, PVE_RES_BASE+28, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_EVENTER, UI_IDP_GAME_EVENTER_MAXHP, 43, 20, 570, 19, 3, PVE_RES_BASE+25, UIRECT_ONE)
	    CreateGauge(UI_IDD_GAME_EVENTER, UI_IDG_GAME_EVENTER_CURHP, 43, 20, 570, 19, 2, PVE_RES_BASE+0)

	    CreateStatic(UI_IDD_GAME_EVENTER, UI_IDS_GAME_EVENTER_CURHP, 532, 23, 41, 14, "Cur/", 1, COMMON_RES_BASE+8, UIRECT_NONE)
        ControlTextDir(UI_IDS_GAME_EVENTER_CURHP, TextDir_vRight)
	    CreateStatic(UI_IDD_GAME_EVENTER, UI_IDS_GAME_EVENTER_MAXHP, 573, 23, 35, 14, "Max", 1, COMMON_RES_BASE+8, UIRECT_NONE)
        ControlTextDir(UI_IDS_GAME_EVENTER_MAXHP, TextDir_vLeft))"

        ,

        R"(CreateNullDialog(UI_IDD_GAME_WAVEWARNING, SCREEN_WIDTH / 2 - 639 / 2, 202, 639, 108, 10)

	    CreatePictureBox(UI_IDD_GAME_WAVEWARNING, UI_IDP_GAME_WAVEWARNING_WAVE, 0, 22, 421, 62, 8, GAME_RES_BASE+85, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_WAVEWARNING, UI_IDP_GAME_WAVEWARNING_WAVEBACK, 0, 0, 639, 108, 10, GAME_RES_BASE+89, UIRECT_ONE)
	    CreateNumberBox(UI_IDD_GAME_WAVEWARNING, UI_IDN_GAME_WAVEWARNING_WAVE, 409, 22, 160, 62, 8, GAME_RES_BASE+8, UIRECT_ONE)
	    ControlTextDir(UI_IDN_GAME_WAVEWARNING_WAVE, TextDir_Center)

	    CreateNullDialog(UI_IDD_GAME_COINTAB, SCREEN_WIDTH - 71, SCREEN_HEIGHT / 3 - 49, 68, 349, 10)	

	    CreatePictureBox(UI_IDD_GAME_COINTAB, UI_IDP_GAME_COINTAB_GOLD, 27, 0, 41, 43, 10, GAME_RES_BASE+86, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_COINTAB, UI_IDP_GAME_COINTAB_SILVER, 27, 131, 41, 43, 10, GAME_RES_BASE+87, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_COINTAB, UI_IDP_GAME_COINTAB_BRONZE, 27, 262, 41, 43, 10, GAME_RES_BASE+88, UIRECT_ONE)

	    CreateNumberBox(UI_IDD_GAME_COINTAB,  UI_IDN_GAME_COINTAB_GOLD, 0, 49, 67, 38, 10, GAME_RES_BASE+1, UIRECT_ONE)
		    ControlTextDir(UI_IDN_GAME_COINTAB_GOLD, TextDir_Right)
	    CreateNumberBox(UI_IDD_GAME_COINTAB,  UI_IDN_GAME_COINTAB_SILVER, 0, 180, 67, 38, 10, GAME_RES_BASE+1, UIRECT_ONE)
		    ControlTextDir(UI_IDN_GAME_COINTAB_SILVER, TextDir_Right)
	    CreateNumberBox(UI_IDD_GAME_COINTAB,  UI_IDN_GAME_COINTAB_BRONZE, 0, 311, 67, 38, 10, GAME_RES_BASE+1, UIRECT_ONE)
		    ControlTextDir(UI_IDN_GAME_COINTAB_BRONZE, TextDir_Right)	

	    CreateNullDialog(UI_IDD_GAME_PVE_FAIL, SCREEN_WIDTH / 2 - 639 / 2, 202, 639, 108, 10)

	    CreatePictureBox(UI_IDD_GAME_PVE_FAIL, UI_IDP_GAME_PVE_FAIL_BACK, 0, 0, 639, 108, 10, GAME_RES_BASE+89, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_PVE_FAIL, UI_IDP_GAME_PVE_FAIL_WIPEDOUT, 92, 21, 461, 69, 9, PVE_RES_BASE+20, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_PVE_FAIL, UI_IDP_GAME_PVE_FAIL_TIMEOUT, 92, 21, 461, 69, 9, PVE_RES_BASE+21, UIRECT_ONE)
	    CreatePictureBox(UI_IDD_GAME_PVE_FAIL, UI_IDP_GAME_PVE_FAIL_DESTROYED, 92, 5, 461, 98, 9, PVE_RES_BASE+22, UIRECT_ONE)

	    HideDialog(UI_IDD_GAME_PVE_FAIL)	

	    dofile("UI\\game_nametag.lua")

	    dofile("UI\\current_score.lua")
	    dofile("UI\\scoreboard.lua")
	    dofile("UI\\game_chatting.lua")

	    dofile("UI\\lettering.lua")
	    dofile("UI\\game_result.lua")
	    dofile("UI\\game_pveresult.lua")
	    dofile("UI\\quest.lua")

	    AllDialogSortingLayer()

	)" };
}