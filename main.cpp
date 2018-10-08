#include <iostream>
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include "Intro.hpp"
#include "Game.hpp"

int main(int argc, char** argv){

	// Create the global window instance.
	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT+100), "Not on my block.");

	// Initialize our intro, and game screens with the window reference.
	Game g(window);
	intro::Intro i(window);

	// Show the intro.
	i.show();

	while(true) {
		int started = g.start();
		if (started  < 0) {
			std::cerr << "Error! Game failed to start" << std::endl;
			break;
		}
		g.run();
	}
}
