#ifndef		__H__COLLECTABLE
#define		__H__COLLECTABLE

#include "SFML/Graphics.hpp"
#include <string>
#include "Person.hpp"

class Collectable {
	private:
		sf::Texture texture;
		sf::Sprite sprite;
		bool active;
		void loadTexture(std::string path);


		void collectableEffect(Person* person);
		void setSprite();

	public:
		Collectable();
		sf::Sprite getSprite();
		void collect(Person* person);
		bool getActive();
};

#endif