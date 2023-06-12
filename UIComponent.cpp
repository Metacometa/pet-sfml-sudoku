#include "UIComponent.h"

UIComponent::UIComponent(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos)
{
	this->sprite.setTexture(*texture.get());
	this->sprite.setPosition(pos);
	this->pos = pos;

	defaultColor = sprite.getColor();
}

UIComponent::UIComponent() {}

void UIComponent::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

bool UIComponent::isPointed(const sf::Vector2f& mousePos)
{
	return this->sprite.getGlobalBounds().contains(mousePos);
}

void UIComponent::setColor(const sf::Color& color)
{
	sprite.setColor(color);
}

void UIComponent::setDefaultColor()
{
	sprite.setColor(defaultColor);
}

sf::Sprite& UIComponent::getSprite()
{
	return sprite;
}


UIComponent::~UIComponent()
{
}
