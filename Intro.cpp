//
// Created by Kyle Flynn on 10/2/2018.
//
#include <iostream>
#include "Intro.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
namespace intro {
    int Intro::show(sf::RenderWindow& window) {
        window.clear();

        sf::Texture splash;
        if (!splash.loadFromFile("./images/neighborhood.png")) {
            return EXIT_FAILURE;
        }
        sf::Sprite sprite;
        sprite.setTexture(splash);
        sf::Font font;
        if (!font.loadFromFile("./fonts/Notable-Regular.ttf")) {
            return EXIT_FAILURE;
        }

        sf::Text title;
        title.setFont(font);
        title.setString("OH BOY OH BOY OH BOY");
        title.setCharacterSize(84);
        title.setFillColor(sf::Color::Red);
        title.setPosition(10, 200);

        sf::Text text;
        text.setFont(font);
        text.setString("PrEsS EnTeR tO C0nT1Nu3");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(150, 350);

        sf::Clock clock;

        // TODO - This currently breaks.
//        sf::SoundBuffer sound_buffer;
//        if (!sound_buffer.loadFromFile("music/epic_hero.wav")) {
//            text.setFillColor(sf::Color::Black);
//        } else {
//            text.setFillColor(sf::Color::White);
//        }

        float seconds = 0.0f;
        while (seconds <= 5.0f) {
            window.draw(sprite);
            window.draw(title);
            window.draw(text);
            window.display();
            
            seconds = clock.getElapsedTime().asSeconds();
        }
        return 0;
    }
} // namespace intro