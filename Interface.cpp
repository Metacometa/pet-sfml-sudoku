#include "Interface.h"

//Constructor / Destructor
Interface::Interface() {}

Interface::~Interface() {
	for (auto *i : interface)
		delete i;
}

//Functions
void Interface::addButton(const sf::Texture* texture, const sf::Vector2f& pos) {
	interface.push_back(new Button(texture, pos));
}

void Interface::addImage(const sf::Texture* texture, const sf::Vector2f& pos){
	interface.push_back(new Image(texture, pos));
}

void Interface::updateButtons(const sf::Vector2f& mousePos){
	for (auto *i : interface)
		i->update(mousePos);
}

void Interface::renderInterfaceComponents(sf::RenderTarget* target){
	for (auto *i : interface)
		i->render(target);
}




