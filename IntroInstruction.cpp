#include <string>
#include "SFML/System.hpp"
#include "IntroInstruction.hpp"

namespace intro{
  namespace moving_scene{
    IntroInstruction::IntroInstruction(
        int entityID, 
        std::string action, 
        std::string detail){

      this->entityID = entityID;
      this->detail = detail;
      IntroInstruction::initAction(action);
    }

    int IntroInstruction::getEntityID() const{
      return entityID;
    }

    IntroInstruction::Action IntroInstruction::getAction() const{
      return action;
    }

    std::string IntroInstruction::getDetail() const {
      return detail;
    }

    sf::Vector2f IntroInstruction::getVector() const{
      std::string values[2];
      char tokenLoc = detail.find(",");

      values[0] = detail.substr(0,tokenLoc);
      values[1] = detail.substr(tokenLoc + 1, detail.length());
      return sf::Vector2f(std::stof(values[0]), std::stof(values[1]));
    }

    void IntroInstruction::initAction(std::string action){
      if(action == "MOVE_ENTITY"){
        this->action = MOVE_ENTITY;
      }
      else if(action == "SET_POSITION"){
        this->action = SET_POSITION;
      }
      else if(action == "TOGGLE__ENTITY"){
        this->action = TOGGLE__ENTITY;
      }
      else if(action == "DISPLAY_SPEECH"){
        this->action = DISPLAY_SPEECH;
      }
      else if(action == "PLAY_SOUND"){
        this->action = PLAY_SOUND;
      }
      else if(action == "WAIT"){
        this->action = WAIT;
      }
      else{
        //throw error
      }
    }
  }
}

