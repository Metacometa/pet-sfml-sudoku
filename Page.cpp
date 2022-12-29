#include "Page.h"

//Contrcutors / Destructors
Page::Page() {
}

Page::~Page() {
	for (auto* i : interfaceComponents)
		delete i;
}

//Functions
void Page::addButton(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name) {
	interfaceComponents.push_back(new Button(texture, pos, name));
}

void Page::addImage(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name) {
	interfaceComponents.push_back(new Image(texture, pos, name));
}

void Page::addField(const sf::Vector2f& pos, InterfaceBlock name) {
	interfaceComponents.push_back(new Field(pos, name));
}

InterfaceBlock Page::updateInterfaceComponents(const sf::Vector2f& mousePos, const bool &isLeftButtonPressed) {
	for (auto* i : interfaceComponents) {
		i->update(mousePos);

		if (i->isPointed(mousePos) && isLeftButtonPressed) {
			return i->getInterfaceBlock();
			//switchPage(i->getInterfaceBlock(), page, window);
		}
	}
	return InterfaceBlock::NONE;;
}

void Page::renderInterfaceComponents(sf::RenderTarget* target) {
	for (auto *i : interfaceComponents)
		i->render(target);
}