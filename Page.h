#pragma once
#include "Button.h"

class Page {
	std::vector<InterfaceComponent*> interfaceComponents;
public:
	//Constructor / Destructor
	Page();
	virtual ~Page();

	//Functions
	void addButton(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);
	void addImage(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);

	void switchPage(const InterfaceBlock& gottenBlock, InterfacePage& page, sf::RenderWindow* window);
	void updateInterfaceComponents(const sf::Vector2f& mousePos, const bool& isLeftButtonPressed, InterfacePage &page, sf::RenderWindow* window);
	void renderInterfaceComponents(sf::RenderTarget* target);
};

