#pragma once
#include "Properties.h"

class IUpdateable
{
public:
	virtual void update(const sf::Vector2f& mousePos) = 0;
};

