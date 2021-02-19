#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	std::shared_ptr<GameManager> gm = std::make_shared<GameManager>();
	Entity* player = new Player(gm, sf::Vector2f(0.f, 0.f));
	gm->start(gm);
	sf::View view;
}
