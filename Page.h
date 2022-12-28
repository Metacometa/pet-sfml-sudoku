#pragma once
#include "Button.h"

class Page {
	std::vector<InterfaceComponent*> interfaceComponents;
public:
	//Constructor / Destructor
	Page();
	virtual ~Page();

	//Functions
	void addButton(const sf::Texture* texture, const sf::Vector2f& pos);
	void addImage(const sf::Texture* texture, const sf::Vector2f& pos);

	void updateInterfaceComponents(const sf::Vector2f& mousePos);
	void renderInterfaceComponents(sf::RenderTarget* target);
};

