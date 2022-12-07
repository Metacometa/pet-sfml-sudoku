#include "Button.h"

//Constructor / Destructor
Button::Button(std::string file){
	sf::Texture texture;
	if (!texture.loadFromFile(file)) {
		std::cout << file << " can't be loaded" << std::endl;
	}
	this->sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(10.f, 50.f));
}

Button::~Button(){
}
