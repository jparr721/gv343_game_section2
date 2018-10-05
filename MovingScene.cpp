#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "IntroEntity.hpp"
#include "IntroInstruction.hpp"
#include "MovingScene.hpp"

namespace intro{
  namespace moving_scene{
    MovingScene::MovingScene(
        std::string entitiesFilename,
        std::string instructionsFilename,
        std::string soundBufferFilename,
        std::string music,
        sf::Music &player){
      initEntities(entitiesFilename);

    }

    void MovingScene::run(sf::RenderWindow &window){
      window.clear();
      window.display();
    }

    void  MovingScene::initEntities(std::string &entitiesFilename){
      constexpr int BUFFER_SIZE = 5; 

      std::ifstream entityList(entitiesFilename);
      if(!entityList){
        //Throw IO error 
      }

      //Define a buffer and get the first line containing the
      //number of entities
      std::string buffer[BUFFER_SIZE];
      std::getline(entityList, buffer[0]);
      int size = std::stoi(buffer[0]);

      //test something 
      for(int index = 0; index < size; ++index){
        //Split the line
        for(int buffer_index = 0; buffer_index < BUFFER_SIZE; 
            ++buffer_index){
          std::getline(entityList, buffer[buffer_index], ',');
        }

        //Extract the scale and position of the entity.
        Scale scale(std::stoi(buffer[1]), std::stoi(buffer[2]));
        Position position(std::stoi(buffer[3]), std::stoi(buffer[4]));

        entities.push_back(IntroEntity(buffer[0],scale, position));

      }

      entityList.close();
    }

    void MovingSceneinitInstructions(std::string &instructionsFilename){

    }

    void MovingScene::initSounds(std::string &soundBufferList){

    }

  }
}
