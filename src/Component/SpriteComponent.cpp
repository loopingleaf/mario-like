#include "Component\SpriteComponent.h"

SpriteComponent::SpriteComponent(sf::Texture& texture)
	: m_texture(texture)
{
	m_sprite.setTexture(texture);
}

void SpriteComponent::update(sf::Time deltaTime)
{

}

void SpriteComponent::draw(sf::Time& deltaTime)
{
	m_sprite.setPosition(sf::Vector2f(100.f, 100.f));
	m_sprite.setScale(5.f, 5.f);
	entity->m_gm->window->draw(m_sprite);
}
