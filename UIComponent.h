#pragma once
#include "Properties.h"

#include "IRenderable.h"
#include "IUpdateable.h"
#include "IPointable.h"
#include "IClickable.h"
#include "IPressable.h"

class UIComponent : public IRenderable, public IUpdateable, public IPointable, public IClickable, public IPressable
{
protected:
	//Resources
	sf::Sprite sprite;

	//Variables
	sf::Vector2f pos;

	sf::Color defaultColor;

public:
	UIComponent(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos);
	UIComponent();
	virtual ~UIComponent();

	void render(sf::RenderTarget* target);
	bool isPointed(const sf::Vector2f& mousePos);
	
	void setColor(const sf::Color &color);
	void setDefaultColor();

	sf::Sprite& getSprite();
};

