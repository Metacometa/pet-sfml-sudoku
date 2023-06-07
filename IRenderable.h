#pragma once
#include "Properties.h"

class IRenderable
{
public:
	virtual void render(sf::RenderTarget* target) = 0;
};

