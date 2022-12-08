#include "Image.h"

class Button : public InterfaceComponent{
	//Private functions
	void shrink(const sf::Vector2f& mousePos);
public:
	//Constructor / Destructor
	Button(const sf::Texture* texture, const sf::Vector2f& pos);
	virtual ~Button();

	//Functions
	virtual void update(const sf::Vector2f& mousePos);
};

