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
	CollisionBoxComponent* m_collisionBox;
	SpriteComponent* m_sprite;

	Player() = default;
	Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates);
	~Player();

	void update(float dt) override;
	std::string getName() override;
};
