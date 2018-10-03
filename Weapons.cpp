#include "Weapons.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include <iostream>

void Weapons::initalize(){
    range = 0;
    damage = 0;
    equipped = false;
}

void Weapons::setRange(int range){
    this->range = range;
}

void Weapons::setDamage(int damage){
    this->damage = damage;
}

void Weapons::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

sf::Sprite Weapons::getSprite(){
    return Weapons::sprite;
}
