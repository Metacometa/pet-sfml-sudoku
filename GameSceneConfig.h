#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <memory>
#include <unordered_map>
#include "UIComponentInfo.h"

extern std::shared_ptr<sf::Vector2f> BACK_POS;
extern std::shared_ptr<sf::Vector2f> SAVE_POS;
extern std::shared_ptr<sf::Vector2f> RESTART_POS;
extern std::shared_ptr<sf::Vector2f> FIELD_POS;
extern std::shared_ptr<sf::Vector2f> TAKEBACK;
extern std::shared_ptr<sf::Vector2f> ERASE_POS;
extern std::shared_ptr<sf::Vector2f> HINT_POS;

extern std::shared_ptr<std::string> BACK_PATH;
extern std::shared_ptr<std::string> SAVE_PATH;
extern std::shared_ptr<std::string> RESTART_PATH;
extern std::shared_ptr<std::string> FIELD_PATH;
extern std::shared_ptr<std::string> TAKEBACK_PATH;
extern std::shared_ptr<std::string> ERASE_PATH;
extern std::shared_ptr<std::string> HINT_PATH;

extern std::vector<UIComponentInfo> game_images_args;

extern std::unordered_map<std::shared_ptr<std::string>, UIComponentInfo> game_buttons_args;

//field
extern std::shared_ptr<std::string> NUMBER_PATH;
extern std::shared_ptr<std::string> SQUARE_PATH;
extern int FIELD_SIZE;
extern std::vector<std::vector<UIComponentInfo>> game_field;