/*
 * Player.cpp
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 *
 *  Currently loads a  sprite
 *
 */

#include "headers/Player.hpp"


Player::Player(sf::Vector2f gridSize, float tileSize) : Character(gridSize, tileSize) { Character(gridSize, tileSize);}


//is given the key that has been pressed and handles the input for it
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){

	//Needed to reset distance traveled
	if(isPressed && !mIsMoving){
		mTravelled = 0;
	}


    //if not already moving
    if(!mIsMoving || !isPressed){
        if(key == sf::Keyboard::W){
            if(mGridPos.y-1 >= 0){
                mIsMovingUp = isPressed;
                if(isPressed) mGridPos.y -= 1;}
			}
        else if(key == sf::Keyboard::S){
            if(mGridPos.y+1 < mGridSize.y){
                mIsMovingDown = isPressed;
                if(isPressed) mGridPos.y += 1;}
            }
        else if(key == sf::Keyboard::A){
            if(mGridPos.x-1 >= 0){
                mIsMovingLeft = isPressed;
			if(isPressed) mGridPos.x -= 1;}
        }
        else if(key == sf::Keyboard::D){
            if(mGridPos.x+1 < mGridSize.x) {
                mIsMovingRight = isPressed;
                if (isPressed) mGridPos.x += 1;}
        }
    }

}


Player::~Player() {
}




