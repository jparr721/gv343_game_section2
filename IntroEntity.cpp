#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "IntroEntity.hpp"

namespace intro{
  namespace moving_scene{
    IntroEntity::IntroEntity(
        std::string filename, 
        Scale scale, 
        int x, int y){

      if(!texture.loadFromFile(filename)){
        std::cout << "failure on texture" << std::endl;
      }

      //Set sprite's texture, scale, and starting position
      sprite.setTexture(texture);
      sprite.setScale(scale.x, scale.y);
      sprite.setPosition(x, y);

      this->x = x;
      this->y = y;
      this->scale = scale;
    }

    sf::Sprite IntroEntity::getSprite(){
      this->sprite.setTexture(texture);
      return this->sprite;
    }

    void IntroEntity::moveSprite(int deltaX, int deltaY){
      if(deltaX < 0 ){
        sprite.setScale(-scale.x, scale.y);
      }
      else{
        sprite.setScale(scale.x, scale.y);
      }
      sprite.move(deltaX, deltaY);
    }

    void IntroEntity::setPosition(int x, int y){
      sprite.setPosition(x,y);
    }

    bool IntroEntity::isEnabled() const{
      return enabled;
    }

    void IntroEntity::setEnabled(bool enabled){
      this->enabled = enabled;
    }
  } 
}
