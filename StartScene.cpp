#include "StartScene.h"

StartScene::StartScene()
{
	std::cout << "Start scene default constructor" << std::endl;
	this->textures["assets/menu/sudoku.png"] = std::make_shared<sf::Texture>();
	this->textures["assets/menu/sudoku.png"]->loadFromFile("assets/menu/sudoku.png");

	//UIComponent* testComponent = new Button(this->textures["assets/menu/sudoku.png"], sf::Vector2f(500, 500));

	components.emplace_back(new Button(this->textures["assets/menu/sudoku.png"], sf::Vector2f(500, 500)));
	
	renderableComponents.push_back(components.back());
	updateableComponents.push_back(components.back());
	
}

StartScene::~StartScene()
{
}
