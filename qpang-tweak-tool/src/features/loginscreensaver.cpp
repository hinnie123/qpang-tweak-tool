#include "loginscreensaver.h"

#include <d3d9.h>

#include "imgui/imgui.h"

#include "sdk/guimanager.h"

#include "helpers/globals.h"
#include "helpers/utils.h"

#include "features/resolution.h"
#include "features/gui.h"

namespace features {
	const float loginWidth = 240.f / 2.f;
	const float loginHeight = 180.f / 2.f;

	float x = 1.f;
	float y = 1.f;

	float xSpeed = 150.f;
	float ySpeed = 150.f;

	float r = 255.f;
	float g = 255.f;
	float b = 255.f;

	UIElement* loginDialog = nullptr;

	UIElement* findLoginDialog() {
		// Loop all ui elements to find the login element
		auto uiManager = GUIManager::getInstance();
		if (!uiManager)
			return nullptr;

		for (size_t i = 0; i < uiManager->getNumElements(); ++i) {
			auto uiElement = uiManager->uiElements[i];
			if (!uiElement)
				continue;

			// This is the login dialog
			if (uiElement->hasId(eUIElements::UI_IDD_LOGIN)) {
				return uiElement;
			}
		}

		return nullptr;
	}

	void randomizeColor() {
		r = utils::randomFloat(100.f, 255.f);
		g = utils::randomFloat(100.f, 255.f);
		b = utils::randomFloat(100.f, 255.f);
	}

	void setup() {
		loginDialog = findLoginDialog();
		if (!loginDialog)
			return;

		x = utils::randomFloat(0.f, features::targetWidth - loginWidth);
		y = utils::randomFloat(0.f, features::targetHeight - loginHeight);

		randomizeColor();
	}

	bool didResetColor = false;
	void loginScreenSaver() {
		// Only try to do this when you're in the login menu
		if (globals::currentUiState != eUIState::LOGIN) {
			// Set the color to what the user has configured, instead of the color
			// that was being generated and used by this screensaver
			if (!didResetColor) {
				utils::setUiColor(features::uiColor);
				didResetColor = true;
			}
			
			return;
		}

		if (loginDialog == nullptr) {
			setup();
			return;
		}

		float deltaTime = ImGui::GetIO().DeltaTime;
		x += xSpeed * deltaTime;
		y += ySpeed * deltaTime;

		if (x + loginWidth >= features::targetWidth) {
			xSpeed = -xSpeed;
			x = features::targetWidth - loginWidth;
			randomizeColor();
		} else if (x <= loginWidth) {
			xSpeed = -xSpeed;
			x = loginWidth;
			randomizeColor();
		}

		if (y + loginHeight >= features::targetHeight) {
			ySpeed = -ySpeed;
			y = features::targetHeight - loginHeight;
			randomizeColor();
		} else if (y <= loginHeight) {
			ySpeed = -ySpeed;
			y = loginHeight;
			randomizeColor();
		}

		float pos[3] = { x, y + 11.f, 0.f };
		loginDialog->setPos(pos);

		GUIManager::getInstance()->setGlobalColor(D3DCOLOR_RGBA((int)r, (int)g, (int)b, 255));
	}
}