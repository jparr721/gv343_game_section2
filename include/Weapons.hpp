//
// Created by killeenj on 10/7/18.
//
#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Person.hpp"
#include <string>


#ifndef CIS_343_02_WEAPONS_HPP
#define CIS_343_02_WEAPONS_HPP

class Weapons{
public:
    Weapons();
    void initalize();
    int getRange();
    void setRange(int range);
    void setDamage(int damage);
    int getDamage();
    void setPosition(int dx, int dy);
    sf::Sprite getSprite();
    void setWeapon(int range, int damage, sf::Sprite sprite,bool equipped);
    void damageMonster(std::vector<Monster> &monsters, int damage);
    int getX();
    int getY();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    int range;
    int damage;
    int x;
    int y;
    sf::Clock clock;
    bool equipped;
};
#endif //CIS_343_02_WEAPONS_HPP
