#include "Scene.h"

void Scene::update()
{
	for (auto& i : updateableComponents) {
		i.lock()->update();
	}
}

void Scene::render(sf::RenderTarget* target)
{
	for (auto& i : renderableComponents) {
		i.lock()->render(target);
	}
}

