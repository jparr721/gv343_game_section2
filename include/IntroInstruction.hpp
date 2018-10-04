#ifndef             INSTRUCTIONS_HPP
#define             INSTRUCTIONS_HPP

#include <string>
#include "SFML/System.hpp"


namespace intro{
  namespace moving_scene{
    class IntroInstruction{
      public: 
        IntroInstruction(int entityID, std::string text, char action,
            int deltaX, int deltaY);

        std::string getText() const;

        sf::Vector2f getVector() const;

        enum Action :unsigned char {
          MOVE_ENTITY,
          SET_POSITION,
          TOGGLE__ENTITY,
          DISPLAY_SPEECH, 
          PLAY_SOUND
        };

      private:
        int entityID;
        Action action;
        std::string detail;
    };
  }
}



#endif
