#include "GameField.h"

GameField::GameField(std::unordered_map<std::string, std::shared_ptr<sf::Texture>>* textures)
{
	sf::Vector2f firstSquarePos = *FIELD_POS;
	sf::Vector2f squarePos = firstSquarePos;

	p_textures = textures;

	for (int i = 0; i < FIELD_SIZE; ++i)
	{
		components.emplace_back(std::vector<std::shared_ptr<UIComponent>>());
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			components[i].emplace_back(new Image((*p_textures)[*NUMBER_PATH + "0.png"], squarePos));

			renderableComponents.emplace_back(components[i].back());
			updateableComponents.emplace_back(components[i].back());
			clickableComponents.emplace_back(components[i].back());

			squarePos.x += 57;
		}

		squarePos.x = firstSquarePos.x;
		squarePos.y += 57;
	}
}

GameField::~GameField() {}

void GameField::render(sf::RenderTarget* target)
{
	for (auto& renderable : renderableComponents) {
		renderable.lock()->render(target);
	}
}

void GameField::update(const sf::Vector2f& mousePos)
{
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			updateSquare(i, j);
		}
	}

	for (auto& i : components) {
		for (auto& j : i) {
			if (j.get()->isPointed(mousePos)) {
				j.get()->setColor(sf::Color{ 250, 230, 202 });
			}
			else {
				j.get()->setDefaultColor();
			}
		}
	}

	if (clicked_square_i != -1 and clicked_square_j != -1) {
		components[clicked_square_i][clicked_square_j]->setColor(sf::Color{ 175,200,182 });
	}
}

void GameField::click(const sf::Vector2f& mousePos)
{
	if (clicked_square_i != -1 and clicked_square_j != -1) {
		components[clicked_square_i][clicked_square_j]->setDefaultColor();
	}
	clicked_square_i = -1;
	clicked_square_j = -1;

	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			if (components[i][j]->isPointed(mousePos)) {
				clicked_square_i = i;
				clicked_square_j = j;
			}
		}
	}
}

void GameField::press(const sf::Keyboard::Key &key)
{
	std::cout << key << " " << sf::Keyboard::BackSpace << std::endl;
	int new_value = key - 26;
	if (key == sf::Keyboard::BackSpace) {
		new_value = 0;
	}

	sudoku.take_back_i = clicked_square_i;
	sudoku.take_back_j = clicked_square_j;
	sudoku.take_back_value = sudoku.field[clicked_square_i][clicked_square_j];

	sudoku.field[clicked_square_i][clicked_square_j] = new_value;

}

void GameField::updateSquare(const int& i, const int& j)
{
	//std::cout << sudoku.field[i][j] << std::endl;
	char path = static_cast<char>(sudoku.field[i][j] + 48);
	components[i][j]->getSprite().setTexture(*(*p_textures)[*NUMBER_PATH + path + ".png"].get());
}

void GameField::generateNewField()
{
	sudoku.generateField();
}

void GameField::takeback()
{
	sudoku.takeback();
}
