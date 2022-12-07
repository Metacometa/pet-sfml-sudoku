#include "Game.h"

//Private functions
void Game::initVariables() {
	this->window = nullptr;

}

void Game::initWindow() {
	this->videoMode.height = 800;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(videoMode, "Sudoku");
}

void Game::initScreen() {
	this->currentScreen = screenState::MENU;
	int k = 6;
	menu.push_back(Screen());
}

//Constructor / Destructor
Game::Game() {
	initVariables();
	initWindow();
	initScreen();
}

Game::~Game() {
	delete this->window;
}

//Accessors
const bool Game::isRunning() const {
	return this->window->isOpen();
}

//Getters
const Game::screenState Game::getScreenState() const {
	return currentScreen;
}

//Setters
void Game::setScreenState(screenState state) {
	this->currentScreen = state;
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->ev)) {
		if (this->ev.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

//Functions
void Game::update() {
	pollEvents();
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
	// 
	Button kek("menu/exit.png");
	//this->window->draw();

	this->window->display();
}