#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player() = default;
	Player(std::shared_ptr<GameManager> gameManager);
	~Player() = default;

	void update(sf::Time deltaTime) override;
};
