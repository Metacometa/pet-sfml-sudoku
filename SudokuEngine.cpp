#include "SudokuEngine.h"

SudokuEngine::SudokuEngine()
{
	field.resize(FIELD_SIZE);
	for (auto& i : field) {
		i.resize(FIELD_SIZE);
	}

	srand(time(0));
	generateField();
}

void SudokuEngine::generateField()
{
	for (auto& i : field) {
		for (auto& j : i) {
			j = rand() % 10;
		}
	}
}

void SudokuEngine::takeback()
{
	if (take_back_value != -1) {
		field[take_back_i][take_back_j] = take_back_value;
	}
}
