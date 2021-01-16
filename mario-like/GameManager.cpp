#include <SFML/Graphics.hpp>
#include "GameManager.h"

#include <iostream>

GameManager::GameManager() : window(nullptr)
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Mari0");
	clock;
}

GameManager::GameManager(const int windowW, const int windowH) : window(nullptr)
{
	window = new sf::RenderWindow(sf::VideoMode(windowW, windowH), "Mari0");
	windowWidth = windowW;
	windowHeight = windowH;
	clock;
}

void GameManager::update()
{

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

		for(Entity* entity : entities)
		{
			entity->update(deltaTime);
		}
	}



}

void GameManager::draw()
{
	
}
