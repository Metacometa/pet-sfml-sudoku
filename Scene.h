#pragma once
#include <unordered_map>
#include <string>
#include <list>

#include "Properties.h"

#include "UIComponent.h"
#include "IClickable.h"

#include "Button.h"
#include "Image.h"

class Scene : public IRenderable, public IUpdateable, public IClickable
{
public:
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;

	std::list<std::shared_ptr<UIComponent>> components;

	std::list<std::weak_ptr<IRenderable>> renderableComponents;
	std::list<std::weak_ptr<IUpdateable>> updateableComponents;
	std::list<std::weak_ptr<IClickable>> clickableComponents;

public:
	void render(sf::RenderTarget* target);
	void update(const sf::Vector2f& mousePos);
	void click(const sf::Vector2f& mousePos);
};

