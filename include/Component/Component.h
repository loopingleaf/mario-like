#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

class Entity;
class Component
{
public:
	Entity* entity;
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::Time& deltaTime);

	//TODO Destructor
	
};
