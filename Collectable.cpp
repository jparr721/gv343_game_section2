#include "Collectable.hpp"
#include "Person.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

Collectable::Collectable(int startingX, int startingY)
{
    active = true;
    lastMillisecondAnimated = 0;
    sprite.setPosition(startingX, startingY);
}

// loadTexture - helper function that takes a file path and
// loads that texture into the instances `sprite` variable
void Collectable::loadTexture(std::string path, sf::IntRect rect)
{
    if (!texture.loadFromFile(path))
    {
        std::cerr << "Can't load sprite." << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
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

int Collectable::collect(Person *person)
{
    this->setSoundEffect();
    soundEffect.play();
    active = false;
    return this->collectableEffect(person);
}

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

void Collectable::reset()
{
    active = true;
}
