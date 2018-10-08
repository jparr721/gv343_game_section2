#include "Monster.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>

Monster::Monster(){
	if (!spritesheet.loadFromFile("sprites/monster1sprites.png")){
		std::cerr << "Can't load sprite." << std::endl;
		exit(EXIT_FAILURE);
	}
	texture.loadFromImage(spritesheet, sf::IntRect(0,0,31,34));
	this->health = 10;
	this->movement_speed = 5;
	this->x = 100;
	this->y = 100;
	this->followPlayer = true;
	sprite.setTexture(texture);
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	currentFrame = 0;
	sprite.setOrigin(spriteSize.width/2.0,spriteSize.height/2.0);
	sprite.setPosition(100,100);
	refreshRate = 90;
}

int Monster::getHealth(){
	return health;
}

void Monster::harm(int amount){
	health = health - amount;
}

void Monster::updatePosition(int x, int y){
	move(x,y);
	sprite.setPosition(this->x, this->y);
}

sf::Sprite Monster::getSprite(){
	sprite.setTexture(texture);
	return this->sprite;
}

void Monster::move(int x, int y){
	if (clock.getElapsedTime().asMilliseconds() > refreshRate) {
		float dist = sqrt(
				(this->x - x) * (this->x - x) +
				(this->y - y) * (this->y - y)
				);
		float angle = atan2(y - this->y, x - this->x);
		int dx = int(this->movement_speed * cos(angle));
		int dy = int(this->movement_speed * sin(angle));
		if (dist <= 1000000) {
			if (this->x < x) {
				this->x += dx;
			} else if (this->x > x) {
				this->x += dx;
			}
			if (this->y < y) {
				this->y += dy;
			} else if (this->y > y) {
				this->y += dy;
			}
		}
		clock.restart();
		nextFrame();
	}
}

void Monster::nextFrame() {
	currentFrame++;
	currentFrame = currentFrame % 8;
	sf::Texture newFrame;
	newFrame.loadFromImage(spritesheet,
		sf::IntRect(currentFrame * 31, 0, (currentFrame + 1) * 31, 34));
	texture.update(newFrame);
}
