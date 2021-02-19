#include "SFML/Graphics.hpp"
#include "Enemy.h"

Enemy::Enemy()
	: Entity(),  m_hitBox(nullptr), m_collisionFeet(nullptr), m_sprite(nullptr), m_movement(nullptr)
{
}

Enemy::Enemy(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, std::string texturePath)
	: Entity(gameManager, coordinates)
{
	m_sprite = new SpriteComponent(texturePath, this);
	m_components.push_back(m_sprite);
	sf::Vector2f spriteSize = (sf::Vector2f) m_sprite->m_sprite.getTexture()->getSize();
	sf::Vector2f scale = m_sprite->m_sprite.getScale();
	spriteSize.x *= scale.x;
	spriteSize.y *= scale.y;

	sf::Vector2f hbSize(spriteSize.x, 5.f);
	sf::Vector2f hbPosition(10.f, -3.f);
	m_hitBox = new CollisionBoxComponent(this, hbSize, "hit", sf::Vector2f(0.f, -3.f));
	m_components.push_back(m_hitBox);
	
	sf::Vector2f fSize(spriteSize.x, 5.f);
	m_collisionFeet = new CollisionBoxComponent(this, fSize, "feet", sf::Vector2f(0.f, spriteSize.y - fSize.y));
	m_components.push_back(m_collisionFeet);

	sf::Vector2f dbSize(spriteSize.x, spriteSize.y - 5.f);
	m_damageBox = new CollisionBoxComponent(this, dbSize, "dammage", sf::Vector2f(0.f, spriteSize.y - fSize.y));

	m_movement = new MovementComponent(this, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, true, sf::Vector2f(), false);
	m_components.push_back(m_movement);
}

Enemy::Enemy(const Enemy& en)
	: m_hitBox(en.m_hitBox), m_collisionFeet(en.m_collisionFeet), m_sprite(en.m_sprite), m_movement(en.m_movement)
{
}

Enemy::~Enemy()
{
	delete m_hitBox;
	delete m_collisionFeet;
	delete m_sprite;
	delete m_movement;
}

Enemy& Enemy::operator=(const Enemy& en)
{
	m_collisionFeet = en.m_collisionFeet;
	m_hitBox = en.m_hitBox;
	m_sprite = en.m_sprite;
	m_movement = en.m_movement;
	m_components.push_back(m_collisionFeet);
	m_components.push_back(m_hitBox);
	m_components.push_back(m_sprite);
	m_components.push_back(m_movement);
	return *this;
}

void Enemy::update(float dt)
{
	for (const CollisionBoxComponent* other : m_hitBox->collisionList())
	{
		if (other->m_tag == "playerFeet")
		{
			die();
		}
	}
}

void Enemy::die()
{
	m_gm->score += 100;
	m_gm->scoreText.setString("score : " + std::to_string(m_gm->score));
	const auto iterator = std::find(m_gm->entities.begin(), m_gm->entities.end(), this);
	if (iterator != m_gm->entities.end())
	{
		m_gm->entities.erase(iterator);
	}
}
