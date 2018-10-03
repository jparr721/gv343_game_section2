#ifndef INC_343GAME_WEAPONS_HPP
#define INC_343GAME_WEAPONS_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Weapons {
    public:
        Weapons();
        void initalize();
        void setRange(int range);
        void setDamage(int damage);
        void setPosition(int x, int y);
        sf::Sprite getSprite();

    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int range;
        int damage;
        int x;
        int y;
        bool equipped;
        sf::SoundBuffer soundBuffer;
        sf::Sound sound;
};

#endif //INC_343GAME_WEAPONS_HPP
