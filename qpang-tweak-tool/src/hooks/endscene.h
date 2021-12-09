#pragma once

#include "render/ui.h"

namespace hooks {
	typedef HRESULT(__stdcall* tEndscene)(IDirect3DDevice9*);
	inline tEndscene oEndscene = nullptr;

	HRESULT __stdcall hkEndscene(IDirect3DDevice9* device) {
		if (!ui::didInit) {
			ui::init(device);
			ui::didInit = true;
		}

		ui::begin();
		ui::render();
		ui::end();

		return oEndscene(device);
	}
}
