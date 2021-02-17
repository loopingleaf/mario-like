#pragma once
#include "Entity.h"
#include "Component/CollisionBoxComponent.h"
#include "Component/SpriteComponent.h"

class Ground : public Entity
{
public:
	static const std::string NAME;
	CollisionBoxComponent* m_collisionBox;
	SpriteComponent* m_sprite;

	Ground();
	Ground(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, std::string texturePath);
	~Ground() override;

	std::string getName() override;
};

