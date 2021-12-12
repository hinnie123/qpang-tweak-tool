#pragma once

#include <dinput.h>

#include "render/ui.h"

namespace hooks {
	typedef HRESULT(__stdcall* tGetDeviceData)(IDirectInputDevice8*, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
	tGetDeviceData oGetDeviceData = nullptr;

	HRESULT __stdcall hkGetDeviceData(IDirectInputDevice8* pThis, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
	{
		HRESULT retValue = oGetDeviceData(pThis, cbObjectData, rgdod, pdwInOut, dwFlags);

		if (ui::renderWindow) {
			// This blocks mouse movement to the game
			memset(rgdod, 0, sizeof(DIDEVICEOBJECTDATA) * *pdwInOut);
		}

		return retValue;
	}
}