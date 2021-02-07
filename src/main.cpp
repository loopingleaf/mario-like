#include "SFML/Graphics.hpp"
#include "GameManager.h"
#include "Player.h"
#include <iostream>

int main()
{
	std::shared_ptr<GameManager> gm = std::make_shared<GameManager>();
	Entity* player = new Player(gm, sf::Vector2f(20.f, 32.f));
	gm->start();
}
