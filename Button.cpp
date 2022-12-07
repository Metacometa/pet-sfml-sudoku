#include "Button.h"

//Constructor / Destructor
Button::Button(std::string file){
	if (!this->texture.loadFromFile(file)) {
		std::cout << file << " can't be loaded" << std::endl;
	}
	this->sprite.setTexture(this->texture);
	sprite.setPosition(sf::Vector2f(10.f, 50.f));
}

Button::~Button(){

}

//Getters
const sf::Sprite Button::getSprite() const {
	return this->sprite;
}
