#pragma once
#include <memory>
#include "Component.h"
#include "SFML/Graphics.hpp"

class SpriteComponent : public Component
{
public:
	SpriteComponent() : m_texture(sf::Texture()), Component() {};
	SpriteComponent(std::string texturePath, Entity* entity);
	~SpriteComponent() = default;

	void update(sf::Time deltaTime) override;
	void draw() override;

private:
	// TODO: Check if needs to be deleted / released
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

