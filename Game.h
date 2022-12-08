#pragma once
#include "Screen.h"

const int SCREENS = 3;

/*
	Class that acts as the game engine.
	Wrapper class;
*/

class Game {	
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Screen
	enum class screenState {MENU, LOAD, GAME};  
	screenState currentScreen;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Screen*> menu;
	
	//Private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initScreens();
public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool isRunning() const;

	//Getters
	const screenState getScreenState() const;

	//Setters
	void setScreenState(screenState state);

	//Functions
    void pollEvents();
	void update();
	void render();
};

