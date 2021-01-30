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
	float m_coordinates[2]{ 0.f, 0.f };
	
	Entity();
	Entity(std::shared_ptr<GameManager> game_manager);
	virtual ~Entity();
	
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::Time& deltaTime);
};

