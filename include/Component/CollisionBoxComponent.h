#pragma once
#include <SFML/System.hpp>
#include "Component.h"

class CollisionBoxComponent : public Component
{
public:
	static std::vector<const CollisionBoxComponent*> all;
	sf::Vector2f m_relativePosition = sf::Vector2f(0.f, 0.f);
	sf::Rect<float> m_rect;
#ifdef _DEBUG
	sf::RectangleShape m_collisionShape;
#endif // _DEBUG
	CollisionBoxComponent();
	CollisionBoxComponent(Entity* entity, const sf::Vector2f& size, const sf::Vector2f& relativePosition = sf::Vector2f(0.f, 0.f));

	bool checkCollision(const CollisionBoxComponent& other);

	void update(float dt) override;
	void draw() override;
};

