#pragma once
#include "SFML/Graphics.hpp"

class IPressable
{
public:
	virtual void press(const sf::Keyboard::Key &key) = 0;
};

