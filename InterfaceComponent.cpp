#include "InterfaceComponent.h"

//Constructor / Destructor
InterfaceComponent::InterfaceComponent() : name(InterfaceBlock::NONE) {}

InterfaceComponent::InterfaceComponent(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name) {
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos);
	this->pos = pos;
	this->name = name;
}

InterfaceComponent::~InterfaceComponent() {}

//Getters
const sf::Sprite InterfaceComponent::getSprite() const {
	return this->sprite;
}

const InterfaceBlock InterfaceComponent::getInterfaceBlock() const {
	return this->name;
}

//Setters

//Accessors
const bool InterfaceComponent::isPointed(const sf::Vector2f& mousePos) const {
	return this->sprite.getGlobalBounds().contains(mousePos);
}

//Functions
void InterfaceComponent::update(const sf::Vector2f& mousePos) {}

void InterfaceComponent::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}


