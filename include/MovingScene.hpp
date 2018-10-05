#ifndef         MOVING_SCENE_HPP
#define         MOVING_SCENE_HPP

#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "IntroEntity.hpp"
#include "IntroInstruction.hpp"


namespace intro{
  namespace moving_scene{
    class MovingScene{
      public:
        MovingScene(
            std::string entitiesFilename, 
            std::string instructionsFilename,
            std::string soundBufferFilename,
            std::string music,
            sf::Music &player);

        void run(sf::RenderWindow &window);

      private:
        std::vector<IntroEntity> entities;
        std::vector<IntroInstruction> instructions;
        std::vector<sf::SoundBuffer> bufferedFiles;
        std::vector<sf::Sound> sounds;
        sf::Music player;
        sf::Text text;

        /**************************************************************
         * Takes a string representing a csv line from a file and 
         * splits it into its respective parts in a vector. 
         *
         * This member function is adapted from the website
         * http://ysonggit.github.io/coding/2014/12/16/split-a-string-using-c.html
         *
         * Param: &line a reference to the string being split.
         * Param: delimiter the token used to split this string.
         * Return: The split line in a vector of strings.
         *************************************************************/
        std::vector<std::string> splitString(std::string &line, char delimiter);

        void initEntities(std::string &entitiesFilename);
        void initInstructions(std::string &instructionsFilename);
        void initSounds(std::string &soundBufferList);
        void updateFrame();
    };
  }
}

#endif
