#include <iostream>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "GameManager.h"
#include "nlohmann/json.hpp"
#include "Ground.h"

const std::string GameManager::LEVEL_FILEPATH = "data/config/level.json";

GameManager::GameManager()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Mari0");
	inputManager;
	inputManager.loadConfig();
	deltaTime = sf::Time();
	font.loadFromFile("data/fonts/Minecraft.ttf");
	scoreText.setFont(font);
	backgroundTexture.loadFromFile("data/textures/bgSky.png");
	background.setTexture(backgroundTexture);
	background.setScale(3.f,1.f);
	background.setPosition(-300.f, -1152.f / 2);
	scoreText.setString("score : 000");
	scoreText.setCharacterSize(24);
	scoreText.setColor(sf::Color::Black);
	window->draw(scoreText);
}

GameManager::GameManager(const int windowW, const int windowH)
{
	window = new sf::RenderWindow(sf::VideoMode(windowW, windowH), "Mari0");
	windowWidth = windowW;
	windowHeight = windowH;
	inputManager;
	inputManager.loadConfig();
	deltaTime = sf::Time();
	backgroundTexture.loadFromFile("data/textures/bgSky.png");
	background.setTexture(backgroundTexture);
	background.setScale(2.f, 1.f);
}

GameManager::GameManager(const GameManager& gm)
	: window(gm.window), windowWidth(gm.windowWidth), windowHeight(gm.windowHeight),
	inputManager(gm.inputManager), deltaTime(gm.deltaTime)
{
}

GameManager::~GameManager()
{
	for (Entity* entity : m_level)
	{
		delete entity;
	}
}

GameManager& GameManager::operator=(const GameManager& gm)
{
	window = gm.window;
	windowWidth = gm.windowWidth;
	windowHeight = gm.windowHeight;
	inputManager = gm.inputManager;
	deltaTime = gm.deltaTime;
	return *this;
}

void GameManager::start(std::shared_ptr<GameManager> gm)
{
	generateLevel(gm);
	clock;
	const float fixedDt = 0.01f;
	float accumulator = 0.f;

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
		accumulator += deltaTime.asSeconds();
		//std::cout << "DT=" << deltaTime.asSeconds() << std::endl;
		while (accumulator >= fixedDt)
		{
			//std::cout << "ACC=" << accumulator << std::endl;
			update(fixedDt);
			accumulator -= fixedDt;
		}
		window->clear();
		draw();
		window->display();
	}
}

void GameManager::generateLevel(std::shared_ptr<GameManager> gm)
{
	std::ifstream file(LEVEL_FILEPATH);
	nlohmann::json json;
	file >> json;
	for (auto it = json.begin(); it != json.end(); ++it)
	{
		if (it.key() == "level")
		{
			for (auto it2 = it.value().begin(); it2 != it.value().end(); ++it2)
			{
				Entity* newGround = new Ground(gm, sf::Vector2f(it2.value()[0], it2.value()[1]), "data/textures/ground.png");
				m_level.push_back(newGround);
			}
		}
		/*else if (it.key() == "enemy")
		{

		}*/
	}
}

void GameManager::update(float dt)
{
	for (Entity* entity : entities)
	{
		entity->updateAll(dt);
	}
}

void GameManager::draw()
{
	window->draw(background);
	window->draw(scoreText);
	// scoreText.setPosition(window->getView().getCenter().x - 550, window->getView().getCenter().y - 320);
	for (Entity* entity : entities)
	{
		entity->drawAll();
	}
	
}
