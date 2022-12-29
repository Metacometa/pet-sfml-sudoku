#pragma once
#include "Button.h"

class Field : public InterfaceComponent {
	//Resources
	std::map<char, sf::Texture*> textures;
public:
	class Square : public InterfaceComponent {
	public:
		char value;
		Image *number;
		Image *square;
	
		Square(char value, const sf::Texture* textureNumber, const sf::Texture* squareNumber, const sf::Vector2f& pos, InterfaceBlock name) {
			this->value = value;
			this->number = new Image(textureNumber, pos, name);
			this->square = new Image(squareNumber, pos, name);
		}

		~Square() {
			delete number;
			delete square;
		}
	};

	std::vector<Square*>* gameField[9];

	//Constructors / Destructors
	Field(const sf::Vector2f& pos, InterfaceBlock name);

	//Functions
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);
};

