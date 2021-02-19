#include <iostream>
#include "Entity.h"

const std::string Entity::NAME = "entity";

Entity::Entity(): m_gm(nullptr), m_coordinates(sf::Vector2f(0.f, 0.f))
{

}

Entity::Entity(std::shared_ptr<GameManager> game_manager, sf::Vector2f coordinates)
	: m_gm(game_manager), m_coordinates(coordinates)
{
	game_manager->entities.push_back(this);
}

Entity::~Entity()
{
	const auto iterator = std::find(m_gm->entities.begin(), m_gm->entities.end(), this);
	if(iterator != m_gm->entities.end())
	{
		m_gm->entities.erase(iterator);
	}
}

void Entity::update(float dt)
{
}

void Entity::draw()
{
}

std::string Entity::getName()
{
	return NAME;
}

void Entity::drawAll()
{
	if (m_components.size() == 0)
		return;

	for (Component* comp : m_components)
	{
		comp->draw();
	}

	this->draw();
}

void Entity::updateAll(float dt)
{
	if (m_components.size() == 0)
		return;

	for (Component* comp : m_components)
	{
		comp->update(dt);
	}

	this->update(dt);
}
