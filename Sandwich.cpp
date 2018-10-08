//
// Created by TB on 10/7/2018.
//

#include "Sandwich.hpp"

// constructor
Sandwich::Sandwich(int startingX, int startingY) : Collectable(startingX, startingY) {
    this->setSprite();
}

void Sandwich::setSprite() {
    this->loadTexture(
        "sprites/0x72_DungeonTilesetII_v1.png",
        sf::IntRect(289, 225, 18, 18)
    );
}

void Sandwich::setSoundEffect() {
    this->loadSoundEffect("sounds/bite.wav");
}

int Sandwich::collectableEffect(Person *person) {
    int newHealth = person->getHealth() + 20;
    person->setHealth(newHealth);
    return 0;
}

void Sandwich::animate() {

}