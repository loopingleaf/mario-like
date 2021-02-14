#pragma once
#include "Entity.h"
#include "Component/CollisionBoxComponent.h"
#include "Component/SpriteComponent.h"

class Ground : public Entity
{
public:
	CollisionBoxComponent m_collisionBox;
	SpriteComponent* m_sprite;

	Ground() : Entity(), m_sprite(new SpriteComponent()) {};
	Ground(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, const std::string& name, std::string texturePath);
	~Ground() override;
};

