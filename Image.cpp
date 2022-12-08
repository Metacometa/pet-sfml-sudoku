#include "Image.h"

//Constructor / Destructor
Image::Image(const sf::Texture* texture, const sf::Vector2f& pos) : InterfaceComponent(texture, pos) {}

Image::~Image() {}
