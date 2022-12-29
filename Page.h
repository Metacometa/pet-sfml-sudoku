#pragma once
#include "Field.h"

class Page {
	std::vector<InterfaceComponent*> interfaceComponents;
public:
	//Constructor / Destructor
	Page();
	virtual ~Page();

	//Functions
	void addButton(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);
	void addImage(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);
	void addField(const sf::Vector2f& pos, InterfaceBlock name);

	InterfaceBlock updateInterfaceComponents(const sf::Vector2f& mousePos, const bool& isLeftButtonPressed);
	void renderInterfaceComponents(sf::RenderTarget* target);
};

