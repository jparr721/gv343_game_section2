#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "IntroEntity.hpp"

namespace intro{
  namespace moving_scene{
    IntroEntity::IntroEntity(
        std::string filename, 
        Scale scale, 
        Position start){

      if(!texture.loadFromFile(filename)){
        //throw error
      }

      //Set sprite's texture, scale, and starting position
      sprite.setTexture(texture);
      sprite.setScale(scale.x, scale.y);
      sprite.setPosition(start.x, start.y);

      this->scale = scale;
    }

    sf::Sprite IntroEntity::getSprite(){
      //if(deltaX > 0 || deltaX < 0){
      //sprite.setScale(-scale.x, scale.y);
      //}

      //Update the sprites position
      //sprite.move(deltaX, deltaY);

      return sprite;
    }

    void IntroEntity::moveSprite(int deltaX, int deltaY){
      if(deltaX > 0 || deltaX < 0){
        sprite.setScale(-scale.x, scale.y);
      }

      sprite.move(deltaX, deltaY);

    }
  } 
}
