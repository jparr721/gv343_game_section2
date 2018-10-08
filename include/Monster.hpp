#ifndef		__H__MONSTER__
#define		__H__MONSTER__

#include "SFML/Graphics.hpp"
#include <string>
class Monster {
	protected:
		/**
		The monster's current health.
		*/
		int health;
		/**
		The monster's current x position.
		*/
		int x;
		/**
		The monster's current y position.
		*/
		int y;
		/**
		The spritesheet that the sprite
		is made from.
		*/
		sf::Image spritesheet;
		/**
		The sprite's current image.
		*/
		sf::Texture texture;
		/**
		The monster's sprite.
		*/
		sf::Sprite sprite;
		/**
		A function to move the monster towards (x,y).
		*/
		void move(int x, int y);
		/**
		A function to help animate the sprite and change the
		sprite to the next frame in the spritesheet.
		*/
		void nextFrame();
		/**
		How many pixels the monster moves per update.
		*/
		int movement_speed;
		/**
		How much damage the monster deals.
		*/
		int attackPower;
		/**
		If the monster is following the player.
		*/
		bool followPlayer;
		/**
		The clock that determines when the
		monster updates position
		*/
		sf::Clock clock;
		/**
		How long it takes before an update in
		position occurs.
		*/
		float refreshRate;
		/**
		The current frame in the spritesheet.
		*/
		int currentFrame;
	public:
		/**
		Constructor that initializes all variables.
		*/
		Monster();
		/**
		Returns current health.
		*/
		int getHealth();
		/**
		Removes amount from health.
		*/
		void harm(int amount);
		/**
		Moves the monster towards (x,y).
		*/
		void updatePosition(int x, int y);
		/**
		Returns the monster's sprite.
		*/
		sf::Sprite getSprite();
		/**
		Returns how much damage the monster deals.
		*/
		int getDamage();
};

//Extension of Monster class
class Orc: public Monster {
	private:

	public:
		/**
		Constructor sets sprite to Orc sprites.
		*/
		Orc();
};
#endif
