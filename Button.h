#include "Properties.h"

class Button {
	//Resources
	sf::Sprite sprite;

	//Variables
	sf::Vector2f pos;

	//Private functions
	void shrink(const sf::Vector2f& mousePos);
public:
	//Constructor / Destructor
	Button(const sf::Texture* texture, const sf::Vector2f& pos);
	virtual ~Button();

	//Getters

	//Setters
	const sf::Sprite getSprite() const;

	//Functions

	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget* target);

};

