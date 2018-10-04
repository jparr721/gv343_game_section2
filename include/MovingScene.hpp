#ifndef         MOVING_SCENE_HPP
#define         MOVING_SCENE_HPP

#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "IntroInstruction.hpp"


namespace intro{
  namespace moving_scene{
    class MovingScene{
      public:
        MovingScene();

      private:
        std::vector<sf::Sprite> entities;
        std::vector<IntroInstruction> instructions;
        std::vector<sf::SoundBuffer> bufferedFiles;
        std::vector<sf::Sound> sounds;
        sf::Music player;
        sf::RenderWindow window;
        
    };
  }
}

#endif
