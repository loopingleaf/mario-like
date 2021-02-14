#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "InputManager.h"

class Entity;
class GameManager
{
public :
	int windowHeight = 720;
	int windowWidth = 1280;
	sf::Time deltaTime;
	sf::RenderWindow* window;
	std::vector<Entity*> entities;
	sf::Clock clock;
	InputManager inputManager;
	GameManager();
	GameManager(const int windowW, const int windowH);
	~GameManager() = default;

	void start();

	/**
	 * \brief Logic loop
	 */
	void update(float dt);

	/**
	 * \brief Render loop
	 */
	void draw();	
};
