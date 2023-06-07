#include "Button.h"

Button::Button(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos, std::function<void()>clickAction_) : UIComponent(texture,  pos)
{
	clickAction = clickAction_;
}

Button::~Button() {}

void Button::update(const sf::Vector2f& mousePos)
{
	if (this->isPointed(mousePos)) {
		this->shrink();
	}
	else {
		this->unshrink();
	}
}

void Button::click(const sf::Vector2f& mousePos)
{
	if (this->isPointed(mousePos)) {
		clickAction();
	}
}

void Button::shrink()
{
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

void Button::unshrink()
{
	//Return old scale and position of buttons after redirection of mouse
	this->sprite.setScale(sf::Vector2f(NORMAL_MULTIPLIER, NORMAL_MULTIPLIER));
	this->sprite.setPosition(this->pos);
}

