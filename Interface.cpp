#include "Interface.h"

//Constructor / Destructor
Interface::Interface() {
	this->interface = nullptr;
}

Interface::~Interface() {
	//Delete buttons (I decided not to use dynamic memory for buttons(class button)
	/*
	for (auto button : buttons)
		delete button;
	*/
}

//Functions
void Interface::addButton(const sf::Texture* texture, const sf::Vector2f& pos) {
	interface.push_back(new Button(texture, pos));
}

void Interface::updateButtons(const sf::Vector2f& mousePos){
	for (auto *i : interface)
		i->update(mousePos);
}

void Interface::renderInterfaceComponents(sf::RenderTarget* target){
	for (auto *i : interface)
		i->render(target);
}




