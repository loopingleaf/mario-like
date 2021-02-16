#pragma once
#include "Entity.h"
#include "Component/CollisionBoxComponent.h"
#include "Component/SpriteComponent.h"
#include "Component/MovementComponent.h"

class Ennemy : public Entity
{
public:
	CollisionBoxComponent* m_hitBox;
	CollisionBoxComponent* m_collisionFeet;
	SpriteComponent* m_sprite;
	MovementComponent* m_movement;

	Ennemy();
	Ennemy(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates);
	~Ennemy();

	//void die();
};
