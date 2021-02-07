#pragma once

#include <memory>
#include "Component/Component.h"
#include "GameManager.h"
#include "vector"

class GameManager;
class Component;

class Entity
{
public:
	static int endValueIds;
	
	std::shared_ptr<GameManager> m_gm;
	std::vector<Component*> m_components;
	int m_identity;                            // TODO Checker la pertinence de identity
	sf::Vector2f m_coordinates;
	
	Entity();
	Entity(std::shared_ptr<GameManager> game_manager, sf::Vector2f coordinates);
	virtual ~Entity();
	
	virtual void update(sf::Time deltaTime);
	virtual void draw();

	virtual void beforeUpdate(sf::Time deltaTime) final;
	virtual void beforeDraw() final;
};

