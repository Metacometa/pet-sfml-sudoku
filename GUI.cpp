#include "GUI.h"

GUI::GUI(std::shared_ptr<sf::RenderWindow> &window)
{
	menu_buttons_args[NEW_GAME_PATH].action = [this]() { this->setGameScene(); };
	menu_buttons_args[EXIT_PATH].action = [&window]() { window.get()->close(); };


	scenes.emplace("Menu", new MenuScene);

	game_buttons_args[BACK_PATH].action = [this]() { this->setMenuScene(); };


	scene = scenes["Menu"];
}

GUI::~GUI() {}

void GUI::update(const sf::Vector2f& mousePos)
{
	scene.lock()->update(mousePos);
}

void GUI::render(sf::RenderTarget* target)
{
	scene.lock()->render(target);
}

void GUI::click(const sf::Vector2f& mousePos)
{
	scene.lock()->click(mousePos);
}

void GUI::press(const sf::Keyboard::Key &key)
{
	std::cout << key << std::endl;
	scene.lock()->press(key);
}

void GUI::setGameScene() 
{
	new_game();
	scene = scenes["Game"];
}

void GUI::setMenuScene()
{
	scene = scenes["Menu"];
}

void GUI::new_game()
{
	scenes.erase("Game");
	scenes.emplace("Game", new GameScene);
}
