#include "UIComponent.h"

UIComponent::UIComponent(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos)
{
	this->sprite.setTexture(*texture.get());
	this->sprite.setPosition(pos);
	this->pos = pos;
}

UIComponent::~UIComponent()
{
}
