#pragma once
#include "Properties.h"

//Parent class for images and buttons components of interface.

class InterfaceComponent {

protected:
	//Resources
	sf::Sprite sprite;

	//Variables
	sf::Vector2f pos;

	InterfaceBlock name;
public:
	//Constructors / Destructors
	InterfaceComponent();
	InterfaceComponent(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);
	virtual ~InterfaceComponent();

	//Getters
	const sf::Sprite getSprite() const;

	const InterfaceBlock getInterfaceBlock() const;

	//Setters

	//Accessors
	const bool isPointed(const sf::Vector2f& mousePos) const;

	//Functions
	virtual void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);
};

