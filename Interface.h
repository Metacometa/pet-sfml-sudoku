#pragma once
#include "Page.h"

/*
	Class that acts as the game interface
	It contains all manipulations with buttons, images and game_field.
	Wrapper class.
*/

class Interface {
	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Page*> pages;

	//Private functions
	void initTextures();
public:
	//Constructor / Destructor
	Interface();	
	virtual ~Interface();

	//Functions
	void addPages(int numberOfPages);

	void addButton(const sf::Texture* texture, const sf::Vector2f& pos);
	void addImage(const sf::Texture* texture, const sf::Vector2f& pos);

	void updateButtons(const sf::Vector2f& mousePos);

	void renderInterfaceComponents(sf::RenderTarget* target);
};

