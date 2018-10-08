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
    /******************************************************************
     * The MovingScene class allow the game to run prebuilt cutscenes 
     * inside the game. It uses an instruction set to maniulate the 
     * screen and play sound. The class is limited to only doing one
     * action at a time. It cannot do two operations at onces. Keep
     * this in mind when makeing cutscenes.
     *
     * Author: David Baas
     * Version: 1.0 - 10/5/2018
     * Since: 1.0 - 10/5/2018
     *****************************************************************/
    class MovingScene{
      public:
        /**************************************************************
         * The constructor initalizes all of the data needed to run
         * the cutscene. The class handles loading the assets it 
         * needs therefore the input parameters are list of assets 
         * need for the cutscene. List should be checked for errors 
         * before runtime. There is no error checking for incorrect
         * list files
         *
         * A line in an entity list file should follow the following 
         * format:
         * <sprite name>,<x scale>,<y scale>,<starting x>,<starting y>
         *
         * For the format of an instruction list file, refer to the 
         * IntroInstruction header file.
         *
         * For a sound buffer list, one line should have a single 
         * filename on it. 
         *
         * Remember for all filenames that it must use reletive path.
         *
         * Param: entitiesFilename The list being used to build entities.
         * Param: instructionsFilename The list of instructions for 
         * this scene.
         * Param: soundBufferFilename The list of sound effects
         * that will be used in this scene.
         * Param: music The name of the music file being played 
         * for this scene.
         * Param: &player a reference to the music player for this 
         * scene.
         *************************************************************/
        MovingScene(
            std::string entitiesFilename, 
            std::string instructionsFilename,
            std::string soundBufferFilename,
            std::string music,
            sf::Music &player);

        /**************************************************************
         * The run fuction carrys out the sequence of the cutscene
         * until it is finished. The running loop is carried out 
         * in the following order 
         * 1. Read the action.
         * 2. Take the action. 
         * 3. Update screen if needed. 
         *
         * Param: window The window being used to display this scene.
         *************************************************************/
        void run(sf::RenderWindow &window);

      private:
        /* A list of entities for this scene. */
        std::vector<IntroEntity> entities;

        /* The list of instructions for this scene.  */
        std::vector<IntroInstruction> instructions;

        /* The list of buffered sounds for this scene  */
        std::vector<sf::SoundBuffer> bufferedFiles;

        /* The list of sounds for this scene. */
        std::vector<sf::Sound> sounds;

        /* The music player for this scene. */
        sf::Music player;

        /* The text being displayed on the screen for this scene. */
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

        /**************************************************************
         * A private function to initalize the entities for the scene
         *
         * Param: entitiesFilename The list being used to build entities.
         *************************************************************/
        void initEntities(std::string &entitiesFilename);

        /**************************************************************
         * A private function to load the instructions into memeory
         *
         * Param: instructionsFilename The list of instructions for 
         * this scene.
         *************************************************************/
        void initInstructions(std::string &instructionsFilename);

        /**************************************************************
         * A private function to load the sound effects into memory.
         *
         * Param: soundBufferList The list of sound effects being used
         * in this scene.
         *************************************************************/
        void initSounds(std::string &soundBufferList);

        void move_entity(int entityID, sf::Vector2f  move);
        void forcePosition(int entityID, sf::Vector2f posiston);
        void toggleEntity(int entityID);
        void displaySpeech(std::string text, sf::RenderWindow &window);
        void playSound(int soundNumber);
        void wait(float time, sf::RenderWindow &window);
        void updateScreen(sf::RenderWindow &window);

        sf::Vector2f convertToVec(std::string detail);
        int convertToInt(std::string detail);


        
    };
  }
}

#endif
