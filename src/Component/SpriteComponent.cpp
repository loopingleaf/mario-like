#include <iostream>
#include "Component\SpriteComponent.h"

SpriteComponent::SpriteComponent(std::string texturePath, Entity* entity)
	: Component(entity)
{
	m_texture = sf::Texture();
	m_texture.loadFromFile(texturePath);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(100.f, 100.f));
	m_sprite.setScale(5.f, 5.f);
}

void SpriteComponent::update(sf::Time deltaTime)
{
	m_sprite.setPosition(m_entity->m_coordinates);
}

void SpriteComponent::draw()
{
	m_entity->m_gm->window->draw(m_sprite);
}
