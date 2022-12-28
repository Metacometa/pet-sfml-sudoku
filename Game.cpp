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
	initTextures();
	initPages();
}

//Constructor / Destructor
Game::Game() : Interface(InterfacePages::MENU) {
	this->initVariables();
	this->initWindow();
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

//Getters

//Setters

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
	updatePage(this->mousePosWorld);
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

	renderPage(this->window);

	this->window->display();
}