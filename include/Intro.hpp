#ifndef INCLUDE_INTRO_HPP
#define INCLUDE_INTRO_HPP

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