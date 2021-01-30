#include "Player.h"
#include "Component/MovementComponent.h"
#include "Component/SpriteComponent.h"

Player::Player(std::shared_ptr<GameManager> gameManager)
	: Entity(gameManager)
{
	/*MovementComponent movement;
	m_components.push_back(&movement);*/
	sf::Texture texture;
	texture.loadFromFile("data/textures/player.png");
	SpriteComponent sprite(texture);
	m_components.push_back(&sprite);
}

void Player::update(sf::Time deltaTime)
{
}
