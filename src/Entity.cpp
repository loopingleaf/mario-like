#include "../include/Entity.h"

int Entity::endValueIds = 0;

Entity::Entity():gm(nullptr)
{
	identity = ++endValueIds;
}

Entity::Entity(GameManager* game_manager): gm(game_manager)
{
	game_manager->entities.push_back(this);
	identity = ++endValueIds;
}

Entity::~Entity()
{
	const auto iterator = std::find(gm->entities.begin(), gm->entities.end(), this);
	if(iterator!=gm->entities.end())
	{
		gm->entities.erase(iterator);
	}
}

void Entity::draw()
{
	
}

void Entity::update(sf::Time deltaTime)
{
	for(IComponent* comp : components)
	{
		comp->update(deltaTime);
	}
		
	
}
