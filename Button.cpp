#include "Button.h"

Button::Button(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f& pos) : UIComponent(texture,  pos)
{
}

Button::~Button()
{
}

void Button::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

void Button::update()
{
	//pos.x++;
	//std::cout << pos.x << " ";
}

