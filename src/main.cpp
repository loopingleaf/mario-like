#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameManager.h"
#include "Player.h"
#include "Ground.h"

int main()
{
	std::shared_ptr<GameManager> gm = std::make_shared<GameManager>();
	Entity* player = new Player(gm, sf::Vector2f(260.f, 432.f));
	Entity* ground = new Ground(gm, sf::Vector2f(24.f, 490.f), "data/textures/player.png");

	gm->start();
	sf::View view;

}
