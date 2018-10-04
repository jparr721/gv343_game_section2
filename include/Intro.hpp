#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
#include "SFML/Graphics.hpp"
#include <string>

namespace intro {
  class Intro {
    sf::RenderWindow rw;
    public:
      Intro() = default;
      ~Intro() = default;
      int show(sf::RenderWindow&);
      sf::RenderWindow* construct_window_context(int, int, std::string);
  };
} // namespace intro

#endif
