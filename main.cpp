#include "SFML/Graphics.hpp"
#include "Intro.hpp"
#include "Game.hpp"

int main(int argc, char** argv){
	Game g;
	intro::Intro i;
	while(true){
		i.show(g.window);
		g.start();
		g.run();
	}
}
