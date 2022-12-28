#include "Interface.h"

//Private functions
void Interface::initTextures() {
	this->textures[InterfaceBlocks::TITLE] = new sf::Texture();
	this->textures[InterfaceBlocks::TITLE]->loadFromFile("assets/sudoku.png");
		
	this->textures[InterfaceBlocks::NEW_GAME] = new sf::Texture();
	this->textures[InterfaceBlocks::NEW_GAME]->loadFromFile("assets/new_game.png");

	this->textures[InterfaceBlocks::LOAD_GAME] = new sf::Texture();
	this->textures[InterfaceBlocks::LOAD_GAME]->loadFromFile("assets/load_game.png");

	this->textures[InterfaceBlocks::EXIT] = new sf::Texture();
	this->textures[InterfaceBlocks::EXIT]->loadFromFile("assets/exit.png");
}

void Interface::initPages() {
	this->pages.push_back(new Page());
	this->pages[InterfacePages::MENU]->addImage(this->textures[InterfaceBlocks::TITLE], TITLE_POS);
	this->pages[InterfacePages::MENU]->addButton(this->textures[InterfaceBlocks::NEW_GAME], NEW_GAME_POS);
	this->pages[InterfacePages::MENU]->addButton(this->textures[InterfaceBlocks::LOAD_GAME], LOAD_GAME_POS);
	this->pages[InterfacePages::MENU]->addButton(this->textures[InterfaceBlocks::EXIT], EXIT_POS);
}

//Constructor / Destructor
Interface::Interface(InterfacePages tempPage) : page(tempPage) {
	std::cout << tempPage << std::endl;
}

Interface::~Interface() {
	//Delete pages
	for (auto *i : this->pages)
		delete i;

	//Delete textures
	for (auto& i : this->textures)
		delete i.second;
}

//Functions
void Interface::updatePage(const sf::Vector2f& mousePos) {
	this->pages[page]->updateInterfaceComponents(mousePos);
}

void Interface::renderPage(sf::RenderTarget* target) {
	this->pages[page]->renderInterfaceComponents(target);
}





