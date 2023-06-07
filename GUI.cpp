#include "GUI.h"

GUI::GUI(std::shared_ptr<sf::RenderWindow> &window)
{
	std::function<void()> setGameFunction = [this]() { std::cout << "Kek" << std::endl; };

	menu_buttons_args[NEW_GAME_PATH].action = [this]() { this->setGameScene(); };
	menu_buttons_args[EXIT_PATH].action = [&window]() { window.get()->close(); };

	scenes.emplace("Menu", new MenuScene);
	scenes.emplace("Game", new GameScene);
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

void GUI::setGameScene() {
	scene = scenes["Game"];
}
