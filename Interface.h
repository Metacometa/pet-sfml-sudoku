#pragma once
#include "Button.h"

/*
	Class that acts as the game interface
	It contains all manipulations with buttons, images and game_field.
	Wrapper class.
*/

class Interface {
	//Resources
	std::vector<InterfaceComponent*> interface;
public:
	//Constructor / Destructor
	Interface();	
	virtual ~Interface();

	//Functions
	void addButton(const sf::Texture* texture, const sf::Vector2f& pos);
	void addImage(const sf::Texture* texture, const sf::Vector2f& pos);

	void updateButtons(const sf::Vector2f& mousePos);

	void renderInterfaceComponents(sf::RenderTarget* target);
};

