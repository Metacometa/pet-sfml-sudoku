#pragma once

#include <unordered_map>

#include "Properties.h"

#include "UIComponent.h"
#include "MenuScene.h"
#include "GameScene.h"

class GUI : public IRenderable, public IUpdateable, public IClickable
{
	std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;

	std::weak_ptr<Scene> scene;

public:
	GUI(std::shared_ptr<sf::RenderWindow> &window);
	virtual ~GUI();

	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);
	void click(const sf::Vector2f& mousePos);

	void setGameScene();
};

