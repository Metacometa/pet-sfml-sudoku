#include "Interface.h"

//Private functions
void Interface::initTextures() {
	this->textures["TITLE"] = new sf::Texture();
	this->textures["TITLE"]->loadFromFile("assets/sudoku.png");

	this->textures["NEW"] = new sf::Texture();
	this->textures["NEW"]->loadFromFile("assets/new_game.png");

	this->textures["LOAD"] = new sf::Texture();
	this->textures["LOAD"]->loadFromFile("assets/load_game.png");

	this->textures["EXIT"] = new sf::Texture();
	this->textures["EXIT"]->loadFromFile("assets/exit.png");
}

//Constructor / Destructor
Interface::Interface() {
	void initTextures();
}

Interface::~Interface() {
	//Delete textures
	for (auto& i : this->textures)
		delete i.second;
}

//Functions
void Interface::addPages(int numberOfPages) {
	for (auto i = 0; i < numberOfPages; ++i)
		pages.push_back();

}

void Interface::addButton(const sf::Texture* texture, const sf::Vector2f& pos) {
	interfaceComponents.push_back(new Button(texture, pos));
}

void Interface::addImage(const sf::Texture* texture, const sf::Vector2f& pos) {
	interfaceComponents.push_back(new Image(texture, pos));
}

void Interface::updateButtons(const sf::Vector2f& mousePos){
	for (auto *i : interfaceComponents)
		i->update(mousePos);
}

void Interface::renderInterfaceComponents(sf::RenderTarget* target){
	for (auto *i : interfaceComponents)
		i->render(target);
}




