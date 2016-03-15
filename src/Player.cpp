/*
 * Player.cpp
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 *
 *  Currently loads a wizard sprite
 *
 */

#include "Player.hpp"
#include "AnimatedSprite.hpp"

Player::Player():
        mSpeed(200.f),
        movement(0.f, 0.f),
        mSize(1,1),
        mPosX(0),
        mPosY(0),
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
	animatedPlayer.setPosition(mPosX, mPosY);



}

//is given the key that has been pressed and handles the input for it
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){


	if(key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if(key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if(key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if(key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
	else if (key == sf::Keyboard::Space)
		mIsTurbo = isPressed;



}


//perform movement for the player
sf::Vector2f Player::updatePlayer(sf::Time elapsedTime) {



		//reset speed of movement and animation
		float movementSpeed = mSpeed;
		animatedPlayer.setFrameTime(sf::seconds(0.2));

		//To return and to move
		sf::Vector2f totalMovement(0,0);

		/*
		 * checking where to apply movement
		 */
		if(mIsTurbo){
			movementSpeed = mSpeed * 5;
			animatedPlayer.setFrameTime(sf::seconds(0.04));
		}



		if(mIsMovingDown){
			totalMovement.y = movementSpeed;
			currentAnimation = &walkingAnimationDown;
			}
		if(mIsMovingLeft){
			totalMovement.x = -movementSpeed;
			currentAnimation = &walkingAnimationLeft;
			}
		if(mIsMovingRight){
			totalMovement.x = movementSpeed;
			currentAnimation = &walkingAnimationRight;
		}
		if(mIsMovingUp){
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
		return totalMovement;
}

void Player::setupAnimation(sf::Texture &texture, int h, int w, std::vector<sf::Vector2f> leftMovements, std::vector<sf::Vector2f> rightMovements,
							std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements){



	for(int i = 0; i < leftMovements.size(); i++){
		walkingAnimationLeft.addFrame(sf::IntRect(leftMovements[i].x, leftMovements[i].y, w, h));
	}
	walkingAnimationLeft.setSpriteSheet(texture);

	for(int i = 0; i < rightMovements.size(); i++){
		walkingAnimationRight.addFrame(sf::IntRect(rightMovements[i].x, rightMovements[i].y, w, h));
	}
	walkingAnimationRight.setSpriteSheet(texture);

	for(int i = 0; i < upMovements.size(); i++){
		walkingAnimationUp.addFrame(sf::IntRect(upMovements[i].x, upMovements[i].y, w, h));
	}
	walkingAnimationUp.setSpriteSheet(texture);

	for(int i = 0; i < downMovements.size(); i++){
		walkingAnimationDown.addFrame(sf::IntRect(downMovements[i].x, downMovements[i].y, w, h));
	}
	walkingAnimationDown.setSpriteSheet(texture);


}

AnimatedSprite Player::getAnimatedPlayer(){

	return animatedPlayer;
}



Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::reverseLastMove() {

	animatedPlayer.move(lastMovement.x *-1, lastMovement.y*-1);

}
