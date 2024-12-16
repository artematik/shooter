#pragma once
#include "AssetManager.h"
class GameEngine
{
public:
	GameEngine();

	void run();

private:
	AssetManager m_manager;
	sf::RenderWindow m_window;
	sf::RectangleShape m_background = sf::RectangleShape(sf::Vector2f(1280, 720));
	sf::Image m_icon;

	void input();
	void update(sf::Time const& deltaTime);
	void draw();
};

