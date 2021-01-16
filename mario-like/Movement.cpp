#include "Movement.h"
using namespace Component;

Movement::Movement(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, 
	float jumpMaxHeight, bool isSubjectToGravity, Direction direction, bool isGrounded)
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

void Movement::update(sf::Time deltaTime)
{
	//TODO Saut, gravité...
	if(speed != 0.f )
	{
		float shift = speed * deltaTime.asMicroseconds();
		entity->coordinates[0] += direction * shift;
	}
}

