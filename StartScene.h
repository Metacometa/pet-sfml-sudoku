#pragma once
#include "Scene.h"

#include "Button.h"

class StartScene : public Scene
{
public:
	StartScene();
	StartScene(const StartScene& scene) = delete;
	virtual ~StartScene();
};

