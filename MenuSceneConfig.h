#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <memory>
#include <unordered_map>
#include "UIComponentInfo.h"

extern std::shared_ptr<sf::Vector2f> TITLE_POS;
extern std::shared_ptr<sf::Vector2f> NEW_GAME_POS;
extern std::shared_ptr<sf::Vector2f> LOAD_GAME_POS;
extern std::shared_ptr<sf::Vector2f> EXIT_POS;

extern std::shared_ptr<std::string> TITLE_PATH;
extern std::shared_ptr<std::string> NEW_GAME_PATH;
extern std::shared_ptr<std::string> LOAD_GAME_PATH;
extern std::shared_ptr<std::string> EXIT_PATH;

extern std::vector<UIComponentInfo> menu_images_args;

extern std::unordered_map<std::shared_ptr<std::string>, UIComponentInfo> menu_buttons_args;