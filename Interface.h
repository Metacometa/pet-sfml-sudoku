#pragma once
#include "Button.h"

class Interface {
	//Resources
	std::vector<Button> buttons;
public:
	//Constructor / Destructor
	Interface();	
	virtual ~Interface();

	//Functions
	void addButton(const sf::Texture* texture, const sf::Vector2f& pos);
	void updateButtons(const sf::Vector2f& mousePos);
	void renderButtons(sf::RenderTarget* target);
};

