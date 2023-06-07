#pragma once
#include "Properties.h"

class IClickable
{
public:
	virtual void click(const sf::Vector2f& mousePos) = 0;
};

