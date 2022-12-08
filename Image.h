#pragma once
#include "InterfaceComponent.h"

class Image : public InterfaceComponent {
public:
	//Constructor / Destructor
	Image(const sf::Texture* texture, const sf::Vector2f& pos);
	virtual ~Image();
};

