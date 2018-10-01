#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
#include "SFML/Graphics.hpp"


namespace intro {
  class Intro {
    public:
      Intro() = default;
      ~Intro() = default;

      int display_intro();

    private:
      sf::RenderWindow window;
      bool loaded;
  };
} // namespace intro

#endif
