/*
 * Game.cpp
 * Much code taken from SFML tutorials on SFML site.  Basic
 * flow tutorial at
 * from https://maksimdan.gitbooks.io/sfml-and-gamedevelopement/content/game_class.html
 *
 * You will need to read SFML API and other documentation to understand this code
 */

#include "Collision.hpp"
#include "Game.hpp"
#include "Person.hpp"
#include "Monster.hpp"
#include "Settings.hpp"
#include "Coin.hpp"
#include "Sandwich.hpp"
#include <iostream>
#include <random>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

/*
 * Default constructor.  Creates our window and sets up
 * initial state of shared variables.
 */
Game::Game(sf::RenderWindow& rw) : window(rw) {
	// when done is true we quit
	done = false;
	// Add monsters to the game via a vector of Monsters.
	monsters.push_back(Monster());

        // Add collectable to the game
        collectables.push_back(new Coin(300, 300));
        collectables.push_back(new Sandwich(200, 200));

	// The "standard" game font is loaded here.
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		std::cerr << "We should be throwing exceptions here... font can't load." << std::endl;
	}
}

class Bullet {
public:
	sf::CircleShape shape;
	sf::Vector2f curVelo;
	float maxSpeed;
	Bullet(float radius = 6.f) : curVelo(0.f, 0.f), maxSpeed(1.f){
		this->shape.setRadius(radius);
		this->shape.setFillColor(sf::Color::Red);
	}
};

/*
 * Display a splash screen with some message for users.
 * Gives them a chance to get situated before the game
 * starts.  Should add a menu to it perhaps.
 */

int Game::start(){
	window.clear();
	sf::Texture splash;
	if(!splash.loadFromFile("./images/neighborhood.png")){
		std::cerr << "Can't load start image." << std::endl;
	}
	sf::Sprite sprite;
	sprite.setTexture(splash);

	sf::Font font;
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		return EXIT_FAILURE;
	}

	sf::Text title;
	title.setFont(font);
	title.setString("Not on my block.");
	title.setCharacterSize(64);
	title.setFillColor(sf::Color::White);
	title.setPosition(10,200);

	sf::Text text;
	text.setFont(font);
	text.setString("(Press Enter to continue)");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(150, 350);

	sf::Clock clock;


	sf::Music music;
	if(!music.openFromFile("music/epic_hero.wav")){
		return EXIT_FAILURE;
	}

	music.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
				music.stop();
				exit(0);
			}

			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return){
					window.clear();
					music.stop();
					return 0;
				}
			}

		}

		window.draw(sprite);
		window.draw(title);
		window.draw(text);
		window.display();

		sf::Time time = clock.getElapsedTime();
		sf::Int32 mills = time.asMilliseconds();
		if(mills % 1000 > 500){
			text.setFillColor(sf::Color::Black);
		} else {
			text.setFillColor(sf::Color::White);
		}
	}

	return 0;

}

/*
 * The main game loop.
 * We may wish to change the run conditions here
 * as the window should stay open after the game play
 * is complete.
 */
Bullet b1;
std::vector<Bullet> bullets;

void Game::run()
{
	player.initialize();
	weapon.initalize();
	bullets.push_back(Bullet(b1));
	done = false;
	sf::Music music;
	if(!music.openFromFile("music/in_game.wav")){
		std::cerr << "Unable to load in_game music file." << std::endl;
	}

	music.setVolume(50);
	music.setLoop(true);
	music.play();

	while (!done)
	{
		processEvents();
		update();
		render();
	}
	music.stop();

}

/*
 * All game events such as keypresses are handled
 * here.
 */

void Game::processEvents()
{
	sf::Event event;
	playerCenter = sf::Vector2f(weapon.getX(),weapon.getY());
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / (float)sqrt ((pow(aimDir.x,2.0) + pow(aimDir.y,2.0)));
	std::cout << aimDirNorm.x << "" << aimDirNorm.y << std::endl;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
				exit(0);
		    case sf::Event::MouseButtonPressed:
		        switch(event.mouseButton.button) {
		            case sf::Mouse::Left:
                        b1.shape.setPosition(playerCenter);
                        b1.curVelo = aimDirNorm * b1.maxSpeed;
                        bullets.push_back(Bullet(b1));
                    break;
		            default:
		            	break;
                }


			case sf::Event::KeyPressed:
				switch(event.key.code){
					std::cout << event.key.code;
					case sf::Keyboard::Left:
						player.updatePosition(-20, 0);
						weapon.setPosition(-20,0);
						break;
					case sf::Keyboard::Right:
						player.updatePosition(20, 0);
						weapon.setPosition(20,0);
						break;
					case sf::Keyboard::Up:
						player.updatePosition(0, -20);
						weapon.setPosition(0,-20);
						break;
					case sf::Keyboard::Down:
						player.updatePosition(0, 20);
						weapon.setPosition(0,20);
						break;
					default:
						break;
				}
			default:
				break;
		}
	}

}

/*
 * Here we update state after one loop.  Used for
 * checking collisions, updating score variables, etc.
 */

void Game::update()
{
	for(size_t i = 0; i < bullets.size();i++){
		bullets[i].shape.move(bullets[i].curVelo);
	}

	for(auto it = monsters.begin(); it != monsters.end(); ++it){
		if(Collision::BoundingBoxTest(player.getSprite(), it->getSprite())){
			player.harm(20);
			std::cout<< it->getHealth() << std::endl;
			std::uniform_int_distribution<int> distribution(0,50);
			std::random_device rd;
			std::mt19937 engine(rd());
			int dis1 = distribution(engine);
			int dis2 = distribution(engine);
			player.updatePosition(dis1, dis2);
			weapon.setPosition(dis1,dis2);

		}

	}
        for (auto col = collectables.begin(); col != collectables.end(); ++col)
        {
            if (Collision::BoundingBoxTest(player.getSprite(), (*col)->getSprite()) && (*col)->getActive())
            {
                score += (*col)->collect(&player);
            }
        }
	if(player.getHealth() <= 0){
		done = true;
	}

}

/*
 * Now that update() has updated our state we redraw.
 */

void Game::render()
{
	window.clear();
	window.draw(player.getSprite());
	window.draw(weapon.getSprite());
	for(size_t i = 0; i <bullets.size(); i ++){
		window.draw(bullets[i].shape);
	}
	for(auto it = monsters.begin(); it != monsters.end(); ++it){
		window.draw( it->getSprite() );
	}

        for (auto cl = collectables.begin(); cl != collectables.end(); ++cl)
        {
            if ((*cl)->getActive())
            {
                (*cl)->tick();
                window.draw((*cl)->getSprite());
            }
        }

	sf::RectangleShape border(sf::Vector2f(WIDTH, 20));
	border.setPosition(sf::Vector2f(0,HEIGHT));
	window.draw(border);
	scoreLabel.setFont(font);
	scoreLabel.setString("Score: " + std::to_string(score));
	scoreLabel.setCharacterSize(24);
	scoreLabel.setFillColor(sf::Color::White);
	scoreLabel.setPosition(50, HEIGHT + 40);
	playerHealth.setFont(font);
	playerHealth.setCharacterSize(24);
	playerHealth.setString("Health " + std::to_string(player.getHealth()));
	playerHealth.setFillColor(sf::Color::White);
	playerHealth.setPosition(300, HEIGHT + 40);
	window.draw(scoreLabel);
	window.draw(playerHealth);

	window.display();

}



