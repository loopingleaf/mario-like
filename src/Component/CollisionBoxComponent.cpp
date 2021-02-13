#include <iostream>
#include "Component\CollisionBoxComponent.h"

std::vector<const CollisionBoxComponent*> CollisionBoxComponent::all;

CollisionBoxComponent::CollisionBoxComponent() : m_relativePosition(sf::Vector2f(0.f, 0.f)), Component()
{
	all.push_back(this);
}

CollisionBoxComponent::CollisionBoxComponent(Entity* entity, const sf::Vector2f& size, const sf::Vector2f& relativePosition)
	: m_relativePosition(relativePosition), Component(entity)
{
	m_rect = sf::Rect<float>(sf::Vector2f(entity->m_coordinates.x + relativePosition.x, entity->m_coordinates.y + relativePosition.y),
		sf::Vector2f(size.y, size.x));
#ifdef _DEBUG
	m_collisionShape = sf::RectangleShape(size);
	//m_collisionShape.setOrigin(m_rect.top, m_rect.left);
	m_collisionShape.setFillColor(sf::Color::Transparent);
	m_collisionShape.setOutlineThickness(1.f);
	m_collisionShape.setOutlineColor(sf::Color::Blue);
#endif // _DEBUG
	all.push_back(this);
}

bool CollisionBoxComponent::checkCollision(const CollisionBoxComponent& other)
{
	return m_rect.intersects(other.m_rect);
}

void CollisionBoxComponent::update(sf::Time deltaTime)
{
	m_rect.top = m_entity->m_coordinates.x + m_relativePosition.x;
	m_rect.left = m_entity->m_coordinates.y + m_relativePosition.y;
	for (const CollisionBoxComponent* cb : all)
	{
		if (this != cb && checkCollision(*cb))
			std::cout << "Intersects !" << std::endl;
	}
#ifdef _DEBUG
	m_collisionShape.setPosition(m_rect.top, m_rect.left);
	m_collisionShape.setSize(sf::Vector2f(m_rect.height, m_rect.width));
#endif // _DEBUG
}

void CollisionBoxComponent::draw()
{
#ifdef _DEBUG
	m_entity->m_gm->window->draw(m_collisionShape);
#endif // _DEBUG
}
