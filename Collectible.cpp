#include "Collectible.hpp"
#include "Person.hpp"

#include "SFML/Graphics.hpp"
#include <iostream>

Collectible::Collectible() {
	if (!texture.loadFromFile("sprites/0x72_DungeonTilesetII_v1.png")){
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}


  sprite.setTexture(texture);
  // sprite.setTextureRect(sf::IntRect(289,273,9,9));
  sprite.setTextureRect(sf::IntRect(298,273,9,9));
  sprite.setPosition(300, 300);

	active = true;
}

sf::Sprite Collectible::getSprite(){
	sprite.setTexture(texture);
	return this->sprite;
}

void Collectible::processCollectible(Person* person) {
	int newHealth = person->getHealth() + 20;
	person->setHealth(newHealth);
	active = false;
}

bool Collectible::getActive() {
	return active;
}