#include "Person.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include <iostream>

Person::Person(){
	if(!left1.loadFromFile("sprites/personL1.png")){
		exit(EXIT_FAILURE);
	}
	if(!right1.loadFromFile("sprites/personR1.png")){
		exit(EXIT_FAILURE);
	}

	if(!left2.loadFromFile("sprites/personL2.png")){
		exit(EXIT_FAILURE);
	}
	if(!right2.loadFromFile("sprites/personR2.png")){
		exit(EXIT_FAILURE);
	}
	sprite.setTexture(right1);
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
	if(!punchBuffer.loadFromFile("sounds/punch.wav")){
		std::cerr << "Can't load punch sound." << std::endl;
	}
	punch.setBuffer(punchBuffer);
	initialize();
}

void Person::initialize(){
	x = WIDTH / 2;
	y = HEIGHT / 2;
	health = STARTING_HEALTH;
	sprite.setPosition(x, y);
	speed = 1;
	direction = 0;
	state = 1;
	//clock.restart();
}

sf::Sprite Person::getSprite(){
	return this->sprite;
}

int Person::getHealth(){
	return this->health;
}

void Person::setHealth(int health){
	this->health = health;
}

/****************************************************************
 * updateSprite uses the clock function as well as the direction
 * of the sprite passed to it via a parameter to decide on the 
 * sprite's appearance.
 * @param d Direction the sprite is facing (0 if left, 1 if right)
 * **************************************************************/

void Person::updateSprite(int d){

	/* Instantiates clock*/
	sf::Time time = clock.getElapsedTime();
	sf::Int32 mills = time.asMilliseconds();

	/* Check for idle state*/
	if (mills % 1000 > 500)
		state = 2;
	 else
		state = 1;

	/* Assigns sprite the right texture on state and direction*/
	if(d == 0){ 
		if(state == 1){
			sprite.setTexture(left2);
		}
		else if(state == 2){
			sprite.setTexture(left1);
		}
	}
	if(d==1){
		if(state == 1){
			sprite.setTexture(right2);
		}
		else if(state == 2){
			sprite.setTexture(right1);
		}
	}
}

void Person::updatePosition(int dx, int dy){
	if( (x+dx) > 0 && (x+dx) < WIDTH ){
		x = x + (dx * speed);
	}
	if ( (y+dy) > 0 && (y+dy) < HEIGHT ){
		y = y + (dy * speed);
	}
	
	/* If facing right, set direction to 1, or right.*/
	if(dx > 0){
		direction = 1;
	}

	/* If facing left, set direction to 0, or left*/
	if(dx < 0){
		direction = 0;
	}
	/* Calls updateSprite to change appearance*/
	updateSprite(direction);
	sprite.setPosition(x,y);
}

void Person::harm(int hp){
	health = health - hp;
	punch.play();
}

/*****************************************************
 * Assigns speed based on parameter
 * @param s New value for speed
 * **************************************************/
void Person::setSpeed(float s){
	this->speed = s;
}

/*****************************************************
 * Returns speed
 * @return this->speed
 * **************************************************/
float Person::getSpeed(){
	return this->speed;
}



