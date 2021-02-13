#include <iostream>
#include "Entity.h"

int Entity::endValueIds = 0;

Entity::Entity(): m_gm(nullptr), m_coordinates(sf::Vector2f(0.f, 0.f)), m_name("")
{

}

Entity::Entity(std::shared_ptr<GameManager> game_manager, sf::Vector2f coordinates, const std::string& name)
	: m_gm(game_manager), m_coordinates(coordinates), m_name(name)
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

void Entity::update(sf::Time deltaTime)
{
}

void Entity::draw()
{
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

void Entity::beforeUpdate(sf::Time deltaTime)
{
	this->update(deltaTime);

	if (m_components.size() == 0)
		return;

	for (Component* comp : m_components)
	{
		comp->update(deltaTime);
	}
}
