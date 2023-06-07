#pragma once
#include "UIComponent.h"

class Image : public UIComponent
{
public:
	Image(const std::shared_ptr<sf::Texture>& texture, const sf::Vector2f& pos);
	virtual ~Image();

	void update(const sf::Vector2f& mousePos);
	void click(const sf::Vector2f& mousePos);
};