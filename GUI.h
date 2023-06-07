#pragma once

#include <list>

#include "Properties.h"

#include "UIComponent.h"
#include "StartScene.h"

class GUI : public IRenderable, public IUpdateable
{
	std::list<std::shared_ptr<Scene>> scenes;
	std::list<std::weak_ptr<IRenderable>> renderableScenes;
	std::list<std::weak_ptr<IUpdateable>> updateableScenes;

public:
	GUI();
	virtual ~GUI();

	void update();
	void render(sf::RenderTarget* target);
};

