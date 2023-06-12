#pragma once
#include <vector>
#include "GameSceneConfig.h"

#include <time.h>

class SudokuEngine
{
public:
	SudokuEngine();
	std::vector<std::vector<short>> field;
	
	int take_back_i = -1;
	int take_back_j = -1;
	int take_back_value = -1;

	void generateField();
	void takeback();
};

