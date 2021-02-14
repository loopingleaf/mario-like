#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

class Entity;
class Component
{
public:
	Entity* m_entity;

	Component() : m_entity(nullptr) {};
	Component(Entity* entity) : m_entity(entity) {};

	virtual void update(float dt);
	virtual void draw();
};
