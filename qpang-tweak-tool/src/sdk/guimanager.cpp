#include "guimanager.h"

GUIManager* GUIManager::getInstance() {
#ifdef V2013
	return (GUIManager*)0x7c7860;
#else
	return (GUIManager*)0x7c4860;
#endif
}

UIElement* GUIManager::findElementById(int id) {
#ifdef V2013
	static const auto findElementByIdFn = (UIElement*(__thiscall*)(void*, int))(0x5ced20);
#else
	static const auto findElementByIdFn = (UIElement*(__thiscall*)(void*, int))(0x5cd1f0);
#endif

	return findElementByIdFn(this, id);
}

void GUIManager::setGlobalColor(DWORD color) {
#ifdef V2013
	static auto setGlobalColorFn = (void(__thiscall*)(void*, DWORD))(0x5cf090);
#else
	static auto setGlobalColorFn = (void(__thiscall*)(void*, DWORD))(0x5cd560);
#endif

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