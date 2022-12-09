#pragma once
#include "Interface.h"

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game {	
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosWorld;

	//Interface
	enum class interfaceState {MENU, LOAD, GAME};  
	interfaceState currentInterface;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Interface> menu;
	
	//Private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initInterface();
public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool isRunning() const;
	const int IntInterfaceState() const;

	//Getters

	//Setters
	void setInterfaceState(interfaceState state);

	//Functions
    void pollEvents();
	void updateMousePositions();
	void updateInterface();
	void update();
	void render();
};

