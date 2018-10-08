#ifndef		__H__COLLECTABLE
#define		__H__COLLECTABLE

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include "Person.hpp"

class Collectable {
	private:
		sf::Texture texture;
		sf::SoundBuffer soundBuffer;

	protected:
		sf::Sound soundEffect;
		sf::Sprite sprite;
		sf::Clock clock;
		int lastMillisecondAnimated;
		bool active;

		/*
		 * loadTexture - A helper function that takes a file path with a
		 *		 bounding rectangle and loads that texture into
		 *		 the instances `sprite` variable
		 * 
		 * @param std::string path - The filepath where the texture sprite
		 * 			      file is located
		 * 
		 * @param sf::IntRect rect - A rectangle which provides the bounds
		 * 			     of the sprite
		 * 				     (eg: sf::IntRect(298, 273, 9, 9))
		 *
		 * @return void
		 *
		 */
		void loadTexture(std::string path, sf::IntRect rect);

		/*
		 * loadSoundEffect - A helper function that takes a file path and
		 * 		     loads the sound file into the instance, which
		 * 		     gets played once collected
		 *
		 * @param std::string path - The filepath where the sound effect
		 * 			     file is located
		 *
		 * @return void
		 *
		 */
		void loadSoundEffect(std::string path);

		/*
		 *
		 *    OVERRIDABLE METHODS
		 *
		 *    Inherit from this class and override these methods to provide
		 *    the unique characteristics to your collectable
		 *
		 */


		/*
		 * collectableEffect - Called by the parent class when `collect()`
		 *		       is called. Given a person pointer, modify
		 *		       anything which your collectable does.
		 *
		 * @param Person* person - A pointer to a person object
		 *
		 * @return void
		 *
		 */
		virtual int collectableEffect(Person* person) = 0;

		/*
		 * setSprite - Where your collectable defines the sprite configuration.
		 *	       Due to the nature of sprite loading, for now this function
		 *	       must be called within any child class which inherits from
		 *	      `Collectable`. 
		 *
		 *	       Example usage:
		 *
		 *	       ```
		 *	       void MyCollectable::setSprite() {
		 *	           this->loadTexture(
		 *	                "spriteFileLocation.png",
		 *	                sf::IntRect(298, 273, 9, 9)
		 *	           );
		 *	       }
		 *	       ```
		 *
		 * @return void
		 *
		 */
		virtual void setSprite() = 0;

		/*
		 * setSoundEffect - Where your collectable defines the sound effect location.
		 * 
		 * 		    Example usage:
		 * 
		 * 		    ```
		 * 		    void MyCollectable::setSoundEffect() {
		 *		        this->loadSoundEffect("locationOfMySoundEffect.wav");
		 *		    }
		 *		    ```
		 */
		virtual void setSoundEffect() = 0;

		/*
		 * animate - This function will be called by the parent class every 16ms
		 * 	     to provide 60fps animations. Leverage this to keep track of
		 * 	     call counts and set new textures based on time intervals.
		 * 
		 * 	     To set the texture:
		 *
		 *	     ```
		 *	      sprite.setTextureRect(sf::IntRect(300, 200, 10, 10));
		 *           ```
		 *
		 * @return void
		 *
		 */
		virtual void animate() = 0;

	public:
		/*
                 * Collectable - Constructor to create a collectable, pass in the starting
                 *               x and y positions.
                 *
                 * @param int startingX - The starting x position of the collectable.
                 *
                 * @param int startingY - The starting y position of the collectable.
		 *
		 */
		Collectable(int startingX, int startingY);


                /*
                 * tick - Call this function in the run loop of the game, it provides
                 *        the collectable with the ability to update itself for
                 *        animations, or provide some time based action.
                 *
                 * @return void
                 *
                 */
		void tick();

                /*
                 * getSprite - Gives access to the internal sprite object, most likely
                 *             for collision detection.
                 *
                 * @return sf::Sprite - A sprite object, which holds dimensions of the
                 *                      sprite for the collectable.
                 *
                 */
		sf::Sprite getSprite();

                /*
                 * collect - Calling this function will perform the action the collectable
                 *           is configured to do. Most likely call this function when
                 *           a collision is detected. Because the player does not hold
                 *           the score counter, this function will return any score
                 *           modifications it performs (positive or negative)
                 *
                 * @param Person* person - The game's player object for the collectable
                 *                         to perform it's effect on
                 *
                 * @return int - The score modification that is meant to be performed
                 *               for the player
                 *
                 */
		int collect(Person* person);

                /*
                 * getActive - Provides access to the `active` property on the collectable
                 *             which gets set to false once collected.
                 *
                 * @return bool - Returns the current `active` property within the collectable
                 *
                 */
		bool getActive();

                /*
                 * reset - Sets the `active` property to true within the collectable
                 *
                 * @return void
                 *
                 */
                void reset();
};

#endif
