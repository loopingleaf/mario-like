#include "MovingSprite.h"

void MovingSprite::walk(Direction direction, sf::Time elapsed)
{
	if (m_direction != direction)
	{
		m_direction = direction;
		m_speed = 0.f;
	}
	if (m_speed >= m_maxSpeed)
	{
		m_speed = m_maxSpeed;
		return;
	}

	m_speed += m_acceleration * elapsed.asMilliseconds;
}

void MovingSprite::jump(float strength)
{
	if (!m_isGrounded)
	{
		return;
	}

	// TODO
}
