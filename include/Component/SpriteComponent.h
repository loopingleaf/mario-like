#pragma once
#include <memory>
#include "Component.h"
#include "SFML/Graphics.hpp"

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(sf::Texture& texture);
	~SpriteComponent() = default;

	void update(sf::Time deltaTime) override;
	void draw(sf::Time& deltaTime) override;

private:
	// TODO: Check if needs to be deleted / released
	sf::Texture& m_texture;
	sf::Sprite m_sprite;
};

