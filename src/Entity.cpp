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
	/*for (auto c : m_components)
	{
		delete c;
	}*/
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

void Entity::beforeDraw()
{
	this->draw();

	if (m_components.size() == 0)
		return;

	for (Component* comp : m_components)
	{
		comp->draw();
	}
}

void Entity::beforeUpdate(float dt)
{
	this->update(dt);

	if (m_components.size() == 0)
		return;

	for (Component* comp : m_components)
	{
		comp->update(dt);
	}
}
