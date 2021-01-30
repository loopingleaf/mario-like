#include "Entity.h"

int Entity::endValueIds = 0;

Entity::Entity(): m_gm(nullptr)
{
	m_identity = ++endValueIds;
}

Entity::Entity(std::shared_ptr<GameManager> game_manager): m_gm(game_manager)
{
	game_manager->entities.push_back(this);
	m_identity = ++endValueIds;
}

Entity::~Entity()
{
	const auto iterator = std::find(m_gm->entities.begin(), m_gm->entities.end(), this);
	if(iterator != m_gm->entities.end())
	{
		m_gm->entities.erase(iterator);
	}
}

void Entity::draw(sf::Time& deltaTime)
{
	for (Component* comp : m_components)
	{
		comp->draw(deltaTime);
	}
}

void Entity::update(sf::Time deltaTime)
{
	for (Component* comp : m_components)
	{
		comp->update(deltaTime);
	}	
}
