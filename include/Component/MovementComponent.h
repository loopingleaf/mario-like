#pragma once
#include "Component.h"
#include "SFML/System/Time.hpp"

class MovementComponent : public Component
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
	float jumpHeight;
	float jumpMaxHeight;
	bool isSubjectToGravity;
	sf::Vector2f direction;
	bool isGrounded;

	MovementComponent() = default;
	MovementComponent(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, float jumpHeight, float jumpMaxHeight,
		bool isSubjectToGravity, sf::Vector2f direction, bool isGrounded);

	//void walk(Direction direction, sf::Time elapsed);

	void update(float dt) override;
};
