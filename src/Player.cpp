#include <iostream>
#include "Player.h"
#include "Ground.h"
#include "Enemy.h"

const std::string Player::NAME = "player";

Player::Player(std::shared_ptr<GameManager> gameManager, sf::Vector2f coordinates)
	: Entity(gameManager, coordinates)
{
	m_movementComponent = MovementComponent(this, 20.f, 0.f, 0.f, 10.f, 0.f, 45.f, true, sf::Vector2f(0.f, 0.f), true);
	m_components.push_back(&m_movementComponent);
	std::string texturePath = "data/textures/player.png";
	m_sprite = new SpriteComponent(texturePath, this);
	m_components.push_back(m_sprite);
	sf::Vector2f spriteSize = (sf::Vector2f) m_sprite->m_sprite.getTexture()->getSize();
	sf::Vector2f scale = m_sprite->m_sprite.getScale();
	spriteSize.x *= scale.x;
	spriteSize.y *= scale.y;
	
	m_collisionFeet = new CollisionBoxComponent(this, spriteSize, "playerFeet");
	m_components.push_back(m_collisionFeet);
	// TEST CAMERA
	view.reset(sf::FloatRect(0, m_coordinates.y - 432, 1280, 720));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	m_gm->window->setView(view);
	m_gm->scoreText.setPosition(view.getCenter().x - 580, view.getCenter().y - 330);
}

Player::~Player()
{
	delete m_sprite;
	delete m_collisionFeet;
}

void Player::die()
{
	const auto iterator = std::find(m_gm->entities.begin(), m_gm->entities.end(), this);
	if (iterator != m_gm->entities.end())
	{
		m_gm->entities.erase(iterator);
	}
}


void Player::update(float dt)
{
	bool isCollidingGround = false;
	std::vector<const CollisionBoxComponent*> retval;
	for (const CollisionBoxComponent* cb : CollisionBoxComponent::all)
	{
		if (cb == m_collisionFeet || cb->m_entity == this)
			continue;

		if (m_collisionFeet->checkCollision(*cb))
		{
			if (cb->m_tag == "ground")
			{
				m_movementComponent.isGrounded = true;
				isCollidingGround = true;
				
				// Not that clean, but that's all I can code for now.
				Ground* collidingGround = static_cast<Ground*>(cb->m_entity);
				m_coordinates.y = collidingGround->m_coordinates.y - (static_cast<float>(collidingGround->m_sprite->m_texture.getSize().y) * collidingGround->m_sprite->m_sprite.getScale().y) / 2.f
					- (static_cast<float>(m_sprite->m_texture.getSize().y) * m_sprite->m_sprite.getScale().y) / 4.f + 2.f;
			}
			else if (cb->m_tag == "hit")
			{
				Enemy* enemy = static_cast<Enemy*>(cb->m_entity);
				enemy->die();
			}
			/*else if(cb->m_tag == "damage")
			{
				die();
			}*/
		}
	}
	/*if (!isCollidingGround)
	{
		m_movementComponent.isGrounded = false;
	}*/

	if (m_movementComponent.isGrounded)
	{
		m_movementComponent.direction.y = 0;
	}

	if (!m_movementComponent.isGrounded)
	{
		if (m_movementComponent.jumpSpeed < 12.f)
		{
			m_movementComponent.jumpSpeed *= 1.004f;
		}
		m_movementComponent.direction.y = 10.f * m_movementComponent.jumpSpeed;
	}
	
	if (!m_gm->inputManager.isPressed("left") && !m_gm->inputManager.isPressed("right"))
	{
		m_movementComponent.direction.x = 0.f;
		m_movementComponent.speed = 0.f;
	}

	if ((!m_gm->inputManager.isPressed("jump") && m_movementComponent.jumpHeight > 0.f) || m_movementComponent.jumpHeight >= m_movementComponent.jumpMaxHeight)
	{
		m_movementComponent.jumpHeight -= 130.f * dt;
		if (m_movementComponent.jumpSpeed < 12.f)
		{
			m_movementComponent.jumpSpeed *= 1.004f;
		}
		m_movementComponent.direction.y = 10.f * m_movementComponent.jumpSpeed;
		m_movementComponent.isGrounded = false;
	}

	if (m_gm->inputManager.isPressed(("jump")) && m_movementComponent.isGrounded && m_movementComponent.jumpHeight < m_movementComponent.jumpMaxHeight)
	{
		m_movementComponent.jumpHeight += 130.f * dt;
		if (m_movementComponent.jumpSpeed < 12.f)
		{
			m_movementComponent.jumpSpeed *= 0.997f;
		}
		m_movementComponent.direction.y = -10.f * m_movementComponent.jumpSpeed;
	}
	
	if(m_gm->inputManager.isPressed("left"))
	{
		if (m_movementComponent.speed == 0.f)
			m_movementComponent.speed = 3.f;
		if (m_movementComponent.speed < m_movementComponent.maxSpeed)
		{
			m_movementComponent.speed += 70.f * dt;
		}
		m_movementComponent.direction.x = -1.f * m_movementComponent.speed;
		//std::cout << m_movementComponent.direction.y << std::endl;
		if (m_coordinates.x < view.getCenter().x - 400)
		{
			view.setCenter(m_coordinates.x + 400, view.getCenter().y);
			m_gm->scoreText.setPosition(view.getCenter().x - 580, view.getCenter().y - 330);
			m_gm->background.setPosition(m_gm->background.getPosition().x - 3 * m_movementComponent.speed / m_movementComponent.maxSpeed, m_gm->background.getPosition().y);
			m_gm->window->setView(view);
		}
	}
	if (m_gm->inputManager.isPressed("right"))
	{
		if (m_movementComponent.speed == 0.f)
			m_movementComponent.speed = 3.f;
		if (m_movementComponent.speed < m_movementComponent.maxSpeed)
		{
			m_movementComponent.speed += 70.f * dt;
		}
		m_movementComponent.direction.x = 1.f * m_movementComponent.speed;
		//std::cout << m_movementComponent.speed << std::endl;
		//TEST CAMERA
		if (m_coordinates.x > view.getCenter().x - 100)
		{
			view.setCenter(m_coordinates.x + 100, view.getCenter().y);
			m_gm->scoreText.setPosition(view.getCenter().x - 580, view.getCenter().y - 330);
			m_gm->background.setPosition(m_gm->background.getPosition().x + 3 * m_movementComponent.speed / m_movementComponent.maxSpeed, m_gm->background.getPosition().y);
			m_gm->window->setView(view);
		}
	}

	if (m_gm->inputManager.isPressed("left") && m_gm->inputManager.isPressed("right"))
	{
		m_movementComponent.direction.x = 0.f;
		m_movementComponent.speed = 0.f;
		m_movementComponent.jumpSpeed = 10.f;
	}
}

std::string Player::getName()
{
	return NAME;
}
