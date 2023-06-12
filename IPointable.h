#pragma once
#include "Properties.h"

class IPointable
{
public:
	virtual bool isPointed(const sf::Vector2f& mousePos) = 0;
};

