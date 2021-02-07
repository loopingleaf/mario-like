#pragma once
#include "Component/MovementComponent.h"
#include "Entity.h"

class Player : public Entity
{
public:
	MovementComponent m_movementComponent;
	Player() = default;
	Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates);
	~Player() = default;

	void update(sf::Time deltaTime) override;
};
