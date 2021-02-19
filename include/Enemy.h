#pragma once
#include "Entity.h"
#include "Component/CollisionBoxComponent.h"
#include "Component/SpriteComponent.h"

class Enemy : public Entity
{
public:
	/* Where the enemy takes damage */
	CollisionBoxComponent* m_hitBox;
	/* Where the enemy gives damage */
	CollisionBoxComponent* m_damageBox;
	SpriteComponent* m_sprite;

	Enemy();
	Enemy(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, std::string texturePath);
	Enemy(const Enemy& en);
	~Enemy() override;
	Enemy& operator=(const Enemy& en);

	/**
	 * \brief Kills this enemy.
	 * 
	 */
	void die();

	void update(float dt) override;
};
