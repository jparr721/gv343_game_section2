#include <iostream>
#include <Settings.hpp>
#include <Animator.hpp>
#include "Intro.hpp"
#include "MovingScene.hpp"
#include "SFML/Audio.hpp"

namespace intro {
	Intro::Intro(sf::RenderWindow &rw) : window(rw) {

	}

	int Intro::show() {
		this->window.clear();
		this->showLogo();
		return 0;
	}

	int Intro::showLogo() {
		sf::Texture logo;
		sf::Color defaultColor(255, 255, 255, 0);

		if (!logo.loadFromFile("./images/the_lord.jpg")) {
			return EXIT_FAILURE;
		}

		sf::Sprite sprite;
		sf::Color spriteColor;
		sprite.setTexture(logo);
		sprite.scale(2.0f, 2.0f);
		spriteColor = sprite.getColor();
		spriteColor.a = 0;
		sprite.setColor(spriteColor);

		sf::Font font;
		if (!font.loadFromFile("fonts/Wonder.ttf")) {
			return EXIT_FAILURE;
		}

		sf::Text title;
		title.setFont(font);
		title.setString("IRA PRODUCTIONS PRESENTS");
		title.setCharacterSize(32);
		title.setFillColor(defaultColor);

		// Position our elements
		sf::FloatRect txtRect = title.getGlobalBounds();
		sf::FloatRect picRect = sprite.getGlobalBounds();
		float txtPosX = (WIDTH - txtRect.width) / 2;
		float picPoxX = (WIDTH - picRect.width) / 2;

		title.setPosition(txtPosX, HEIGHT - 50);
		sprite.setPosition(picPoxX, 50);

		sf::Clock clock;
		float timeElapsed = 0.0f;
		int alpha = 0;
		Animator alphaAnimator;

		alphaAnimator.init(0, 255, alpha, 1.0f);

		sf::Event event;
		while (timeElapsed < 10.0f) {
			window.pollEvent(event);
			this->window.clear();
			this->window.draw(sprite);
			this->window.draw(title);
			this->window.display();

			alphaAnimator.run(clock);

			defaultColor.a = alpha;
			spriteColor.a = alpha;
			title.setFillColor(defaultColor);
			sprite.setColor(spriteColor);

			timeElapsed = clock.getElapsedTime().asSeconds();
		}

		sf::Music player;
		moving_scene::MovingScene scene(
			"intros/entityList.txt",
			"intros/instructionList.txt",
			"intros/soundList.txt",
			"music/epic_hero.wav",
			player
		);

		scene.run(window);
//    std::cout << "here intro" <<std::endl;

		return 0;
	}
}

