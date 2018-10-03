#ifndef		__H__COLLECTIBLE
#define		__H__COLLECTIBLE

#include "SFML/Graphics.hpp"
#include <string>
#include "Person.hpp"

class Collectible {
	private:
		sf::Texture texture;
		sf::Sprite sprite;
		bool active;

	public:
		Collectible();
		sf::Sprite getSprite();
		void processCollectible(Person* person);
		bool getActive();
};

#endif