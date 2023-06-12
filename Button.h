#pragma once
#include <functional>

#include "UIComponent.h"
#include "IClickable.h"

class Button : public UIComponent
{
	std::function<void()> clickAction;

public:
	Button(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos, std::function<void()> &clickAction_);
	virtual ~Button();

	void update(const sf::Vector2f& mousePos);
	void click(const sf::Vector2f& mousePos);
	void press(const sf::Keyboard::Key &key);

	void shrink();
	void unshrink();
};

