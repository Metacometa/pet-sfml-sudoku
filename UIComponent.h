#pragma once
#include "Properties.h"

#include "IRenderable.h"
#include "IUpdateable.h"
#include "IPointable.h"
#include "IClickable.h"

class UIComponent : public IRenderable, public IUpdateable, public IPointable, public IClickable
{
protected:
	//Resources
	sf::Sprite sprite;

	//Variables
	sf::Vector2f pos;

public:
	UIComponent(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos);
	virtual ~UIComponent();

	void render(sf::RenderTarget* target);
	bool isPointed(const sf::Vector2f& mousePos);
};

