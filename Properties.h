#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>

//Positions of interface's components
const sf::Vector2f TITLE_POS = sf::Vector2f(186, 65);
const sf::Vector2f NEW_GAME_POS = sf::Vector2f(83, 198);
const sf::Vector2f LOAD_GAME_POS = sf::Vector2f(83, 382);
const sf::Vector2f EXIT_POS = sf::Vector2f(83, 565);

//Variable for correct shrinking animation of button
const float SHRINK_MULTIPLIER = 0.98;
const float NORMAL_MULTIPLIER = 1;

//Interface
const int INTERFACE_PAGES = 3;