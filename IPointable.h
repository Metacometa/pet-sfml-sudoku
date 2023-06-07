#pragma once
#include "Properties.h"

class IPointable
{
	virtual bool isPointed(const sf::Vector2f& mousePos) = 0;
};

