#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>


class Button {
	sf::Sprite sprite;
public:
	//Constructor / Destructor
	Button(std::string file);
	virtual ~Button();
};

