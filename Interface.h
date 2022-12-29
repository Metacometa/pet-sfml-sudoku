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
	std::map<InterfaceBlock, sf::Texture*> textures;
	std::vector<Page*> pages;

	InterfacePage page;
protected:
	//Private functions
	void initTextures();
	void initPages();
public:
	//Constructor / Destructor
	Interface(InterfacePage tempPage);
	virtual ~Interface();

	//Functions
	void updatePage(const sf::Vector2f &mousePos, const bool &isLeftButtonPressed, sf::RenderWindow* window);
	void renderPage(sf::RenderTarget* target);
};

