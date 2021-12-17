#pragma once

#include "defs.h"

enum class eUIState : int {
	UNKNOWN,
	LOGIN,
	WAITROOM,
	GAME,
	LOADING,
	TUTORIAL,
	SQUARE
};

enum class eUIElements : int {
	UI_IDD_WEAPON_SLOT = 25000,
	UI_IDD_PLAYER_STAT = 25100,
	UI_IDD_PLAYER_PVESTAT = 25120,
	UI_IDD_MINIMAP = 25150,
	UI_IDD_NULLDLG = 30000,
	UI_IDD_HITMARK = 30090,
	UI_IDD_BULLET_INFO = 30100,
	UI_IDD_CURRENT_SCORE = 30200,
	UI_IDD_SCORE = 30300,
	UI_IDD_CHATTING = 30550,
	UI_IDD_ESSENSE_SLOT = 30600,
	UI_IDD_SNIPING = 30800,
	UI_IDD_ONELINE_MSG = 30930,
	UI_IDD_SKILL_HEHLP = 31100,
	UI_IDD_WORLDMAP = 36400,
	UI_IDD_GAME_PVE_FAIL = 38350,

	UI_IDD_LOGIN = 100
};

class UIElement {
public:
	PAD(0xf0);
	int startX;
	int startY;
	int endX;
	int endY;
	int id;
	PAD(0x8);
	bool shouldDraw;
public:
	bool hasId(eUIElements id) {
		return (eUIElements)this->id == id;
	}

	void setDimensions(int width, int height) {
		GetVirtualFunc<void(__thiscall*)(void*, int, int)>(this, 3)(this, width, height);
	}

	void setPos(float pos[3]) {
		GetVirtualFunc<void(__thiscall*)(void*, float*)>(this, 17)(this, pos);
	}

	void setColor(DWORD color) {
		GetVirtualFunc<void(__thiscall*)(void*, DWORD)>(this, 65)(this, color);
	}
};

class GUIManager {
public:
	void* vtable;
	UIElement** uiElements;
	UIElement** lastElementPtr;
	PAD(0x1c8);
	DWORD globalColor;
public:
	static GUIManager* getInstance();
	UIElement* findElementById(int id);
	void setGlobalColor(DWORD color);

	int getNumElements();
};