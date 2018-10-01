#include <iostream>
#include "Intro.hpp"
#include "SFML/Audio.hpp"

namespace intro {
  int Intro::display_intro() {
    window.clear();
    sf::Texture spash;

    if (!spash.loadFromFile("./images/neighborhood.png")) {
      return EXIT_FAILURE;
    }

    sf::Sprite sprite;
    sprite.setTexture(spash);

    sf::Font font;
    if (!font.loadFromFile("./fonts/COMIC.ttf")) {
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
  }
} // namespace intro
