#include "Button.h"

//Constructor / Destructor
Button::Button(sf::Texture* texture){

	this->sprite.setTexture(&texture);
	sprite.setPosition(sf::Vector2f(10.f, 50.f));
}

Button::~Button(){

}

//Getters
const sf::Sprite Button::getSprite() const {
	return this->sprite;
}
