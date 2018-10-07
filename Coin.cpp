//
// Created by TB on 10/7/2018.
//

#include "Coin.hpp"

Coin::Coin(int startingX, int startingY) : Collectable(startingX, startingY) {
    this->setSprite();
}

void Coin::setSprite() {
    this->loadTexture("sprites/0x72_DungeonTilesetII_v1.png", sf::IntRect(298, 273, 9, 9));
}

void Coin::setSoundEffect() {
    this->loadSoundEffect("sounds/coin-get.wav");
}

int Coin::collectableEffect(Person *person) {
    return 1;
}