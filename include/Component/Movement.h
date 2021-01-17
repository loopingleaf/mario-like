#pragma once
#include "IComponent.h"
#include "SFML/System/Time.hpp"

// TODO : Ask pour la good habit du namespace
namespace Component
{

	class Movement : public IComponent
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
		Direction direction;
		bool isGrounded;

		Movement(Entity* ent, float maxSpeed, float speed, float acceleration, float jumpSpeed, float jumpMaxHeight, bool isSubjectToGravity, Direction direction, bool isGrounded);

		//void walk(Direction direction, sf::Time elapsed);

		void update(sf::Time deltaTime) override;
	};
	
}



