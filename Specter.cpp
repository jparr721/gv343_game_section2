#include "SFML/Graphics.hpp"
#include <math.h>
#include "Monster.hpp"
#include <iostream>

Specter::Specter() {
	if (!spritesheet.loadFromFile("sprites/monster2sprites.png")) {
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}
	texture.loadFromImage(spritesheet, sf::IntRect(0,0,31,34));
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(120, 0, 250, 180));
	this->health = 5;
	this->movement_speed = 7;
}
