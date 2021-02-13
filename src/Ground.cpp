#include <iostream>
#include "Ground.h"
#include "Player.h"

Ground::Ground(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, const std::string& name, std::string texturePath)
	: Entity(gameManager, coordinates, name)
{
	m_sprite = new SpriteComponent(texturePath, this);
	m_components.push_back(m_sprite);
	sf::Vector2f v = (sf::Vector2f) m_sprite->m_texture.getSize();
	sf::Vector2f scale = m_sprite->m_sprite.getScale();
	v.x *= scale.x;
	v.y *= scale.y;
	std::cout << v.x << std::endl;
	m_collisionBox = CollisionBoxComponent(this, v);
	m_components.push_back(&m_collisionBox);
}

Ground::~Ground()
{
	delete m_sprite;
}

void Ground::update(sf::Time deltaTime)
{
	for (const CollisionBoxComponent* cb : CollisionBoxComponent::all)
	{
		if (cb->m_entity->m_name == "Player")
		{
			// TODO: Player.isgrounded = true;
		}
	}
}

