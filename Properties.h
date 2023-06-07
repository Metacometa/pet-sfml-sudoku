#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

//Positions of interface's components
//menu

const sf::Vector2f TITLE_POS = sf::Vector2f(186, 65);
const sf::Vector2f NEW_GAME_POS = sf::Vector2f(83, 198);
const sf::Vector2f LOAD_GAME_POS = sf::Vector2f(83, 382);
const sf::Vector2f EXIT_POS = sf::Vector2f(83, 565);
//game
const sf::Vector2f BACK_POS = sf::Vector2f(47, 48);
const sf::Vector2f SAVE_POS = sf::Vector2f(566, 47);
const sf::Vector2f RESTART_POS = sf::Vector2f(281, 63);
const sf::Vector2f FIELD_POS = sf::Vector2f(130,200);
const sf::Vector2f TAKEBACK_POS = sf::Vector2f(682, 317);
const sf::Vector2f ERASE_POS = sf::Vector2f(701,438);
const sf::Vector2f HINT_POS = sf::Vector2f(702,558);

//Variable for correct shrinking animation of button
const float SHRINK_MULTIPLIER = 0.98;
const float NORMAL_MULTIPLIER = 1;

//Interface
const int INTERFACE_PAGES = 3;

enum InterfacePage { MENU, GAME };
enum InterfaceBlock { NONE, TITLE, NEW_GAME, LOAD_GAME, EXIT, BACK, RESTART, SAVE, SQUARE, TAKEBACK, ERASE, HINT, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };
