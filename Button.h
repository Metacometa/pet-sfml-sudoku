#include "Image.h"

//Children class that has own features for clicking and pointing

class Button : public InterfaceComponent {
	//Private functions
	void shrink();
	void unshrink();
public:
	//Constructor / Destructor
	Button(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name);
	virtual ~Button();

	//Functions
	virtual void update(const sf::Vector2f& mousePos);
};

