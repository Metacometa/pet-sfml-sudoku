#include "GameSceneConfig.h"

std::shared_ptr<sf::Vector2f> BACK_POS = std::make_shared<sf::Vector2f>(47, 48);
std::shared_ptr<sf::Vector2f> SAVE_POS = std::make_shared<sf::Vector2f>(566, 47);
std::shared_ptr<sf::Vector2f> RESTART_POS = std::make_shared<sf::Vector2f>(281, 63);
std::shared_ptr<sf::Vector2f> FIELD_POS = std::make_shared<sf::Vector2f>(130, 200);
std::shared_ptr<sf::Vector2f> TAKEBACK_POS = std::make_shared<sf::Vector2f>(682, 317);
std::shared_ptr<sf::Vector2f> ERASE_POS = std::make_shared<sf::Vector2f>(701, 438);
std::shared_ptr<sf::Vector2f> HINT_POS = std::make_shared<sf::Vector2f>(702, 558);

std::shared_ptr<std::string> BACK_PATH = std::make_shared<std::string>("assets/game/back.png");
std::shared_ptr<std::string> SAVE_PATH = std::make_shared <std::string>("assets/game/save.png");
std::shared_ptr<std::string> RESTART_PATH = std::make_shared <std::string>("assets/game/restart.png");
std::shared_ptr<std::string> FIELD_PATH = std::make_shared<std::string>("assets/game/field.png");
std::shared_ptr<std::string> TAKEBACK_PATH = std::make_shared<std::string>("assets/game/takeback.png");
std::shared_ptr<std::string> ERASE_PATH = std::make_shared<std::string>("assets/game/erase.png");
std::shared_ptr<std::string> HINT_PATH = std::make_shared<std::string>("assets/game/hint.png");

std::vector<UIComponentInfo> game_images_args = { /*UIComponentInfo(FIELD_PATH, FIELD_POS)*/};

std::unordered_map<std::shared_ptr<std::string>, UIComponentInfo> game_buttons_args =
{
	{ BACK_PATH, UIComponentInfo(BACK_PATH, BACK_POS) },
	{ SAVE_PATH, UIComponentInfo(SAVE_PATH, SAVE_POS) },
	{ RESTART_PATH, UIComponentInfo(RESTART_PATH, RESTART_POS) },
	{ TAKEBACK_PATH, UIComponentInfo(TAKEBACK_PATH, TAKEBACK_POS) },
	{ ERASE_PATH, UIComponentInfo(ERASE_PATH, ERASE_POS) },
	{ HINT_PATH, UIComponentInfo(HINT_PATH, HINT_POS) },
};


std::shared_ptr<std::string> NUMBER_PATH = std::make_shared<std::string>("assets/game/numbers/");
std::shared_ptr<std::string> SQUARE_PATH = std::make_shared<std::string>("assets/game/numbers/square.png");
int FIELD_SIZE = 9;
std::vector<std::vector<UIComponentInfo>> game_field;