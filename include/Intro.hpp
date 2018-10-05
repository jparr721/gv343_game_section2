#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
#include "SFML/Graphics.hpp"
#include <string>

namespace intro {
  class Intro {
    public:
      sf::RenderWindow* CURRENT_WINDOW;
      Intro() = default;
      explicit Intro(sf::RenderWindow& rw);
      ~Intro() = default;
      int show(sf::RenderWindow&);
      sf::RenderWindow* construct_window_context(int, int, std::string);
  };
} // namespace intro

#endif
