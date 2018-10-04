#include <iostream>
#include "Intro.hpp"
#include "WindowLoader.hpp"
#include "SFML/Audio.hpp"

namespace intro {
  sf::RenderWindow* Intro::construct_window_context(
      int width = 800,
      int height = 600,
      std::string heading = "Video Games, OH YEAH"
      ) {
    this->rw.create(sf::VideoMode(width, height), heading);

    auto window_copy = &this->rw;

    return window_copy;
  }

  int Intro::show(sf::RenderWindow& window) {
    window.clear();
    sf::Texture spash;

    if (!spash.loadFromFile("./images/neighborhood.png")) {
      return EXIT_FAILURE;
    }

    sf::Sprite sprite;
    sprite.setTexture(spash);

    sf::Font font;
    if (!font.loadFromFile("fonts/Notable-Regular.ttf")) {
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

    sf::Music music;

    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
          return 0;
        }

        if (event.type == sf::Event::KeyPressed) {
          if(event.key.code == sf::Keyboard::Return) {
            window.clear();
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
} // namespace intro

