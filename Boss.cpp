#include "SFML/Graphics.hpp"
#include <math.h>
#include "Monster.hpp"
#include <iostream>

Boss::Boss() {
	if (!spritesheet.loadFromFile("sprites/monster1sprites.png")) {
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}
	texture.loadFromImage(spritesheet, sf::IntRect(0,0,31,34));
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 130, 0, 255));
	this->health = 50;
	this->movement_speed = 2;
}
