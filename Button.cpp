#include "Button.h"

//Constructor / Destructor
Button::Button(const sf::Texture* texture, const sf::Vector2f& pos) : InterfaceComponent(texture, pos) {}

Button::~Button(){}

//Private functions
void Button::shrink(const sf::Vector2f& mousePos) {
	/*
		@return void
		- Shrink scale
		- Change position
		Shrinks buttons then moise is pointed.
	*/
	if (isPointed(mousePos)) {

		//Save old width and height
		sf::Vector2f old_measure;
		old_measure.x = this->sprite.getGlobalBounds().width;
		old_measure.y = this->sprite.getGlobalBounds().height;

		//Apply shrinking of button's sprite
		this->sprite.setScale(sf::Vector2f(SHRINK_MULTIPLIER, SHRINK_MULTIPLIER));

		//Compute new coordinations for smooth animation
		sf::Vector2f dif_measure;
		dif_measure.x = old_measure.x - this->sprite.getGlobalBounds().width;
		dif_measure.y = old_measure.y - this->sprite.getGlobalBounds().height;

		//Apply relocation of button
		sf::Vector2f new_pos;
		new_pos.x = this->sprite.getPosition().x + dif_measure.x / 2;
		new_pos.y = this->sprite.getPosition().y + dif_measure.y / 2;

		this->sprite.setPosition(new_pos);

	}
	else {
		//Return old scale and position of buttons after redirection of mouse
		this->sprite.setScale(sf::Vector2f(NORMAL_MULTIPLIER, NORMAL_MULTIPLIER));
		this->sprite.setPosition(this->pos);
	}
}

//Functions
void Button::update(const sf::Vector2f& mousePos) {
	this->shrink(mousePos);
}

