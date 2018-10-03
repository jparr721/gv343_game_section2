#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP
<<<<<<< HEAD
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
=======

#include "SFML/Graphics.hpp"

namespace intro {
    class Intro {
    public:
        Intro() = default;
        ~Intro() = default;
        int show(sf::RenderWindow&);
    private:
        bool loaded;
    };
}
#endif
>>>>>>> 45f038e730db9cc1f132b31858ce65288815d09a
