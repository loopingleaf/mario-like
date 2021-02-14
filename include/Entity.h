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
 	std::string m_name;
	sf::Vector2f m_coordinates;
	
	Entity();
	Entity(std::shared_ptr<GameManager> game_manager, sf::Vector2f coordinates, const std::string& name);
	virtual ~Entity();
	
	virtual void update(float dt);
	virtual void draw();

	virtual void beforeUpdate(float dt) final;
	virtual void beforeDraw() final;
};
