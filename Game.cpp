#include "Game.h"

//Private functions
void Game::initVariables() 
{
}

void Game::initWindow() 
{
	//set screen properties
	this->videoMode.height = 800;
	this->videoMode.width = 800;
	this->window = std::make_shared<sf::RenderWindow>(videoMode, "Sudoku");

}

void Game::initInterface() 
{
	gui = new GUI(window);
}

//Constructor / Destructor
Game::Game() 
{
	this->initWindow();
	this->initInterface();
}

Game::~Game() 
{
	//delete this->window;
}

//Accessors
const bool Game::isRunning() const 
{
	return this->window->isOpen();
}

sf::RenderWindow* Game::getWindow() const
{
	return this->window.get();
}

sf::Vector2f Game::getMousePos() const
{
	return mousePosWorld;
}

//Getters

//Setters

//Functions
void Game::pollEvents() {
	while (this->window->pollEvent(this->ev)) 
	{
		updateInput();
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

	switch (this->ev.type) {
		std::cout << "switch" << std::endl;
		case sf::Event::Closed:
			this->window->close();
		case sf::Event::MouseButtonPressed:
			if (ev.mouseButton.button == sf::Mouse::Left)
			{
				isLeftButtonPressed = true;
			}
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::BackSpace) {
				isKeyPressed = true;
				pressedKey = ev.key.code;
			}
			else if (ev.key.code >= sf::Keyboard::Num1 and ev.key.code <= sf::Keyboard::Num9) {
				isKeyPressed = true;
				pressedKey = ev.key.code;
			}
	}
}

void Game::update(const sf::Vector2f& mousePos) {
	this->pollEvents();

	this->updateMousePositions();
	//this->updateInput();

	gui->update(mousePos);

	if (isLeftButtonPressed) 
	{
		gui->click(mousePos);
	}

	if (isKeyPressed and pressedKey != sf::Keyboard::Unknown)
	{
		gui->press(pressedKey);
	}

	isKeyPressed = false;
	pressedKey = sf::Keyboard::Unknown;
	isLeftButtonPressed = false;
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