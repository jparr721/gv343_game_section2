#include "Collectable.hpp"
#include "Person.hpp"

#include "SFML/Graphics.hpp"
#include <iostream>

Collectable::Collectable() {
	active = true;
	this->setSprite();
}

// loadTexture - helper function that takes a file path and 
// loads that texture into the instances `sprite` variable
void Collectable::loadTexture(std::string path) {
	if (!texture.loadFromFile(path)){
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}

  sprite.setTexture(texture);
}

// Called by the game engine to get the sprite of the
// collectable
sf::Sprite Collectable::getSprite(){
	sprite.setTexture(texture);
	return this->sprite;
}

void Collectable::collect(Person* person) {
	this->collectableEffect(person);
	active = false;
}

bool Collectable::getActive() {
	return active;
}

// void Collectable::animate(int milliseconds) {

// }

/*
 * OVERRIDABLE FUNCTIONS
 */


// Override to set the collectable's sprite path
// and dimensions
void Collectable::setSprite() {
	this->loadTexture("sprites/0x72_DungeonTilesetII_v1.png");

  // sprite.setTextureRect(sf::IntRect(289,273,9,9));
  sprite.setTextureRect(sf::IntRect(298,273,9,9));
  sprite.setPosition(300, 300);
}

//
void Collectable::collectableEffect(Person* person) {
	int newHealth = person->getHealth() + 20;
	person->setHealth(newHealth);
}