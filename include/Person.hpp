#ifndef		__H_PERSON__
#define		__H_PERSON__

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Person {
	public:
		Person();
		void initialize();
		int getHealth();
		void setHealth(int health);
		sf::Sprite getSprite();
		void harm(int hp);
		void updatePosition(int x, int y);
		void setSpeed(float s);
		float getSpeed();
		void updateSprite(int d);	
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Texture left1;
		sf::Texture right1;
		sf::Texture left2;
		sf::Texture right2;
		int state;
		int direction;
		int x;
		int y;
		int health;
		float speed;
		sf::SoundBuffer punchBuffer;
		sf::Sound punch;
		sf::Clock clock;
};

#endif
