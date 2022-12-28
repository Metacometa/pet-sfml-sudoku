#include "Page.h"

//Contrcutors / Destructors
Page::Page() {
}

Page::~Page() {
	for (auto* i : interfaceComponents)
		delete i;
}

//Functions
void Page::addButton(const sf::Texture* texture, const sf::Vector2f& pos) {
	interfaceComponents.push_back(new Button(texture, pos));
}

void Page::addImage(const sf::Texture* texture, const sf::Vector2f& pos) {
	interfaceComponents.push_back(new Image(texture, pos));
}

void Page::updateInterfaceComponents(const sf::Vector2f& mousePos) {
	for (auto *i : interfaceComponents)
		i->update(mousePos);
}

void Page::renderInterfaceComponents(sf::RenderTarget* target) {
	for (auto *i : interfaceComponents)
		i->render(target);
}