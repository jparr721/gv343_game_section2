#include "WindowLoader.hpp"

namespace loader {
  sf::RenderWindow* WindowLoader::get_window() {
    return this->CURRENT_WINDOW;
  }

  void WindowLoader::set_window(sf::RenderWindow* current_window) {
    this->CURRENT_WINDOW = current_window;
  }
} // namespace loader
