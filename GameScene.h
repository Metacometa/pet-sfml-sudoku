#pragma once
#include "Scene.h"
#include "GameField.h"

class GameScene : public Scene
{
	std::shared_ptr<GameField> game_field;
public:
	GameScene();
	virtual ~GameScene();
};

