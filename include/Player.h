#pragma once
#include "Component/MovementComponent.h"
#include "Component/CollisionBoxComponent.h"
#include "Entity.h"

class Player : public Entity
{
public:
	MovementComponent m_movementComponent;
	CollisionBoxComponent m_collisionBox;
	//TEST CAMERA
	sf::View view;

	Player() = default;
	Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, const std::string& name);
	~Player() = default;

	void update(float dt) override;
};
