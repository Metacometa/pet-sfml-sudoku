#include "Interface.h"

//Private functions
void Interface::initTextures() {
	this->textures[InterfaceBlock::TITLE] = new sf::Texture();
	this->textures[InterfaceBlock::TITLE]->loadFromFile("assets/menu/sudoku.png");
		
	this->textures[InterfaceBlock::NEW_GAME] = new sf::Texture();
	this->textures[InterfaceBlock::NEW_GAME]->loadFromFile("assets/menu/new_game.png");

	this->textures[InterfaceBlock::LOAD_GAME] = new sf::Texture();
	this->textures[InterfaceBlock::LOAD_GAME]->loadFromFile("assets/menu/load_game.png");

	this->textures[InterfaceBlock::EXIT] = new sf::Texture();
	this->textures[InterfaceBlock::EXIT]->loadFromFile("assets/menu/exit.png");

	this->textures[InterfaceBlock::BACK] = new sf::Texture();
	this->textures[InterfaceBlock::BACK]->loadFromFile("assets/game/back.png");

	this->textures[InterfaceBlock::RESTART] = new sf::Texture();
	this->textures[InterfaceBlock::RESTART]->loadFromFile("assets/game/restart.png");

	this->textures[InterfaceBlock::SAVE] = new sf::Texture();
	this->textures[InterfaceBlock::SAVE]->loadFromFile("assets/game/save.png");

	this->textures[InterfaceBlock::SQUARE] = new sf::Texture();
	this->textures[InterfaceBlock::SQUARE]->loadFromFile("assets/game/field.png");

	this->textures[InterfaceBlock::TAKEBACK] = new sf::Texture();
	this->textures[InterfaceBlock::TAKEBACK]->loadFromFile("assets/game/takeback.png");

	this->textures[InterfaceBlock::ERASE] = new sf::Texture();
	this->textures[InterfaceBlock::ERASE]->loadFromFile("assets/game/erase.png");

	this->textures[InterfaceBlock::HINT] = new sf::Texture();
	this->textures[InterfaceBlock::HINT]->loadFromFile("assets/game/hint.png");
}

void Interface::initPages() {
	//Initializing MENU page
	this->pages.push_back(new Page());
	this->pages[InterfacePage::MENU]->addImage(this->textures[InterfaceBlock::TITLE], TITLE_POS, InterfaceBlock::TITLE);
	this->pages[InterfacePage::MENU]->addButton(this->textures[InterfaceBlock::NEW_GAME], NEW_GAME_POS, InterfaceBlock::NEW_GAME);
	this->pages[InterfacePage::MENU]->addButton(this->textures[InterfaceBlock::LOAD_GAME], LOAD_GAME_POS, InterfaceBlock::LOAD_GAME);
	this->pages[InterfacePage::MENU]->addButton(this->textures[InterfaceBlock::EXIT], EXIT_POS, InterfaceBlock::EXIT);

	this->pages.push_back(new Page());
	this->pages[InterfacePage::GAME]->addButton(this->textures[InterfaceBlock::BACK], BACK_POS, InterfaceBlock::BACK);
	this->pages[InterfacePage::GAME]->addButton(this->textures[InterfaceBlock::RESTART], RESTART_POS, InterfaceBlock::RESTART);
	this->pages[InterfacePage::GAME]->addButton(this->textures[InterfaceBlock::SAVE], SAVE_POS, InterfaceBlock::SAVE);
	this->pages[InterfacePage::GAME]->addField(FIELD_POS, InterfaceBlock::SQUARE);
	this->pages[InterfacePage::GAME]->addButton(this->textures[InterfaceBlock::TAKEBACK], TAKEBACK_POS, InterfaceBlock::TAKEBACK);
	this->pages[InterfacePage::GAME]->addButton(this->textures[InterfaceBlock::ERASE], ERASE_POS, InterfaceBlock::ERASE);
	this->pages[InterfacePage::GAME]->addButton(this->textures[InterfaceBlock::HINT], HINT_POS, InterfaceBlock::HINT);
}

//Constructor / Destructor
Interface::Interface(InterfacePage tempPage) : page(tempPage) {
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
void Interface::updatePage(const sf::Vector2f& mousePos, const bool &isLeftButtonPressed, sf::RenderWindow* window) {
	InterfaceBlock block = this->pages[this->page]->updateInterfaceComponents(mousePos, isLeftButtonPressed);
	switchPage(block, this->page, window);
}

void Interface::renderPage(sf::RenderTarget* target) {
	this->pages[page]->renderInterfaceComponents(target);
}

void Interface::switchPage(const InterfaceBlock& gottenBlock, InterfacePage& page, sf::RenderWindow* window) {
	switch (gottenBlock) {
		case InterfaceBlock::NONE:
		break;
		case InterfaceBlock::NEW_GAME: {
			page = InterfacePage::GAME;
			std::cout << "New_game clicked" << std::endl;
			break;
		}
		case InterfaceBlock::LOAD_GAME: {
			std::cout << "Load_game clicked" << std::endl;
			break;
		}
		case InterfaceBlock::EXIT: {
			window->close();
			std::cout << "Exit clicked" << std::endl;
			break;
		}
		case InterfaceBlock::BACK:
			page = InterfacePage::MENU;
		}
	}







