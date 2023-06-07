#include "MenuSceneConfig.h"

std::shared_ptr<sf::Vector2f> TITLE_POS = std::make_shared<sf::Vector2f>(186, 65);
std::shared_ptr<sf::Vector2f> NEW_GAME_POS = std::make_shared<sf::Vector2f>(83, 198);
std::shared_ptr<sf::Vector2f> LOAD_GAME_POS = std::make_shared<sf::Vector2f>(83, 382);
std::shared_ptr<sf::Vector2f> EXIT_POS = std::make_shared<sf::Vector2f>(83, 565);

std::shared_ptr<std::string> TITLE_PATH = std::make_shared<std::string>("assets/menu/sudoku.png");
std::shared_ptr<std::string> NEW_GAME_PATH = std::make_shared <std::string>("assets/menu/new_game.png");
std::shared_ptr<std::string> LOAD_GAME_PATH = std::make_shared <std::string>("assets/menu/load_game.png");
std::shared_ptr<std::string> EXIT_PATH = std::make_shared <std::string>("assets/menu/exit.png");

std::vector<UIComponentInfo> menu_images_args = { UIComponentInfo(TITLE_PATH, TITLE_POS) };

std::unordered_map<std::shared_ptr<std::string>, UIComponentInfo> menu_buttons_args = 
{ 
	{ NEW_GAME_PATH, UIComponentInfo(NEW_GAME_PATH, NEW_GAME_POS) },
	{ LOAD_GAME_PATH, UIComponentInfo(LOAD_GAME_PATH, LOAD_GAME_POS) }, 
	{ EXIT_PATH, UIComponentInfo(EXIT_PATH, EXIT_POS) } 
};

/*std::vector<UIComponentInfo> menu_buttons_args = {UIComponentInfo(NEW_GAME_PATH, NEW_GAME_POS),
UIComponentInfo(LOAD_GAME_PATH, LOAD_GAME_POS), UIComponentInfo(EXIT_PATH, EXIT_POS) };*/