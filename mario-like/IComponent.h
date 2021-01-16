#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Entity;
class IComponent
{
public:
	Entity* entity;
	virtual void update(sf::Time deltaTime) = 0;

	//TODO Destructor
	
};

