//
// Created by killeenj on 10/7/18.
//

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#ifndef CIS_343_02_BULLET_HPP
#define CIS_343_02_BULLET_HPP

class Bullet {
public :
    sf::CircleShape shape;
    sf::Vector2f curVelo;
    float maxSpeed;
    Bullet(float radius = 5.f);
private:


};
#endif //CIS_343_02_BULLET_HPP
