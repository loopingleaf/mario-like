#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "InputManager.h"

class Entity;
class GameManager
{
public :
	static const std::string LEVEL_FILEPATH;
	int windowHeight = 720;
	int windowWidth = 1280;
	sf::Time deltaTime;
	sf::RenderWindow* window;
	std::vector<Entity*> entities;
	sf::Clock clock;
	InputManager inputManager;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	GameManager();
	GameManager(const int windowW, const int windowH);
	GameManager(const GameManager& gm);
	~GameManager();
	GameManager& operator=(const GameManager& gm);

	void start(std::shared_ptr<GameManager> gm);

	/**
	 * \brief Generates the level, using the level.json file.
	 * 
	 */
	void generateLevel(std::shared_ptr<GameManager> gm);

	/**
	 * \brief Logic loop
	 */
	void update(float dt);

	/**
	 * \brief Render loop
	 */
	void draw();	

private:
	std::vector<Entity*> m_level;
};
