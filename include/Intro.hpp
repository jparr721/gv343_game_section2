#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
#include "SFML/Graphics.hpp"

namespace intro {
  class Intro {
    public:
      Intro() = default;
      Intro(int, int, sf::Font);
      ~Intro() = default;
      int show(sf::RenderWindow&);
  };
} // namespace intro

#endif
