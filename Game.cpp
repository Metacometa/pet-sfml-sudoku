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

void Game::initTextures() {
	this->textures["NEW"] = new sf::Texture();
	this->textures["NEW"]->loadFromFile("assets/new_game.png");

	this->textures["LOAD"] = new sf::Texture();
	this->textures["LOAD"]->loadFromFile("assets/load_game.png");

	this->textures["EXIT"] = new sf::Texture();
	this->textures["EXIT"]->loadFromFile("assets/exit.png");
}

void Game::initScreens() {
	this->currentScreen = screenState::MENU; 
	this->menu.push_back(new Screen());
	this->menu[(int)screenState::MENU]->addButton(this->textures["NEW"]);

	this->menu.push_back(new Screen());

	this->menu.push_back(new Screen());
}

//Constructor / Destructor
Game::Game() {
	initVariables();
	initWindow();
	initScreens();
}

Game::~Game() {
	//Delete menu
	for (auto& i : menu)
		delete i;

	//Delete textures
	for (auto& i : textures)
		i.second;
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
	Button kek("assets/load_game.png");
	this->window->draw(kek.getSprite());
	//this->window->draw();

	this->window->display();
}