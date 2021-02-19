#pragma once
#include "Entity.h"
#include "Component/CollisionBoxComponent.h"
#include "Component/SpriteComponent.h"
#include "Component/MovementComponent.h"

class Enemy : public Entity
{
public:
	/* Where the enemy takes damage */
	CollisionBoxComponent* m_hitBox;
	CollisionBoxComponent* m_collisionFeet;
	/* Where the enemy gives damage */
	CollisionBoxComponent* m_damageBox;
	SpriteComponent* m_sprite;
	MovementComponent* m_movement;

	Enemy();
	Enemy(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, std::string texturePath);
	Enemy(const Enemy& en);
	~Enemy();
	Enemy& operator=(const Enemy& en);

	void update(float dt) override;

private:
	/**
	 * \brief Kills this enemy.
	 * 
	 */
	void die();
};
