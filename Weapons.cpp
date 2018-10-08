#include "Weapons.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include <iostream>

Weapons::Weapons(){
    if(!texture.loadFromFile("sprites/ak.png")){
        std::cerr << "Can't load sprite." << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture);
    sf::FloatRect spriteSize = sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.0,spriteSize.height/2.0);
    sprite.setPosition(WIDTH/2,(HEIGHT/2)-20);
}

void Weapons::initalize(){
    range = 0;
    damage = 10;
    equipped = false;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    sprite.setPosition(x, y);
}
void Weapons::setWeapon(int range, int damage, sf::Sprite sprite,bool equipped){
    this->range = range;
    this->damage = damage;
    this->sprite = sprite;
    this->equipped = equipped;
}

void Weapons::setRange(int range){
    this->range = range;
}

int Weapons::getRange(){
    return range;
}

void Weapons::setDamage(int damage){
    this->damage = damage;
}

int Weapons::getDamage(){
    return damage;
}
int Weapons::getX(){
    return this-> x;
}
int Weapons::getY(){
    return this->y;
}
void Weapons::setPosition(int dx, int dy){
    if( (x+dx) > 0 && (x+dx) < WIDTH ){
        x = x + dx;
    }
    if ( (y+dy) > 0 && (y+dy) < HEIGHT ){
        y = y + dy;
    }
    sprite.setPosition(x,y);
}

void Weapons::damageMonster(std::vector<Monster> &monsters, int damage){
    std::cout << monsters[0].getHealth() << std::endl;
    monsters[0].harm(damage);
    std::cout << monsters[0].getHealth() << std::endl;
}

sf::Sprite Weapons::getSprite(){
    sprite.setTexture(texture);
    return this->sprite;
}
