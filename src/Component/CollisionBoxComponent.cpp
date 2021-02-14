#include <iostream>
#include "Component\CollisionBoxComponent.h"

std::vector<const CollisionBoxComponent*> CollisionBoxComponent::all;

CollisionBoxComponent::CollisionBoxComponent() : m_relativePosition(sf::Vector2f(0.f, 0.f)), Component()
{
	all.push_back(this);
}

CollisionBoxComponent::CollisionBoxComponent(Entity* entity, const sf::Vector2f& size, const std::string& tag, const sf::Vector2f& relativePosition)
	: Component(entity), m_relativePosition(relativePosition), m_tag(tag)
{
	m_rect = sf::Rect<float>(sf::Vector2f(entity->m_coordinates.x + relativePosition.x, entity->m_coordinates.y + relativePosition.y),
		sf::Vector2f(size.y, size.x));
#ifdef _DEBUG
	m_collisionShape = sf::RectangleShape(size);
	m_collisionShape.setFillColor(sf::Color::Transparent);
	m_collisionShape.setOutlineThickness(1.f);
	m_collisionShape.setOutlineColor(sf::Color::Blue);
#endif // _DEBUG
	all.push_back(this);
}

bool CollisionBoxComponent::checkCollision(const CollisionBoxComponent& other) const
{
	return m_rect.intersects(other.m_rect);
}

std::vector<const CollisionBoxComponent*> CollisionBoxComponent::collisionList(bool excludeSelf)
{
	std::vector<const CollisionBoxComponent*> retval;
	for (const CollisionBoxComponent* cb : CollisionBoxComponent::all)
	{
		if (cb == this || (excludeSelf && cb->m_entity == m_entity))
			continue;

		if (checkCollision(*cb))
		{
			retval.push_back(cb);
		}
	}
	return retval;
}

void CollisionBoxComponent::update(float dt)
{
	m_rect.top = m_entity->m_coordinates.x + m_relativePosition.x;
	m_rect.left = m_entity->m_coordinates.y + m_relativePosition.y;
#ifdef _DEBUG
	m_collisionShape.setPosition(m_rect.top, m_rect.left);
	m_collisionShape.setSize(sf::Vector2f(m_rect.height, m_rect.width));
#endif // _DEBUG
}

#ifdef _DEBUG
void CollisionBoxComponent::draw()
{
	m_entity->m_gm->window->draw(m_collisionShape);
}
#endif // _DEBUG
