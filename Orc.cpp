#include "SFML/Graphics.hpp"
#include <math.h>

Orc::Orc() {
	if (!texture.loadFromFile("sprites/monster_two.png")) {
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(texture);
	this->health = 25;
	this->movement_speed = 3;
}
