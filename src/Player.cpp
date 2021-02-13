#include "Player.h"
#include <iostream>
#include "Component/MovementComponent.h"
#include "Component/SpriteComponent.h"

Player::Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates, const std::string& name)
	: Entity(gameManager, coordinates, name)
{
	m_movementComponent = MovementComponent(this, 20.f, 0.f, 0.f, 10.f, 0.f, 45.f, true, sf::Vector2f(0.f, 0.f), true);
	m_components.push_back(&m_movementComponent);
	std::string texturePath = "data/textures/player.png";
	Component* sprite = new SpriteComponent(texturePath, this);
	m_components.push_back(sprite);
	m_collisionBox = CollisionBoxComponent(this, sf::Vector2f(40.f, 50.f));
	m_components.push_back(&m_collisionBox);
}

void Player::update(sf::Time deltaTime)
{
	if (!m_movementComponent.isGrounded)
	{
		if (m_movementComponent.jumpSpeed < 12.f)
		{
			m_movementComponent.jumpSpeed = m_movementComponent.jumpSpeed * 1.004f;
		}
		m_movementComponent.direction.y = 10.f * m_movementComponent.jumpSpeed;
	}
	
	if (!m_gm->inputManager.isPressed("left") && !m_gm->inputManager.isPressed("right"))
	{
		m_movementComponent.direction.x = 0.f;
		m_movementComponent.speed = 0.f;
		m_movementComponent.jumpSpeed = 10.f;
	}

	if ((!m_gm->inputManager.isPressed("jump") && m_movementComponent.jumpHeight > 0.f) || m_movementComponent.jumpHeight >= m_movementComponent.jumpMaxHeight)
	{
		m_movementComponent.jumpHeight -= 0.1f;
		if (m_movementComponent.jumpSpeed < 12.f)
		{
			m_movementComponent.jumpSpeed = m_movementComponent.jumpSpeed * 1.004f;
		}
		m_movementComponent.direction.y = 10.f * m_movementComponent.jumpSpeed;
		m_movementComponent.isGrounded = false;
	}

	if (m_gm->inputManager.isPressed(("jump")) && m_movementComponent.isGrounded && m_movementComponent.jumpHeight < m_movementComponent.jumpMaxHeight)
	{
		m_movementComponent.jumpHeight += 0.1f;
		if (m_movementComponent.jumpSpeed < 12.f)
		{
			m_movementComponent.jumpSpeed = m_movementComponent.jumpSpeed * 0.997f;
		}
		m_movementComponent.direction.y = -10.f * m_movementComponent.jumpSpeed;
	}
	
	if(m_gm->inputManager.isPressed("left"))
	{
		if (m_movementComponent.speed == 0.f)
			m_movementComponent.speed = 3.f;
		if (m_movementComponent.speed < m_movementComponent.maxSpeed)
		{
			m_movementComponent.speed = m_movementComponent.speed * 1.004f;
		}
		m_movementComponent.direction.x = -1.f * m_movementComponent.speed;
		std::cout << m_movementComponent.direction.y << std::endl;
	}
	if (m_gm->inputManager.isPressed("right"))
	{
		if (m_movementComponent.speed == 0.f)
			m_movementComponent.speed = 3.f;
		if (m_movementComponent.speed < m_movementComponent.maxSpeed)
		{
			m_movementComponent.speed = m_movementComponent.speed * 1.004f;
		}
		m_movementComponent.direction.x = 1.f * m_movementComponent.speed;
		std::cout << m_movementComponent.speed << std::endl;
	}

	if (m_gm->inputManager.isPressed("left") && m_gm->inputManager.isPressed("right"))
	{
		m_movementComponent.direction.x = 0.f;
		m_movementComponent.speed = 0.f;
		m_movementComponent.jumpSpeed = 10.f;
	}
}
