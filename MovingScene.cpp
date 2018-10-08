#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
        sf::Music &player
        ,sf::RenderWindow &rw): window(rw){

      //Load all the components in seperate functions
      initEntities(entitiesFilename);
      initInstructions(instructionsFilename);
      initSounds(soundBufferFilename);

      player.openFromFile(music);

    }

    void MovingScene::run(){
      float nextInstruction = 2.0f;
      float timeElapsed = 0.0f;
      //The ambient wait between the next instruction happening.
      constexpr float AMBIENT_WAIT= .25f;
      bool running = true;
      
      sf::Event event;
      sf::Clock timer;

      //Hard code some sprites as disabled.
      //If there was more added this code below would have to be cut
      entities[2].setEnabled(false);
      entities[3].setEnabled(false);
      entities[4].setEnabled(false);

      timer.restart();
      while(running){
        this->window.pollEvent(event);
        this->window.clear();

        //Check to run the next instruction
        if(timeElapsed> nextInstruction){
          float extraWaitTime = doNextInstruction();
          nextInstruction = timer.getElapsedTime().asSeconds() +
            AMBIENT_WAIT + extraWaitTime;
        }
        updateScreen();
        this->window.display();
        running = !instructions.empty();
        timeElapsed = timer.getElapsedTime().asSeconds();
      }
      window.clear();
    }

    void  MovingScene::initEntities(std::string &entitiesFilename){
      constexpr int BUFFER_SIZE = 5;
    
      std::string data[BUFFER_SIZE];
      io::CSVReader<5> reader(entitiesFilename);
      while(reader.read_row(data[0], data[1], data[2],
      data[3], data[4])){

        Scale scale(std::stoi(data[1]), std::stoi(data[2]));

        entities.push_back(IntroEntity(data[0],scale,
         std::stoi(data[3]), std::stoi(data[4])));

      }
    }

    //TODO make this use csv header
    void MovingScene::initInstructions(std::string &instructionsFilename){
      constexpr int BUFFER_SIZE = 4; 
      std::string buffer[BUFFER_SIZE];

      io::CSVReader<3> lineReader(instructionsFilename);

      while(lineReader.read_row(buffer[0], buffer[1],
            buffer[2])){ 
         instructions.push(IntroInstruction(
              std::stoi(buffer[0]),
              buffer[1], 
              buffer[2]
              )
            );
      }
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

    float MovingScene::doNextInstruction(){
      float addedWait = 0.0f;

      IntroInstruction  &instruction = instructions.front();
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

          case IntroInstruction::TOGGLE_ENTITY:{
            toggleEntity(instruction.getEntityID());
            break;
          }

          case IntroInstruction::DISPLAY_SPEECH:{
            displaySpeech(instruction.getDetail());
            addedWait = 3.0f;
            break;
          }

          case IntroInstruction::PLAY_SOUND:{
            playSound(convertToInt(instruction.getDetail()));
            addedWait = 1.5f;
            break;
          }

          case IntroInstruction::WAIT:{
            addedWait = (float) convertToInt(instruction.getDetail());
            break;
          }
          default: break;
        }  
      instructions.pop();
      return addedWait;
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

    void MovingScene::displaySpeech(std::string text){
      sf::Font font;

      if(!font.loadFromFile("fonts/COMIC.TTF"))
        return;
      //Set the Text object
      this->text.setString(text);
      this->text.setCharacterSize(24);

      this->window.draw(this->text);
    }

    void MovingScene::playSound(int soundNumber){
      sounds[soundNumber].play();

    }

    void MovingScene::updateScreen(){
      for(int i = 0; i < entities.size(); ++i){
        if(entities[i].isEnabled()){
          this->window.draw(entities[i].getSprite());
        }
      }
    }

    sf::Vector2f MovingScene::convertToVec(std::string detail){
      std::istringstream strStream(detail);
      std::string splitStr[2];

      //Split the string
      std::getline(strStream, splitStr[0], ' ');
      std::getline(strStream, splitStr[1]);

      return sf::Vector2f(std::stoi(splitStr[0]), std::stoi(splitStr[1]));
    }

    int MovingScene::convertToInt(std::string detail){
      return std::stoi(detail);
    }
  }
}
