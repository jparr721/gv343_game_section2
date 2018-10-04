#ifndef             INSTRUCTIONS_HPP
#define             INSTRUCTIONS_HPP

#include <string>
#include "SFML/System.hpp"


namespace intro{
  namespace moving_scene{
    /******************************************************************
     * The IntroInstruction class holds the instruction for a 
     * sequenced scene in memory. It hold information such as what 
     * entity is being modified, the action being taken, and details
     * related to the action. It is inteded that a series of action
     * is made ahead of time and saved in a .csv file. From there
     * the MovingScene class will load it into memeory.
     *
     * Author David Baas
     * Version 1.0 - 10/4/2018
     * Since 1.0 - 10/4/2018
     *****************************************************************/
    class IntroInstruction{
      public:
        /**************************************************************
         * The constructor initalizes all of the varable. 
         *
         * Param: entityID the id of the entity being modified by this
         * instruction.
         * Param: action the action being taken with this instruction.
         * Param: The details of this instruction.
         *************************************************************/
        IntroInstruction(int entityID, std::string action, std::string detail);
            
        /**************************************************************
         * Return the details of this instruction as a string. Used 
         * for getting file names and speech. 
         *
         * Return: The value of detail as a string.
         *************************************************************/
        std::string getText() const;

        /**************************************************************
         * Returns the details of the instruction as a vector. Used
         * for getting a position or a movement.
         *
         * Return: The value of details as a vector.
         *************************************************************/
        sf::Vector2f getVector() const;

        /*A series of enumerated types to define actions*/
        enum Action :unsigned char {
          MOVE_ENTITY,
          SET_POSITION,
          TOGGLE__ENTITY,
          DISPLAY_SPEECH, 
          PLAY_SOUND,
          WAIT
        };

      private:
        /**************************************************************
         * All the entities will be held in a vector.
         * This value tracks what entity is being modified by this
         * instruction. If an action is not being done on an entitiy 
         * the value should be -1.
         *************************************************************/
        int entityID;

        /*The action being taken with this instruction.*/
        Action action;

        /**************************************************************
         * The detials of the instruction weather its text on the screen,
         * a vector value, a lentgh of time to wait, or the file to
         * play for a sound file.
         **************************************************************/
        std::string detail;

        /*A private method to initialize the action.*/
        void initAction(std::string action);
    };
  }
}
#endif

