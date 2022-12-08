#pragma once
#include "Button.h"

class Screen {
	//Resources
	std::vector<Button*> buttons;
public:
	//Constructor / Destructor
	Screen();
	virtual ~Screen();

	//Functions
	void addButton(const sf::Texture *texture);
};

