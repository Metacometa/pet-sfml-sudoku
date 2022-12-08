#pragma once
#include "Button.h"

class Interface {
	//Resources
	std::vector<InterfaceComponent*> &interface;
public:
	//Constructor / Destructor
	Interface();	
	virtual ~Interface();

	//Functions
	void addButton(const sf::Texture* texture, const sf::Vector2f& pos);
	void addImages(const sf::Texture* texture, const sf::Vector2f& pos);

	void updateButtons(const sf::Vector2f& mousePos);

	void renderInterfaceComponents(sf::RenderTarget* target);
};

