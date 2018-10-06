#include "Collectable.hpp"
#include "Person.hpp"

#include "SFML/Graphics.hpp"

Collectable::Collectable(int startingX, int startingY)
{
    active = true;
    lastMillisecondAnimated = 0;
    this->setSprite();
    sprite.setPosition(startingX, startingY);

    this->setSoundEffect();
}

// loadTexture - helper function that takes a file path and
// loads that texture into the instances `sprite` variable
void Collectable::loadTexture(std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Can't load sprite." << std::endl;
        exit(EXIT_FAILURE);
    }

    sprite.setTexture(texture);
}

void Collectable::loadSoundEffect(std::string path)
{
    if (!soundBuffer.loadFromFile(path))
    {
        std::cerr << "Can't load sound effect" << std::endl;
    }

    soundEffect.setBuffer(soundBuffer);
}

// Called by the game engine to get the sprite of the
// collectable
sf::Sprite Collectable::getSprite()
{
    sprite.setTexture(texture);
    return this->sprite;
}

void Collectable::collect(Person *person)
{
    this->collectableEffect(person);
    soundEffect.play();
    printf("Should be called\n");
    active = false;
}

// bool Collectable::shouldAnimate() {
// }

void Collectable::tick()
{

    int currentTimeInMils = clock.getElapsedTime().asMilliseconds();
    if (currentTimeInMils - lastMillisecondAnimated >= 16)
    {
        this->animate();
        lastMillisecondAnimated = currentTimeInMils;
    }
}

bool Collectable::getActive()
{
    return active;
}

/*
 * OVERRIDABLE FUNCTIONS
 */

// Override to set the collectable's sprite path
// and dimensions
void Collectable::setSprite()
{
    this->loadTexture("sprites/0x72_DungeonTilesetII_v1.png");

    // sprite.setTextureRect(sf::IntRect(289,273,9,9));
    sprite.setTextureRect(sf::IntRect(298, 273, 9, 9));
}

void Collectable::setSoundEffect()
{
    this->loadSoundEffect("sounds/punch.wav");
}

//
void Collectable::collectableEffect(Person *person)
{
    int newHealth = person->getHealth() + 20;
    person->setHealth(newHealth);
}

// void

// Override to provide animation to the collectable,
// the tick method above will call this method every ~16ms
void Collectable::animate() {}