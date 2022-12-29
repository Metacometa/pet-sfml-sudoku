#pragma once
#include "InterfaceComponent.h"

//Children class without special features

class Image : public InterfaceComponent {
public:
	//Constructor / Destructor
	Image(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);
	virtual ~Image();
};

