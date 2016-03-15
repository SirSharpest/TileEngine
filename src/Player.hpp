/*
 * Player.h
 *
 *  Created on: 2 Apr 2015
 *      Author: nathan
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

class Player {
public:
	Player();
	void setUp(std::string fileLocation, int h, int w, std::vector<sf::Vector2f> leftMovements, std::vector<sf::Vector2f> rightMovements,
			   std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements);
	virtual ~Player();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	sf::Vector2f updatePlayer(sf::Time elapsedTime);
	void setupAnimation(sf::Texture &texture, int h, int w, std::vector<sf::Vector2f> leftMovements, std::vector<sf::Vector2f> rightMovements,
						std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements);
	AnimatedSprite getAnimatedPlayer();


private:

	//properties of the player
	float mSpeed;
	sf::Vector2f movement;
	sf::Vector2f mSize;
	int mPosX;
	int mPosY;
	sf::Color mColor;

	//movement flags for player
	bool mIsMovingUp, mIsMovingDown,
	mIsMovingLeft, mIsMovingRight,
	mIsTurbo, mIsMoving;

	sf::Texture characterSprite;

	Animation walkingAnimationDown, walkingAnimationLeft,
			walkingAnimationRight, walkingAnimationUp;

	Animation* currentAnimation;

	AnimatedSprite animatedPlayer;

};

#endif /* PLAYER_H_ */
