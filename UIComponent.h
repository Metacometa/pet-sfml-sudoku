#pragma once
#include "IRenderable.h"
#include "IUpdateable.h"
#include "Properties.h"

class UIComponent : public IRenderable, public IUpdateable
{
public:	
	//Resources
	sf::Sprite sprite;

	//Variables
	sf::Vector2f pos;
public:
	UIComponent(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos);
	virtual ~UIComponent();
};

