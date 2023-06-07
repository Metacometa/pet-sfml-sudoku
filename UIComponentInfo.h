#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <functional>

struct UIComponentInfo {
	UIComponentInfo(const std::shared_ptr<std::string> &asset_path_, const std::shared_ptr<sf::Vector2f> &pos_) : asset_path(asset_path_), pos(pos_) {}
	UIComponentInfo() {};

	std::shared_ptr<std::string> asset_path;
	std::shared_ptr<sf::Vector2f> pos;
	std::function<void()> action = []() { std::cout << "Default function" << std::endl; };
};