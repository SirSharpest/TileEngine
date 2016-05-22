//
// Created by nathan on 22/05/16.
//

#ifndef SFML2_CHARACTER_H
#define SFML2_CHARACTER_H

#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>



class Character {

public:

    Character(sf::Vector2f gridSize, float tileSize);
    void setUp(std::string fileLocation, int h, int w, std::vector<sf::Vector2f> leftMovements,
               std::vector<sf::Vector2f> rightMovements,
               std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements);
    void updateCharacter(sf::Time elapsedTime);
    void setupAnimation(sf::Texture &texture, int h, int w, std::vector<sf::Vector2f> leftMovements,
                        std::vector<sf::Vector2f> rightMovements,
                        std::vector<sf::Vector2f> upMovements, std::vector<sf::Vector2f> downMovements);
    AnimatedSprite getAnimatedPlayer();

    sf::Vector2f* getPosition();


private:

    //properties of the player
    float mSpeed, mTileSize, mTravelled;
    sf::Vector2f movement;
    sf::Vector2f mSize;

    //movement flags
    bool mIsMovingUp, mIsMovingDown,
            mIsMovingLeft, mIsMovingRight,
            mIsTurbo, mIsMoving;

    sf::Texture characterSprite;

    Animation walkingAnimationDown, walkingAnimationLeft,
            walkingAnimationRight, walkingAnimationUp;

    Animation* currentAnimation;

    AnimatedSprite animatedPlayer;

    sf::Vector2f mGridPos;

    sf::Vector2f mGridSize;







};


#endif //SFML2_CHARACTER_H
