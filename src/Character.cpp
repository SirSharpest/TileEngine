//
// Created by nathan on 22/05/16.
//

#include "Character.hpp"

Character::Character(sf::Vector2f gridSize, float tileSize):
        mSpeed(300.f),
        mTileSize(tileSize),
        mTravelled(0),
        movement(0.f, 0.f),
        mSize(1,1),
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
        mGridPos(0,0),
        mGridSize(gridSize){

}

void Character::setUp(std::string fileLocation, int h, int w, std::vector<sf::Vector2f> leftMovements,
                      std::vector<sf::Vector2f> rightMovements, std::vector<sf::Vector2f> upMovements,
                      std::vector<sf::Vector2f> downMovements) {

    characterSprite.loadFromFile(fileLocation);

    //apply animations to image
    setupAnimation(characterSprite, h ,w , leftMovements, rightMovements, upMovements, downMovements);

    //Increasing the size of the image
    animatedPlayer.setScale(mSize);
    //animated sprite properties
    //default values for now
    animatedPlayer.setPosition(0, 0);

}

void Character::updateCharacter(sf::Time elapsedTime) {



    //To return and to move
    sf::Vector2f totalMovement(0,0);

    /*
     * checking where to apply movement
     */
    if(mIsMovingDown){
        totalMovement.y = mSpeed;
        currentAnimation = &walkingAnimationDown;
        mIsMoving = true;
    }
    else if(mIsMovingLeft){
        totalMovement.x = -mSpeed;
        currentAnimation = &walkingAnimationLeft;
        mIsMoving = true;
    }
    else if(mIsMovingRight){
        totalMovement.x = mSpeed;
        currentAnimation = &walkingAnimationRight;
        mIsMoving = true;
    }
    else if(mIsMovingUp){
        totalMovement.y = -mSpeed;
        currentAnimation = &walkingAnimationUp;
        mIsMoving = true;
    }else{
        mIsMoving = false;
    }


    animatedPlayer.play(*currentAnimation);

    if(totalMovement.x == 0 && totalMovement.y == 0){
        animatedPlayer.pause();
    }


    animatedPlayer.move(totalMovement  * elapsedTime.asSeconds());

    animatedPlayer.update(elapsedTime);

    //One of these should be 0 and the other a value anyway, so can cheat a little and sum both
    mTravelled += abs(
            (int) ((totalMovement.x * elapsedTime.asSeconds()) + (totalMovement.y * elapsedTime.asSeconds())));



    //Correct movement if past destination
    //And turn movement off.
    if(mTravelled >= mTileSize && mIsMoving){

        animatedPlayer.setPosition(mGridPos.x * 64, mGridPos.y * 64);

        mIsMovingDown = false;
        mIsMovingUp = false;
        mIsMovingRight = false;
        mIsMovingLeft = false;
        mIsMoving = false;

    }





}

void Character::setupAnimation(sf::Texture &texture, int h, int w, std::vector<sf::Vector2f> leftMovements,
                               std::vector<sf::Vector2f> rightMovements, std::vector<sf::Vector2f> upMovements,
                               std::vector<sf::Vector2f> downMovements) {




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

    animatedPlayer.setFrameTime(sf::seconds(0.1));





}

AnimatedSprite Character::getAnimatedPlayer() {
    return animatedPlayer;
}

sf::Vector2f *Character::getPosition() {
    return &mGridPos;
}











