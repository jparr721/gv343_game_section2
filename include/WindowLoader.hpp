#ifndef INCLUDE_WINDOW_LOADER_HPP
#define INCLUDE_WINDOW_LOADER_HPP

#include "SFML/Graphics.hpp"

namespace loader {
  class WindowLoader {
      sf::RenderWindow* CURRENT_WINDOW;
    public:

      WindowLoader() = default;
      explicit WindowLoader(sf::RenderWindow* rw) : CURRENT_WINDOW(rw) {};
      ~WindowLoader() = default;

      sf::RenderWindow* get_window();
      void set_window(sf::RenderWindow*);
  };
} // namespace loader

#endif
