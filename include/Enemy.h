#pragma once
#include "Entity.h"
#include "Component/CollisionBoxComponent.h"
#include "Component/SpriteComponent.h"
#include "Component/MovementComponent.h"

class Enemy : public Entity
{
public:
	CollisionBoxComponent* m_hitBox;
	CollisionBoxComponent* m_collisionFeet;
	SpriteComponent* m_sprite;
	MovementComponent* m_movement;

	Enemy();
	Enemy(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, std::string texturePath);
	Enemy(const Enemy& en);
	~Enemy();
	Enemy& operator=(const Enemy& en);

	//void die();
};
