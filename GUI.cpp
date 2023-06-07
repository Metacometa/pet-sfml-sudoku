#include "GUI.h"

GUI::GUI()
{
	scenes.emplace_back(new StartScene);

	updateableScenes.emplace_back(scenes.back());
	renderableScenes.emplace_back(scenes.back());
}

GUI::~GUI()
{

}

void GUI::update()
{
	for (auto &i : updateableScenes) {
		i.lock()->update();
	}
}

void GUI::render(sf::RenderTarget* target)
{
	for (auto& i : scenes) {
	}

	for (auto& i : renderableScenes) {
		i.lock()->render(target);
	}
}
