#pragma once
#include <SFML/System.hpp>
#include "Component.h"

class CollisionBoxComponent : public Component
{
public:
	static std::vector<const CollisionBoxComponent*> all;
	sf::Vector2f m_relativePosition = sf::Vector2f(0.f, 0.f);
	sf::Rect<float> m_rect;
	std::string m_tag;
#ifdef _DEBUG
	/* Outline of the collision box */
	sf::RectangleShape m_collisionShape;
#endif // _DEBUG

	CollisionBoxComponent();
	CollisionBoxComponent(Entity* entity, const sf::Vector2f& size, const std::string& tag = "", const sf::Vector2f& relativePosition = sf::Vector2f(0.f, 0.f));

	/**
	 * \brief Check the collision (intersection) with another CollisionBoxComponent.
	 * 
	 * \param other The other CollisionBoxComponent to check.
	 * \return True if the two collision boxes collides, false otherwise.
	 */
	bool checkCollision(const CollisionBoxComponent& other) const;

	/**
	 * \brief Returns the list of colliding CollisionBoxComponent.
	 * 
	 * \param excludeSelf Whether or not it return the other collision boxes attached to m_entity.
	 * \return The collidings CollisionBoxComponent.
	 */
	std::vector<const CollisionBoxComponent*> collisionList(bool excludeSelf = true);

	void update(float dt) override;
#ifdef _DEBUG
	void draw() override;
#endif // _DEBUG
};
