#pragma once

#include <memory>
#include "IComponent.h"
#include "GameManager.h"
#include "vector"

class GameManager;
class IComponent;

class Entity
{
public:
	static int endValueIds;
	
	std::unique_ptr<GameManager> gm;
	std::vector<IComponent*> components;
	int identity;                            // TODO Checker la pertinence de identity
	float coordinates[2]{ 0.f, 0.f };
	
	Entity();
	Entity(GameManager* game_manager);
	~Entity();
	
	virtual void update(sf::Time deltaTime);
	virtual void draw();
	
};

