#include "MenuScene.h"

MenuScene::MenuScene()
{
	std::cout << "Start scene default constructor" << std::endl;

	//images
	for (auto& image_args : menu_images_args) {
		this->textures[*image_args.asset_path.get()] = std::make_shared<sf::Texture>();

		this->textures[*image_args.asset_path.get()]->loadFromFile(*image_args.asset_path);

		components.emplace_back(new Image(this->textures[*image_args.asset_path], *image_args.pos));

		renderableComponents.emplace_back(components.back());
		updateableComponents.emplace_back(components.back());
	}

	//buttons
	for (auto& button_args : menu_buttons_args) {
		std::cout << *button_args.first.get() << std::endl;
		this->textures[*button_args.first.get()] = std::make_shared<sf::Texture>();
		this->textures[*button_args.first.get()]->loadFromFile(*button_args.first);

		components.emplace_back(new Button(this->textures[*button_args.first], *button_args.second.pos, button_args.second.action));

		renderableComponents.emplace_back(components.back());
		updateableComponents.emplace_back(components.back());
		clickableComponents.emplace_back(components.back());
	}
}

MenuScene::~MenuScene() {}
