#pragma once

#include "Properties.h"

#include "GUI.h"
#include "IRenderable.h"
#include "IUpdateable.h"

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game : public IRenderable, public IUpdateable {	
	//Variables
	GUI* gui;
	
	//Window
	std::shared_ptr<sf::RenderWindow> window = nullptr;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosWorld;

	//Player input
	bool isLeftButtonPressed = false;

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
	sf::RenderWindow* getWindow() const;
	sf::Vector2f getMousePos() const;

	//Setters

	//Functions
    void pollEvents();

	void updateMousePositions();
	void updateInput();

	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);
};

