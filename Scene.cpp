#include "Scene.h"

void Scene::update(const sf::Vector2f& mousePos)
{
	for (auto& i : updateableComponents) {
		i.lock()->update(mousePos);
	}
}

void Scene::render(sf::RenderTarget* target)
{
	for (auto& i : renderableComponents) {
		i.lock()->render(target);
	}
}

void Scene::click(const sf::Vector2f& mousePos)
{
	for (auto& i : clickableComponents) {
		i.lock()->click(mousePos);
	}
}

