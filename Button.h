#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>


class Button {
	sf::Sprite sprite;
public:
	//Constructor / Destructor
	Button(sf::Texture* texture);
	virtual ~Button();

	//Getters

	//Setters
	const sf::Sprite getSprite() const;
};

