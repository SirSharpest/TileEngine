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
mIsMoving(true),
mIsOnGround(false),
mMayJumpAgain(false),
characterSprite(),
walkingAnimationDown(),
walkingAnimationLeft(),
walkingAnimationRight(),
walkingAnimationUp(),
currentAnimation(&walkingAnimationRight),
animatedPlayer(sf::seconds(0.2), true, false){



	//load sprite's texture
	characterSprite.loadFromFile("images/mageCharacter.png");


	//apply animations to image
	setupAnimation(characterSprite);
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
sf::Vector2f Player::updatePlayer(sf::Time elapsedTime, int groundHeight){



		//reset speed of movement and animation
		float movementSpeed = mSpeed;
		animatedPlayer.setFrameTime(sf::seconds(0.2));
		int playerHeight = 70;

		groundHeight -= playerHeight;



		//To return
		sf::Vector2f totalMovement(0,0);

		/*
		 * checking where to apply movement
		 */
		if(mIsTurbo){
			movementSpeed = mSpeed * 5;
			animatedPlayer.setFrameTime(sf::seconds(0.04));}

		if(animatedPlayer.getPosition().y >= groundHeight){
			mIsOnGround = true;
		}
		else if (animatedPlayer.getPosition().y < groundHeight){
			mIsOnGround = false;
		}


		//https://wiki.allegro.cc/index.php?title=How_to_implement_jumping_in_platformers
		//get this sorted for jump mechanic
		if(mIsOnGround){
			if(mIsMovingUp){

				if(mMayJumpAgain){

					movement.y += - (movementSpeed * 15);
					mMayJumpAgain = false;


				}
				else{
					mMayJumpAgain = true;
				}

				}
		}

		//really should be slightly different
		//left in for debugging and testing
		//TODO: find better solution
		if(mIsMovingDown){
			movement.y = movementSpeed;
			}
		if(mIsMovingLeft){
			movement.x = -movementSpeed;
			}
		if(mIsMovingRight){
			movement.x = movementSpeed;
			currentAnimation = &walkingAnimationRight;}



		if(mIsMovingUp && !mIsOnGround){
			movement.y += movementSpeed;
		}

			animatedPlayer.play(*currentAnimation);

			if(movement.x == 0 && movement.y == 0){
				animatedPlayer.pause();
			}


		//test here for an idea for gravity
		//TODO Fix this up and make usable
		//80 is the players height
		if(animatedPlayer.getPosition().y < groundHeight){
			movement.y += movementSpeed  ;
			if(movement.y > (movementSpeed * 3 )){
				movement.y = movementSpeed * 3;
			}
		}

		//bug here for if moving up or down, then this wont reset
		//meaning that we can clip and drop further than screen
		if(!mIsMovingUp && mIsOnGround){
			movement.y = 0;
		}
		if(!mIsMovingLeft && !mIsMovingRight){
			movement.x = 0;
		}

			animatedPlayer.move(movement * elapsedTime.asSeconds());
			animatedPlayer.update(elapsedTime);



			totalMovement.x += movement.x * elapsedTime.asSeconds();

			return totalMovement;
}

void Player::setupAnimation(sf::Texture &texture){



    walkingAnimationRight.addFrame(sf::IntRect(42, 108, 45, 67));
    walkingAnimationRight.addFrame(sf::IntRect(124, 108, 45, 67));
    walkingAnimationRight.addFrame(sf::IntRect(207, 108, 45, 67));
    walkingAnimationRight.addFrame(sf::IntRect(285, 108, 45, 67));
    walkingAnimationRight.setSpriteSheet(texture);


}

AnimatedSprite Player::getAnimatedPlayer(){

	return animatedPlayer;
}



Player::~Player() {
	// TODO Auto-generated destructor stub
}

