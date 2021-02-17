#include <iostream>
#include "Ground.h"
#include "Player.h"

const std::string Ground::NAME = "ground";

Ground::Ground()
	: Entity(), m_sprite(nullptr), m_collisionBox(nullptr)
{
}

Ground::Ground(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, std::string texturePath)
	: Entity(gameManager, coordinates)
{
	m_sprite = new SpriteComponent(texturePath, this);
	m_components.push_back(m_sprite);
	sf::Vector2f v = (sf::Vector2f) m_sprite->m_texture.getSize();
	sf::Vector2f scale = m_sprite->m_sprite.getScale();
	v.x *= scale.x;
	v.y *= scale.y;
	m_collisionBox = new CollisionBoxComponent(this, v, "ground");
	m_components.push_back(m_collisionBox);
}

Ground::~Ground()
{
	delete m_collisionBox;
	delete m_sprite;
}

std::string Ground::getName()
{
	return NAME;
}
