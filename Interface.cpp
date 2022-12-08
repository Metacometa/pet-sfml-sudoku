#include "Interface.h"

//Constructor / Destructor
Interface::Interface() {
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
	buttons.push_back(Button(texture, pos));
}

void Interface::updateButtons(const sf::Vector2f& mousePos){
	for (auto& i : buttons)
		i.update(mousePos);
}

void Interface::renderButtons(sf::RenderTarget* target){
	for (auto& i : buttons)
		i.render(target);
}




