#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/tokenizer.hpp>
#include "csv.h"

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

      //Load all the components in seperate functions
      initEntities(entitiesFilename);
      initInstructions(instructionsFilename);
      initSounds(soundBufferFilename);

      player.openFromFile(music);

    }

    void MovingScene::run(sf::RenderWindow &window){
      sf::Event event;

      for(const auto &instruction: instructions){
        window.clear();
        window.pollEvent(event);

        switch(instruction.getAction()){
          case IntroInstruction::MOVE_ENTITY:{
            move_entity(instruction.getEntityID(),
                convertToVec(instruction.getDetail()));
            break;
          }

          case IntroInstruction::SET_POSITION:{
            forcePosition(instruction.getEntityID(),
                convertToVec(instruction.getDetail()));
            break;
          }

          case IntroInstruction::TOGGLE__ENTITY:{
            toggleEntity(instruction.getEntityID());
            break;
          }

          case IntroInstruction::DISPLAY_SPEECH:{
            displaySpeech(instruction.getDetail(), window);
            break;
          }

          case IntroInstruction::PLAY_SOUND:{
            playSound(convertToInt(instruction.getDetail()));
            break;
          }
          
          case IntroInstruction::WAIT:{
            wait(convertToInt(instruction.getDetail()), window);
            break;
          }
          default: break; 



        }
      }
      window.clear();
      //      sf::Event event;
      //Test code rm when done
      // sf::Clock timer;
      // float timeElapsed = 0.0f;
      // while(timeElapsed < 5.0f){
      //   window.pollEvent(event);
      //   window.clear();
      //   if(timeElapsed > 2.0f){
      //     window.clear();
      //     entities.front().setPosition(200,200);
      //   }
      //   window.draw(entities.front().getSprite());
      //   window.display();

      //   timeElapsed = timer.getElapsedTime().asSeconds();
      // }
    }

    void  MovingScene::initEntities(std::string &entitiesFilename){
      std::ifstream entityList(entitiesFilename);

      std::string raw_line;
      std::vector<std::string> data;
      while(std::getline(entityList, raw_line)){
        boost::tokenizer<boost::escaped_list_separator<char>> raw_split
        {raw_line};
        //Put the values inside the vector to be referenced 
        for(const auto &value :raw_split){
          data.push_back(value);
        }

        //Load an entity
        Scale scale(std::stoi(data[1]), std::stoi(data[2]));
        Position position(std::stoi(data[3]), std::stoi(data[4]));

        entities.push_back(IntroEntity(data[0],scale, std::stoi(data[3]), std::stoi(data[4])));
        data.clear();
      }
      entityList.close();
    }

    //TODO make this use csv header
    void MovingScene::initInstructions(std::string &instructionsFilename){
      constexpr int BUFFER_SIZE = 3; 

      //This has the exception built in according to Prof. Woodring
      std::ifstream instructionList(instructionsFilename);

      //get the number of elements in this list
      std::string buffer[BUFFER_SIZE];
      std::getline(instructionList, buffer[0]);
      int size = std::stoi(buffer[0]);

      // //throw away the line
      // std::getline(instructionList, buffer[0]);

      for(int index = 0; index < size; ++index){
        //Extract the line
        std::getline(instructionList, buffer[0], ',');
        std::getline(instructionList, buffer[1], ',');
        std::getline(instructionList, buffer[2]);

        //Add the element to the vector
        instructions.push_back(IntroInstruction(
              std::stoi(buffer[0]),
              buffer[1], 
              buffer[2]
              )
            );
      }

      instructionList.close();
    }

    void MovingScene::initSounds(std::string &soundBufferList){
      std::ifstream soundList(soundBufferList);
      std::string buffer;

      //Load each buffer and sound file.
      while(std::getline(soundList, buffer)){
        bufferedFiles.push_back(sf::SoundBuffer());
        sounds.push_back(sf::Sound());
        bufferedFiles.back().loadFromFile(buffer);
        sounds.back().setBuffer(bufferedFiles.back());
      }
      soundList.close();
    }

    void MovingScene::move_entity(int entityID, sf::Vector2f  move){
      entities[entityID].moveSprite(move.x, move.y);
    }

    void MovingScene::forcePosition(int entityID, sf::Vector2f position){
      entities[entityID].setPosition(position.x, position.y);
    }

    void MovingScene::toggleEntity(int entityID){
      //Reverse the bool flag on the given entity
      entities[entityID].setEnabled(
          !entities[entityID].isEnabled());
    }

    void MovingScene::displaySpeech(std::string text, sf::RenderWindow &window){
      constexpr float MAX_TIME = 3.0f;

      //Set the Text object
      this->text.setString(text);
      this->text.setCharacterSize(24);

      //Declare timers.
      float timeElapsed = 0.0f;
      sf::Clock timer;
      updateScreen(window);
      window.draw(this->text);

      while(timeElapsed < MAX_TIME){
        window.display();
        timeElapsed = timer.getElapsedTime().asSeconds();
      }
    }

    void MovingScene::playSound(int soundNumber){
      sounds[soundNumber].play();

    }

    void MovingScene::wait(float time, sf::RenderWindow &window){
      //Declare timers.
      float timeElapsed = 0.0f;
      sf::Clock timer;
      while(timeElapsed < time){
        window.display();
        timeElapsed = timer.getElapsedTime().asSeconds();
      }
    }

    void MovingScene::updateScreen(sf::RenderWindow &window){
      window.clear();
      for(int i = 0; i < entities.size(); ++i){
        if(entities[i].isEnabled()){
          window.draw(entities[i].getSprite());
        }
      }
    }

    sf::Vector2f MovingScene::convertToVec(std::string detail){
      std::istringstream strStream(detail);
      std::string splitStr[2];

      //Split the string
      std::getline(strStream, splitStr[0], ',');
      std::getline(strStream, splitStr[1]);

      return sf::Vector2f(std::stoi(splitStr[0]), std::stoi(splitStr[1]));
    }

    int MovingScene::convertToInt(std::string detail){
      return std::stoi(detail);
    }
  }
}
