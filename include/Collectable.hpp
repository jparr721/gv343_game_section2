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
		sf::SoundBuffer soundBuffer;

    protected:
        sf::Sound soundEffect;
        bool active;
		void loadTexture(std::string path, sf::IntRect rect);
		void loadSoundEffect(std::string path);
		bool shouldAnimate();
		void animate();

		virtual int collectableEffect(Person* person) = 0;
		virtual void setSprite() = 0;
		virtual void setSoundEffect() = 0;

	public:
		Collectable(int startingX, int startingY);
		void tick();
		sf::Sprite getSprite();
		int collect(Person* person);
		bool getActive();
};

#endif