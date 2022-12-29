#include "Field.h"

Field::Field(const sf::Vector2f& pos, InterfaceBlock name) : InterfaceComponent(nullptr, pos, name){
	this->textures['0'] = new sf::Texture();
	this->textures['0']->loadFromFile("assets/game/numbers/square.png");

	for (char i = '1'; i <= '9'; ++i) {
		this->textures[i] = new sf::Texture();
		std::string pathName = "assets/game/numbers/";
		pathName += i;
		pathName += ".png";
		this->textures[i]->loadFromFile(pathName);
	}

	sf::Vector2f tempPos = pos;
	for (int i = 0; i < 9; ++i) {
		gameField[i] = new std::vector<Square*>;
		for (char j = '1'; j <= '9'; ++j) {
			gameField[i]->push_back(new Square(j, this->textures[j], this->textures['0'], tempPos, name));
			tempPos.x += 60;
		}
		tempPos.x = pos.x;
		tempPos.y += 60;
	}
}

void Field::update(const sf::Vector2f& mousePos) {
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 0; ++j)
			gameField[i]->at(j)->update();
	}

}

void Field::render(sf::RenderTarget* target) {
}
