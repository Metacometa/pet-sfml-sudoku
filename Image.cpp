#include "Image.h"

//Constructor / Destructor
Image::Image(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name) : InterfaceComponent(texture, pos, name) {}

Image::~Image() {}
