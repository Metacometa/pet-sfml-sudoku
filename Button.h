#pragma once
#include "UIComponent.h"

class Button : public UIComponent
{
public:
	Button(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos);
	virtual ~Button();

	void render(sf::RenderTarget* target);
	void update();
};

