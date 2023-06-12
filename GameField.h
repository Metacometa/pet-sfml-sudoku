#pragma once

#include "SFML/Graphics.hpp"

#include "Properties.h"

#include "Image.h"
#include "SudokuEngine.h"

class GameField : public UIComponent
{
	std::weak_ptr<UIComponent> clickedSquare;
	int clicked_square_i = -1;
	int clicked_square_j = -1;

	std::vector<std::vector<std::shared_ptr<UIComponent>>> components;

	std::list<std::weak_ptr<IRenderable>> renderableComponents;
	std::list<std::weak_ptr<IUpdateable>> updateableComponents;
	std::list<std::weak_ptr<IClickable>> clickableComponents;

	SudokuEngine sudoku;
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>>* p_textures;

public:
	GameField(std::unordered_map<std::string, std::shared_ptr<sf::Texture>> *textures);
	virtual ~GameField();

	void render(sf::RenderTarget* target);
	void update(const sf::Vector2f& mousePos);
	void click(const sf::Vector2f& mousePos);
	void press(const sf::Keyboard::Key &key);

	void updateSquare(const int&i, const int&j);
	void generateNewField();
	void takeback();
};

