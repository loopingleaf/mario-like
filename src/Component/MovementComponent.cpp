#include "Component/MovementComponent.h"

MovementComponent::MovementComponent(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, float jumpHeight,
	float jumpMaxHeight, bool isSubjectToGravity, sf::Vector2f direction, bool isGrounded)
{
	m_entity = ent;
	this->maxSpeed = maxSpeed;
	this->speed = speed;
	this->acceleration = acceleration;
	this->jumpSpeed = jumpSpeed;
	this->jumpHeight = jumpHeight;
	this->jumpMaxHeight = jumpMaxHeight;
	this->isSubjectToGravity = isSubjectToGravity;
	this->direction = direction;
	this->isGrounded = isGrounded;
}

void MovementComponent::update(sf::Time deltaTime)
{
	//TODO Saut, gravité...
	/*if(speed > 0.0001f && jumpSpeed > 0.0001f)
	{*/
		float shiftX = speed * deltaTime.asSeconds();
		m_entity->m_coordinates.x += direction.x * shiftX;
		float shiftY = jumpSpeed * deltaTime.asSeconds();
		m_entity->m_coordinates.y += direction.y * shiftY;
	//}
}
