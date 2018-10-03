#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
#include "SFML/Graphics.hpp"


namespace intro {
  class Intro {
    public:
      sf::Font FONT;
      sf::Text TITLE;

      Intro(int, int, sf::Font);
      ~Intro() = default;

      int display_intro();

    private:
      sf::RenderWindow window;
      bool loaded;
  };
} // namespace intro

#endif
