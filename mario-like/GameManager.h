#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"
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

	GameManager();
	GameManager(const int windowW, const int windowH);
	~GameManager() = default;

	void update();

	//TODO Gestion des boucles de draw
	void draw();

	
};

