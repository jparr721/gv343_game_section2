#ifndef		__H__COIN
#define		__H__COIN

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include "Person.hpp"
#include "Collectable.hpp"

class Coin : public Collectable {
public:
    Coin(int startingX, int startingY);

protected:
    int collectableEffect(Person* person);
    void setSprite();
    void setSoundEffect();
};

#endif