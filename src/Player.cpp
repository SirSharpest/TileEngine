/*
 * Player.cpp
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 *
 *  Currently loads a  sprite
 *
 */

#include <iostream>
#include "Player.hpp"

Player::Player():
        mSpeed(200.f),
        mTileSize(64.f),
        mTravelled(0),
        movement(0.f, 0.f),
        mSize(1,1),
        mColor(sf::Color::Blue),
        mIsMovingUp(false),
        mIsMovingDown(false),
        mIsMovingLeft(false),
        mIsMovingRight(false),
        mIsTurbo(false),
        mIsMoving(false),
        characterSprite(),
        walkingAnimationDown(),
        walkingAnimationLeft(),
        walkingAnimationRight(),
        walkingAnimationUp(),
        currentAnimation(&walkingAnimationRight),
		lastMovement(0,0){




}


void Player::setUp(std::string fileLocation, int h, int w, std::vector<sf::Vector2f> leftMovements, std::vector<sf::Vector2f> rightMovements,
			   std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements){



	characterSprite.loadFromFile(fileLocation);

	//apply animations to image
	setupAnimation(characterSprite, h ,w , leftMovements, rightMovements, upMovements, downMovements);

	//Increasing the size of the image
    animatedPlayer.setScale(mSize);
	//animated sprite properties
	//default values for now
	animatedPlayer.setPosition(0, 0);



}

//is given the key that has been pressed and handles the input for it
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){

    //if not already moving
    if(!mIsMoving){
        if(key == sf::Keyboard::W)
            mIsMovingUp = isPressed;
        else if(key == sf::Keyboard::S)
            mIsMovingDown = isPressed;
        else if(key == sf::Keyboard::A)
            mIsMovingLeft = isPressed;
        else if(key == sf::Keyboard::D)
            mIsMovingRight = isPressed;
    }

    if(isPressed && mTravelled >= mTileSize)
        mTravelled = 0;

}


//perform movement for the player
sf::Vector2f Player::updatePlayer(sf::Time elapsedTime) {

        //Stop moving if reached destination
        if(mTravelled >= mTileSize){

            mIsMovingDown = false;
            mIsMovingUp = false;
            mIsMovingRight = false;
            mIsMovingLeft = false;
            mIsMoving = false;
            return sf::Vector2f(0,0);
        }

		//reset speed of movement and animation
		float movementSpeed = mSpeed;
		animatedPlayer.setFrameTime(sf::seconds(0.2));

		//To return and to move
		sf::Vector2f totalMovement(0,0);

		/*
		 * checking where to apply movement
		 */
		if(mIsMovingDown){
			totalMovement.y = movementSpeed;
			currentAnimation = &walkingAnimationDown;
			}
		else if(mIsMovingLeft){
			totalMovement.x = -movementSpeed;
			currentAnimation = &walkingAnimationLeft;
			}
		else if(mIsMovingRight){
			totalMovement.x = movementSpeed;
			currentAnimation = &walkingAnimationRight;
		}
		else if(mIsMovingUp){
			totalMovement.y = -movementSpeed;
			currentAnimation = &walkingAnimationUp;
		}


		animatedPlayer.play(*currentAnimation);

		if(totalMovement.x == 0 && totalMovement.y == 0){
			animatedPlayer.pause();
		}


		animatedPlayer.move(totalMovement  * elapsedTime.asSeconds());


		animatedPlayer.update(elapsedTime);

		lastMovement = totalMovement *elapsedTime.asSeconds();

        //One of these should be 0 and the other a value anyway, so can cheat a little and sum both
        mTravelled += abs(
                (int) ((totalMovement.x * elapsedTime.asSeconds()) + (totalMovement.y * elapsedTime.asSeconds())));


        mIsMoving = (bool) mTravelled;


		return totalMovement;
}

void Player::setupAnimation(sf::Texture &texture, int h, int w, std::vector<sf::Vector2f> leftMovements,
							std::vector<sf::Vector2f> rightMovements,
							std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements){



	for(int i = 0; i < leftMovements.size(); i++){
		walkingAnimationLeft.addFrame(sf::IntRect((int) leftMovements[i].x, (int) leftMovements[i].y, w, h));
	}
	walkingAnimationLeft.setSpriteSheet(texture);

	for(int i = 0; i < rightMovements.size(); i++){
		walkingAnimationRight.addFrame(sf::IntRect((int) rightMovements[i].x, (int) rightMovements[i].y, w, h));
	}
	walkingAnimationRight.setSpriteSheet(texture);

	for(int i = 0; i < upMovements.size(); i++){
		walkingAnimationUp.addFrame(sf::IntRect((int) upMovements[i].x, (int) upMovements[i].y, w, h));
	}
	walkingAnimationUp.setSpriteSheet(texture);

	for(int i = 0; i < downMovements.size(); i++){
		walkingAnimationDown.addFrame(sf::IntRect((int) downMovements[i].x, (int) downMovements[i].y, w, h));
	}
	walkingAnimationDown.setSpriteSheet(texture);


}

AnimatedSprite Player::getAnimatedPlayer(){

	return animatedPlayer;
}



Player::~Player() {
}

void Player::reverseLastMove() {

	animatedPlayer.move(lastMovement.x *-1, lastMovement.y*-1);

}
