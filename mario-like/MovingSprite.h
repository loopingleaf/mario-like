#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

enum Direction {
	Right,
	Left
};

class MovingSprite : public sf::Sprite
{
public:
	float m_maxSpeed;
	float m_speed;
	float m_acceleration;
	float m_jumpSpeed;
	float m_jumpMaxHeight;
	bool m_isSubjectToGravity;

	void walk(Direction direction, sf::Time elapsed);

	/**
	 * strength is multiplied by jumpMaxHeight to give the effective jump height
	 * strength should be <= 1 and must be > 0
	 */
	void jump(float strength = 1.0f);

private:
	Direction m_direction;
	bool m_isGrounded;
};

