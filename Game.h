#pragma once
#include "Interface.h"

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game : public Interface {	
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosWorld;

	//Player input
	bool isLeftButtonPressed;

	//Resources
	
	//Private functions
	void initVariables();
	void initWindow();
	void initInterface();
public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool isRunning() const;

	//Getters

	//Setters

	//Functions
    void pollEvents();

	void updateMousePositions();
	void updateInput();

	void update();
	void render();
};

