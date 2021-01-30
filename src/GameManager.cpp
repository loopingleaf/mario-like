#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameManager.h"

GameManager::GameManager()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Mari0");
	inputManager;
	inputManager.loadConfig();
}

GameManager::GameManager(const int windowW, const int windowH)
{
	window = new sf::RenderWindow(sf::VideoMode(windowW, windowH), "Mari0");
	windowWidth = windowW;
	windowHeight = windowH;
	inputManager;
	inputManager.loadConfig();
}

void GameManager::start()
{
	clock;

	// Main loop
	while (window->isOpen())
	{
		deltaTime = clock.restart();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		window->clear();
		window->display();

		update();
		draw();
	}
}

void GameManager::update()
{
	for (Entity* entity : entities)
	{
		entity->update(deltaTime);
	}
}

void GameManager::draw()
{
	for (Entity* entity : entities)
	{
		entity->draw(deltaTime);
	}
}
