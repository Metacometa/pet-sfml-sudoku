#include "Game.h"

//Private functions
void Game::initVariables() {
	this->window = nullptr;
}

void Game::initWindow() {
	//set screen properties
	this->videoMode.height = 800;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(videoMode, "Sudoku");
}


void Game::initInterface() {
	//remember current state of screen
	//interface.cr
	interface.addPages(INTERFACE_PAGES);
	/*
	this->currentInterface = interfaceState::MENU; 

	//create starting screen
	this->interface.push_back(Interface());
	this->interface[(int)interfaceState::MENU].addImage(this->textures["TITLE"], TITLE_POS);
	this->interface[(int)interfaceState::MENU].addButton(this->textures["NEW"], NEW_GAME_POS);
	this->interface[(int)interfaceState::MENU].addButton(this->textures["LOAD"], LOAD_GAME_POS);
	this->interface[(int)interfaceState::MENU].addButton(this->textures["EXIT"], EXIT_POS);
	*/


	//this->interface.push_back(Interface());

	//this->interface.push_back(Interface());
}

//Constructor / Destructor
Game::Game() {
	this->initVariables();
	this->initWindow();
	//this->initTextures();
	this->initInterface();
}

Game::~Game() {
	//Delete window
	delete this->window;
}

//Accessors
const bool Game::isRunning() const {
	return this->window->isOpen();
}

const int Game::IntInterfaceState() const {
	return (int)this->currentInterface;
}

//Getters

//Setters
void Game::setInterfaceState(interfaceState state) {
	this->currentInterface = state;
}

//Functions
void Game::pollEvents() {
	while (this->window->pollEvent(this->ev)) {
		if (this->ev.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::updateMousePositions() {
	/*
		@ return void

		Updates the mouse positions:
		- Mouse position relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosWorld = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateInterface() {
	//
	//this->interface[IntInterfaceState()].updateButtons(this->mousePosWorld);
}

void Game::update() {
	this->pollEvents();

	this->updateMousePositions();

	this->updateInterface();
}

void Game::render() {
	/*
		@return void
		- clear old frame
		- render new objects
		- display frame in window
		Render the game objects.	
	*/

	this->window->clear(sf::Color(237,218,192,255));

	//Draw game objects
	switch (this->currentInterface) {
		case interfaceState::MENU:
			//render buttons of starting interface
			//this->interface[IntInterfaceState()].renderInterfaceComponents(this->window);
			break;
		case interfaceState::LOAD:
			break;
		case interfaceState::GAME:
			break;
	}

	this->window->display();
}