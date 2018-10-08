#ifndef CREDITS_H
#define CREDITS_H

#include <string> 
#include <vector>
#include "SFML/Graphics.hpp"
class Credits {


	public:
	
	sf::RenderWindow* window;	
	Credits(); 
	int start(sf::RenderWindow& rw);
	

	private:
	int yText;
	int xText;
	int timeModifier;
	int xPic;
	int yPic;
	int xMon;
	int yMon;
	int staggerFactor;
	int count;
	int otX;
	int otY;


	unsigned int timeFactor;

	sf::Texture splash;
	sf::Texture mTexture; 

	sf::Sprite overlord;
	sf::Sprite monster1;
	sf::Sprite monster2;

	sf::Text gameTitle;
	sf::Text overlordText;
	sf::Text groups;


	sf::Font font;

	sf::Clock clock;
	sf::Time time;
	sf::Int32 mills;

	std::vector<std::vector<std::string>> credits;

};

#endif
