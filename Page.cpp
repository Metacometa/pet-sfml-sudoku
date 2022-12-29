#include "Page.h"

//Contrcutors / Destructors
Page::Page() {
}

Page::~Page() {
	for (auto* i : interfaceComponents)
		delete i;
}

//Functions
void Page::addButton(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name) {
	interfaceComponents.push_back(new Button(texture, pos, name));
}

void Page::addImage(const sf::Texture* texture, const sf::Vector2f& pos, InterfaceBlock name) {
	interfaceComponents.push_back(new Image(texture, pos, name));
}

void Page::switchPage(const InterfaceBlock &gottenBlock, InterfacePage& page, sf::RenderWindow* window) {
	switch (gottenBlock) {
		case InterfaceBlock::NEW_GAME: {
			page = InterfacePage::GAME;
			std::cout << "New_game clicked" << std::endl;
			break;
		}
		case InterfaceBlock::LOAD_GAME: {
			std::cout << "Load_game clicked" << std::endl;
			break;
		}
		case InterfaceBlock::EXIT: {
			window->close();
			std::cout << "Exit clicked" << std::endl;
			break;
		}
		case InterfaceBlock::BACK:
			page = InterfacePage::MENU;
	}
}

void Page::updateInterfaceComponents(const sf::Vector2f& mousePos, const bool &isLeftButtonPressed, InterfacePage &page, sf::RenderWindow* window) {
	for (auto* i : interfaceComponents) {
		i->update(mousePos);

		if (i->isPointed(mousePos) && isLeftButtonPressed) {
			switchPage(i->getInterfaceBlock(), page, window);
		}
	}
}

void Page::renderInterfaceComponents(sf::RenderTarget* target) {
	for (auto *i : interfaceComponents)
		i->render(target);
}