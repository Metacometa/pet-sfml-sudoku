#pragma once
#include "Page.h"

/*
	Class that acts as the game interface
	It contains all manipulations with buttons, images and game_field.
	Wrapper class.
*/

class Interface {
private:
	//Resources
	std::map<InterfaceBlocks, sf::Texture*> textures;
	std::vector<Page*> pages;

	InterfacePages page;
protected:
	//Private functions
	void initTextures();
	void initPages();
public:
	//Constructor / Destructor
	Interface(InterfacePages tempPage);
	virtual ~Interface();

	//Functions
	void updatePage(const sf::Vector2f& mousePos);
	void renderPage(sf::RenderTarget* target);
};

