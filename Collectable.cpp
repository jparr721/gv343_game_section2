#include "Collectable.hpp"
#include "Person.hpp"

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// Constructor - Pass in starting x and y coordinates for
// the collectable
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

// loadSoundEffect - method that takes a file path and
// loads the desired sound effect, which is played,
// once the collectable is collected
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

// collect - a method that takes a person
// (the player) in the moment that he collects
// a collectable
int Collectable::collect(Person *person)
{
    this->setSoundEffect();
    soundEffect.play();
    active = false;
    return this->collectableEffect(person);
}

// tick - a method that balances the animation
// of the collectable with the flow of time
void Collectable::tick()
{

    int currentTimeInMils = clock.getElapsedTime().asMilliseconds();
    if (currentTimeInMils - lastMillisecondAnimated >= 16)
    {
        this->animate();
        lastMillisecondAnimated = currentTimeInMils;
    }
}

// getActive - a method that only returns a bool,
// true if the collectable has been caught,
// otherwise, return false
bool Collectable::getActive()
{
    return active;
}

void Collectable::reset()
{
    active = true;
}
