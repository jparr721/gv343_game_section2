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

      private:
        int entityID;
        std::string text;
        char action;
        sf::Vector2i motion;
    };
  }
}



#endif
