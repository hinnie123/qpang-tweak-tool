#include "guimanager.h"

GUIManager* GUIManager::getInstance() {
	return (GUIManager*)0x7c4860;
}

UIElement* GUIManager::findElementById(int id) {
	static const auto findElementByIdFn = (UIElement*(__thiscall*)(void*, int))(0x5cd1f0);
	return findElementByIdFn(this, id);
}

void GUIManager::setGlobalColor(DWORD color) {
	static auto setGlobalColorFn = (void(__thiscall*)(void*, DWORD))(0x5cd560);
	setGlobalColorFn(this, color);

	// Or, rebuild:
	/*this->globalColor = color;

	int numElements = this->getNumElements();
	for (size_t i = 0; i < numElements; ++i) {
		UIElement* element = this->uiElements[i];
		if (!element)
			continue;

		element->setColor(this->globalColor);
	}*/
}

int GUIManager::getNumElements() {
	return ((uintptr_t)this->lastElementPtr - (uintptr_t)this->uiElements) / 4;
}