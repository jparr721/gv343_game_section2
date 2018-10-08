//
// Created by TB on 10/7/2018.
//

#include "Coin.hpp"

Coin::Coin(int startingX, int startingY) : Collectable(startingX, startingY) {
    this->setSprite();
}

void Coin::setSprite() {
    this->loadTexture(
        "sprites/0x72_DungeonTilesetII_v1.png",
        sf::IntRect(298, 273, 9, 9)
    );
}

void Coin::setSoundEffect() {
    this->loadSoundEffect("sounds/coin-get.wav");
}

int Coin::collectableEffect(Person *person) {
    return 1;
}

void Coin::animate() {

    // Rate of animation, the higher the slower the
    // coin will spin, the lower the faster.
    int rate = 8;

    // Four states of the coin animation
    switch ((animationCallCount % (3 * rate) ) / rate)
    {
        case 0:
            sprite.setTextureRect(sf::IntRect(289, 273, 6, 7));
            break;
        case 1:
            sprite.setTextureRect(sf::IntRect(297, 273, 6, 7));
            break;
        case 2:
            sprite.setTextureRect(sf::IntRect(305, 273, 6, 7));
            break;
        case 3:
            sprite.setTextureRect(sf::IntRect(313, 273, 6, 7));
            break;

    }
    animationCallCount++;
}