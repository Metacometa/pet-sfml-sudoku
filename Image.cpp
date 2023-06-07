#include "Image.h"

Image::Image(const std::shared_ptr<sf::Texture>& texture, const sf::Vector2f& pos) : UIComponent(texture, pos)
{
}

Image::~Image()
{
}

void Image::update(const sf::Vector2f& mousePos)
{
}

void Image::click(const sf::Vector2f& mousePos)
{
}

