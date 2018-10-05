#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
#include "SFML/Graphics.hpp"
#include <string>

namespace intro {
  class Intro {
    public:
      sf::RenderWindow& window;
      Intro() = default;
      explicit Intro(sf::RenderWindow& rw);
      ~Intro() = default;
      int show();
  private:
      int showLogo();
  };
} // namespace intro

#endif
