#ifndef		__H__SANDWICH
#define		__H__SANDWICH

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include "Person.hpp"
#include "Collectable.hpp"

class Sandwich : public Collectable {
public:
    Sandwich(int startingX, int startingY);

protected:
    void collectableEffect(Person* person);
    void setSprite();
    void setSoundEffect();
};

#endif