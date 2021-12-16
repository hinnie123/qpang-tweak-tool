#pragma once

#include "defs.h"

enum eUIElements {
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
	UI_IDD_GAME_PVE_FAIL = 38350
};

class UIElement {
public:
	PAD(0x100);
	int id;
	PAD(0x8);
	bool bDraw;
public:
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