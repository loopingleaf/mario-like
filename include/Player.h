#pragma once
#include "Component/SpriteComponent.h"
#include "Component/MovementComponent.h"
#include "Component/CollisionBoxComponent.h"
#include "Entity.h"

class Player : public Entity
{
public:
	static const std::string NAME;
	MovementComponent m_movementComponent;
	CollisionBoxComponent* m_collisionFeet;
	//CollisionBoxComponent* m_hitBox;
	SpriteComponent* m_sprite;
	//TEST CAMERA
	sf::View view;

	Player() = default;
	Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates);
	~Player();

	/**
	 * \brief When the player is hit.
	 * 
	 */
	void die();
	
	void update(float dt) override;
	std::string getName() override;
};
