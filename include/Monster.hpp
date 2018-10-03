#ifndef		__H__MONSTER__
#define		__H__MONSTER__

#include "SFML/Graphics.hpp"
#include <string>

class Monster {
	protected:
		int health;
		int x;
		int y;
		sf::Texture texture;
		sf::Sprite sprite;
		void move(int x, int y);
		int movement_speed;
		int attackPower;

	public:
		Monster();
		int getHealth();
		void harm(int amount);
		void updatePosition(int x, int y);
		sf::Sprite getSprite();
		int getDamage();
};

//Extension of Monster class
class Monster_A: public Monster {
	private:

	public:
		MonsterA();
};
#endif
