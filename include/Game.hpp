#ifndef		H__GAME__
#define		H__GAME__

#include "Person.hpp"
#include "Monster.hpp"
#include "Weapons.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
#include "SFML/System.hpp"

class Game {
	public:
		Game(sf::RenderWindow& window);
		int start();
		void run();
	private:
		void processEvents();
		void update();
		void render();

		std::vector<Monster> monsters;
		Person player;
		Weapons weapon;
		bool done;
		int score;
		sf::Text scoreLabel;
		sf::Text playerHealth;	
        	sf::Font font;
		sf::RenderWindow& window;
		sf::Vector2f playerCenter;
		sf::Vector2f mousePosWindow;
		sf::Vector2f aimDir;
		sf::Vector2f aimDirNorm;



};

#endif
