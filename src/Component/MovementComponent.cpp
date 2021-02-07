#include "Component/MovementComponent.h"

MovementComponent::MovementComponent(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, 
	float jumpMaxHeight, bool isSubjectToGravity, sf::Vector2f direction, bool isGrounded)
{
	m_entity = ent;
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
		m_entity->m_coordinates.x = direction.x * shift;
		m_entity->m_coordinates.y = direction.y * shift;
	}
}
