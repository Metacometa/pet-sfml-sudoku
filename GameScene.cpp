#include "GameScene.h"

GameScene::GameScene()
{
	//game field
	for (char number = '0'; number <= '9'; ++number) {
		std::string key = *NUMBER_PATH + number + ".png";

		this->textures[key] = std::make_shared<sf::Texture>();
		this->textures[key]->loadFromFile(key);
	}

	game_field = std::make_shared<GameField>(&textures);
	components.emplace_back(game_field);

	renderableComponents.emplace_back(components.back());
	updateableComponents.emplace_back(components.back());
	clickableComponents.emplace_back(components.back());
	pressableComponents.emplace_back(components.back());

	game_buttons_args[RESTART_PATH].action = [this]() { this->game_field->generateNewField(); };
	game_buttons_args[TAKEBACK_PATH].action = [this]() { this->game_field->takeback(); };

	//images
	for (auto& image_args : game_images_args) 
	{
		this->textures[*image_args.asset_path.get()] = std::make_shared<sf::Texture>();
		this->textures[*image_args.asset_path.get()]->loadFromFile(*image_args.asset_path);

		components.emplace_back(new Image(this->textures[*image_args.asset_path], *image_args.pos));

		renderableComponents.emplace_back(components.back());
		updateableComponents.emplace_back(components.back());
	}

	//buttons
	for (auto& button_args : game_buttons_args) 
	{
		std::cout << *button_args.first.get() << std::endl;
		this->textures[*button_args.first.get()] = std::make_shared<sf::Texture>();
		this->textures[*button_args.first.get()]->loadFromFile(*button_args.first);

		components.emplace_back(new Button(this->textures[*button_args.first], *button_args.second.pos, button_args.second.action));

		renderableComponents.emplace_back(components.back());
		updateableComponents.emplace_back(components.back());
		clickableComponents.emplace_back(components.back());
	}


}

GameScene::~GameScene()
{
}
