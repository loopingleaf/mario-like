#include "SFML/Graphics.hpp"
#include "Enemy.h"

Enemy::Enemy()
	: Entity(),  m_hitBox(nullptr), m_damageBox(nullptr), m_sprite(nullptr)
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

	sf::Vector2f hbSize(spriteSize.x, 20.f);
	sf::Vector2f hbPosition(10.f, -3.f);
	m_hitBox = new CollisionBoxComponent(this, hbSize, "hit", sf::Vector2f(0.f, -3.f));
	m_components.push_back(m_hitBox);
	
	/*sf::Vector2f fSize(spriteSize.x, 5.f);
	m_damageBox = new CollisionBoxComponent(this, fSize, "feet", sf::Vector2f(0.f, spriteSize.y - fSize.y));
	m_components.push_back(m_damageBox);*/

	sf::Vector2f dbSize(spriteSize.x, spriteSize.y - 30.f);
	m_damageBox = new CollisionBoxComponent(this, dbSize, "damage", sf::Vector2f(0.f, 40.f));
	m_components.push_back(m_damageBox);
}

Enemy::Enemy(const Enemy& en)
	: m_hitBox(en.m_hitBox), m_damageBox(en.m_damageBox), m_sprite(en.m_sprite)
{
}

Enemy::~Enemy()
{
	delete m_hitBox;
	delete m_sprite;
	delete m_damageBox;
}

Enemy& Enemy::operator=(const Enemy& en)
{
	m_damageBox = en.m_damageBox;
	m_hitBox = en.m_hitBox;
	m_sprite = en.m_sprite;
	m_components.push_back(m_damageBox);
	m_components.push_back(m_hitBox);
	m_components.push_back(m_sprite);
	return *this;
}

void Enemy::update(float dt)
{
	/*for (const CollisionBoxComponent* other : m_hitBox->collisionList())
	{
		if (other->m_tag == "playerFeet")
		{
			die();
		}
	}*/
}

void Enemy::die()
{
	m_gm->killSound.play();
	m_gm->score += 100;
	m_gm->scoreText.setString("score : " + std::to_string(m_gm->score));
	const auto iterator = std::find(m_gm->entities.begin(), m_gm->entities.end(), this);
	if (iterator != m_gm->entities.end())
	{
		delete *iterator;
	}
}
