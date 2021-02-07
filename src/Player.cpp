#include "Player.h"
#include "Component/MovementComponent.h"
#include "Component/SpriteComponent.h"

Player::Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates)
	: Entity(gameManager, coordinates)
{
	m_movementComponent = MovementComponent(this, 100.f, 0.f, 4.f, 4.f, 200.f, true, sf::Vector2f(0.f, 1.f), false);
	m_components.push_back(&m_movementComponent);
	std::string texturePath = "data/textures/player.png";
	Component* sprite = new SpriteComponent(texturePath, this);
	m_components.push_back(sprite);
}

void Player::update(sf::Time deltaTime)
{
	m_movementComponent.speed = 2.f;
}
