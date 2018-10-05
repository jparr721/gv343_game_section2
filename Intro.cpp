#include <iostream>
#include <Settings.hpp>
#include "Intro.hpp"
#include "SFML/Audio.hpp"

namespace intro {
    Intro::Intro(sf::RenderWindow &rw) {
      this->window = &rw;
    }

    int Intro::show() {
        this->window->clear();
        this->showLogo();
        return 0;
    }

    int Intro::showLogo() {
        sf::Texture logo;

        if (!logo.loadFromFile("./images/the_lord.jpg")) {
            return EXIT_FAILURE;
        }

        sf::Sprite sprite;
        sprite.setTexture(logo);
        sprite.scale(2.0f, 2.0f);

        sf::Font font;
        if (!font.loadFromFile("fonts/Wonder.ttf")) {
            return EXIT_FAILURE;
        }

        sf::Text title;
        title.setFont(font);
        title.setString("IRA PRODUCTIONS PRESENTS");
        title.setCharacterSize(32);
        title.setFillColor(sf::Color::White);

        // Position our elements
        sf::FloatRect txtRect = title.getGlobalBounds();
        sf::FloatRect picRect = sprite.getGlobalBounds();
        float txtPosX = (WIDTH - txtRect.width) / 2;
        float picPoxX = (WIDTH - picRect.width) / 2;

        title.setPosition(txtPosX, HEIGHT - 50);
        sprite.setPosition(picPoxX, 50);

        sf::Clock clock;
        float timeElapsed = 0.0f;

        while (timeElapsed < 5.0f) {
            this->window->draw(sprite);
            this->window->draw(title);
            this->window->display();
            timeElapsed = clock.getElapsedTime().asSeconds();
        }

        return 0;
    }
} // namespace intro

