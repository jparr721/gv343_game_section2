#ifndef         MOVING_SCENE_HPP
#define         MOVING_SCENE_HPP

#include <string>
#include <vector>
#include <queue>
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
            sf::Music &player,
            sf::RenderWindow &window);

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
        void run();

      private:
        /* A list of entities for this scene. */
        std::vector<IntroEntity> entities;

        /* The list of instructions for this scene.  */
        std::queue<IntroInstruction> instructions;

        /* The list of buffered sounds for this scene  */
        std::vector<sf::SoundBuffer> bufferedFiles;

        /* The list of sounds for this scene. */
        std::vector<sf::Sound> sounds;

        /* The window being used to display the cutscene */
        sf::RenderWindow &window;

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
        std::vector<std::string> splitString(std::string &line, 
        char delimiter);

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

	/*************************************************************
	 * A private funstion to run the next Instruction/Scene
	 *
	*************************************************************/
        float doNextInstruction();

	/*************************************************************
	 * This method moves a given Image/sprite 
	 *
	*************************************************************/
        void move_entity(int entityID, sf::Vector2f  move);

	/*************************************************************
	 * This method will place the given entity to a static 
	 * position 
	 *
	*************************************************************/
        void forcePosition(int entityID, sf::Vector2f posiston);

	/*************************************************************
	 * This method will 'toggle'/activate and diactivate
	 * a specific entitiy acoirding tho its current state 
	 *
	 **********************************************************/
        void toggleEntity(int entityID);

	/*************************************************************
	 * this methods will emulate pockemon style subtitles
	 * as the main form of speech
	 *
	*************************************************************/
        void displaySpeech(std::string text);

	/*************************************************************
	 * This method will play a sound based on its ID
	 *
	*************************************************************/
        void playSound(int soundNumber);

	/*************************************************************
	 * This method will simulate a leep acording to the 
	 * given time in milliseconds
	 *
	*************************************************************/
        void wait(float time);

	/*************************************************************
	 * This methods re renders the screen to its current state
	 *
	*************************************************************/
        void updateScreen();

	/*************************************************************
	 * Converts the given String to a Vector Object 
	 *
	*************************************************************/
        sf::Vector2f convertToVec(std::string detail);

	/*************************************************************
	 * Converts the given String to an int 
	 *
	*************************************************************/
        int convertToInt(std::string detail);
    };
  }
}

#endif
