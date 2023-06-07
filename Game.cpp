#include "Game.h"

//Private functions
void Game::initVariables() {
}

void Game::initWindow() {
	//set screen properties
	this->videoMode.height = 800;
	this->videoMode.width = 800;
	this->window = std::make_shared<sf::RenderWindow>(videoMode, "Sudoku");
}

void Game::initInterface() {
	gui = new GUI;
}

//Constructor / Destructor
Game::Game() {
	this->initInterface();
	this->initWindow();
}

Game::~Game() {
	//delete this->window;
}

//Accessors
const bool Game::isRunning() const {
	return this->window->isOpen();
}

sf::RenderWindow* Game::getWindow() const
{
	return this->window.get();
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

void Game::updateInput() {
	isLeftButtonPressed = false;
	if (this->ev.type == sf::Event::MouseButtonPressed) {
		if (ev.mouseButton.button == sf::Mouse::Left) {
			isLeftButtonPressed = true;
		}
	}
}

void Game::update() {
	this->pollEvents();

	this->updateMousePositions();
	this->updateInput();

	gui->update();
}

void Game::render(sf::RenderTarget* target) {
	/*
		@return void
		- clear old frame
		- render new objects
		- display frame in window
		Render the game objects.	
	*/

	this->window->clear(sf::Color(237,218,192,255));

	//Draw game objects
	gui->render(this->window.get());

	this->window->display();
}