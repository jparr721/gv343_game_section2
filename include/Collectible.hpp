#ifndef		__H__COLLECTIBLE
#define		__H__COLLECTIBLE

#include "SFML/Graphics.hpp"
#include <string>

class Collectible {
	private:
		sf::Texture texture;
		sf::Sprite sprite;

	public:
		Collectible();
		sf::Sprite getSprite();
};

#endif