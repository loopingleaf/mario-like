#include "Component/MovementComponent.h"

MovementComponent::MovementComponent(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, 
	float jumpMaxHeight, bool isSubjectToGravity, sf::Vector2f direction, bool isGrounded)
{
	entity = ent;
	this->maxSpeed = maxSpeed;
	this->speed = speed;
	this->acceleration = acceleration;
	this->jumpSpeed = jumpSpeed;
	this->jumpMaxHeight = jumpMaxHeight;
	this->isSubjectToGravity = isSubjectToGravity;
	this->direction = direction;
	this->isGrounded = isGrounded;
}

void MovementComponent::update(sf::Time deltaTime)
{
	//TODO Saut, gravité...
	if(speed > 0.0001f )
	{
		float shift = speed * deltaTime.asMicroseconds();
		entity->coordinates[0] = direction.x * shift;
		entity->coordinates[1] = direction.y * shift;
	}
}

