#include "Ennemy.h"

Ennemy::Ennemy()
{
}

Ennemy::Ennemy(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates)
	: Entity(gameManager, coordinates)
{
	sf::Vector2f size(4.f, 4.f);
	sf::Vector2f rPosition(10.f, -3.f);
	m_hitBox = new CollisionBoxComponent(this, size, "hit", rPosition);
	m_components.push_back(m_hitBox);
}

Ennemy::~Ennemy()
{
}
