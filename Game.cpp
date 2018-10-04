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
#include <iostream>
#include <random>
#include <Intro.hpp>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

/*
 * Default constructor.  Creates our window and sets up
 * initial state of shared variables.
 */
Game::Game(){
	// Creates the window.  We are using the same window for
	// the intro screen as the game, though this can change.
	window.create(sf::VideoMode(WIDTH, HEIGHT + 100), "Not on my block.");
	// when done is true we quit
	done = false;
	// Add monsters to the game via a vector of Monsters.
	monsters.push_back(Monster());
	// The "standard" game font is loaded here.
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		std::cerr << "We should be throwing exceptions here... font can't load." << std::endl;
	}
}

/*
 * Display a splash screen with some message for users.
 * Gives them a chance to get situated before the game
 * starts.  Should add a menu to it perhaps.
 */

int Game::start(){
  // Build our game intro
  intro::Intro i;

  // Build our window context and pass the ref
  auto intro_window = i.construct_window_context(800, 600, "Video Games, OH YEAH");

  // Deref our window and show it
  int running = i.show(*intro_window);
  if (running < 0) {
    std::cerr << "Oh man the intro screen broke :(" << std::endl;
    return EXIT_FAILURE;
  }

	return 0;
}

/*
 * The main game loop.
 * We may wish to change the run conditions here
 * as the window should stay open after the game play
 * is complete.
 */

void Game::run()
{
	player.initialize();
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
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
				exit(0);

			case sf::Event::KeyPressed:
				switch(event.key.code){
					std::cout << event.key.code;
					case sf::Keyboard::Left:
					player.updatePosition(-20, 0);
					break;
					case sf::Keyboard::Right:
					player.updatePosition(20, 0);
					break;
					case sf::Keyboard::Up:
					player.updatePosition(0, -20);
					break;
					case sf::Keyboard::Down:
					player.updatePosition(0, 20);
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
	for(auto it = monsters.begin(); it != monsters.end(); ++it){
		if(Collision::BoundingBoxTest(player.getSprite(), it->getSprite())){
			player.harm(20);
			std::uniform_int_distribution<int> distribution(0,50);
			std::random_device rd;
			std::mt19937 engine(rd());
			player.updatePosition(distribution(engine), distribution(engine));
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
	for(auto it = monsters.begin(); it != monsters.end(); ++it){
		window.draw( it->getSprite() );
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
