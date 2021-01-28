#pragma once
#include "IComponent.h"
#include "SFML/System/Time.hpp"

class MovementComponent : public IComponent
{
public:
	enum Direction {
		Right = 1,
		Left = -1
	};

	float maxSpeed;
	float speed;
	float acceleration;
	float jumpSpeed;
	float jumpMaxHeight;
	bool isSubjectToGravity;
	sf::Vector2f direction;
	bool isGrounded;

	MovementComponent(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, float jumpMaxHeight,
		bool isSubjectToGravity, sf::Vector2f direction, bool isGrounded);

	//void walk(Direction direction, sf::Time elapsed);

	void update(sf::Time deltaTime) override;
};
