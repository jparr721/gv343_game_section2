#ifndef		__H__COLLECTABLE
#define		__H__COLLECTABLE

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include "Person.hpp"

class Collectable {
	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Clock clock;
		int lastMillisecondAnimated;
		bool active;
		sf::SoundBuffer soundBuffer;
		sf::Sound soundEffect;

		void loadTexture(std::string path);
		void loadSoundEffect(std::string path);
		bool shouldAnimate();
		void animate();

		void collectableEffect(Person* person);
		void setSprite();
		void setSoundEffect();

	public:
		Collectable(int startingX, int startingY);
		void tick();
		sf::Sprite getSprite();
		void collect(Person* person);
		bool getActive();
};

#endif