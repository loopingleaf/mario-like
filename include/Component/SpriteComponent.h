#pragma once
#include <memory>
#include "Component.h"
#include "SFML/Graphics.hpp"

class SpriteComponent : public Component
{
public:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	SpriteComponent() : m_texture(sf::Texture()), Component() {};
	SpriteComponent(std::string texturePath, Entity* entity);
	~SpriteComponent() = default;

	void update(sf::Time deltaTime) override;
	void draw() override;	
};

