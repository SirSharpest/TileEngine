/*
 * Game.cpp
 *
 *  Created on: 24 Mar 2015
 *      Author: Nathan Hughes
 */

#include "headers/Game.hpp"
#include <iostream>
#include <sstream>

Game::Game():
  gWindow(sf::VideoMode(640, 640), "SFML"),
  gSounds(),
  gAlexandriaFont(),
  FRAMES_PER_SECOND(60),
  TIME_PER_FRAME(sf::seconds(1.f/FRAMES_PER_SECOND)),
  gFps(),
  gFpsTimer(),
  gFpsNumFrames(),
  gGameState(0),
  gSplashScreenTexture(),
  gSplashScreenSprite(),
  gBackgroundSprite(),
  gBackgroundTexture(),
  gMap(),
  gplayer(sf::Vector2f(10,10), 64.f),
  gScoreText(),
  gScore(0)
{
  //setting window properties
  gWindow.setVerticalSyncEnabled(true);
  gWindow.setFramerateLimit(FRAMES_PER_SECOND);
  
  //setting font location
  gAlexandriaFont.loadFromFile("fonts/AlexandriaFLF.ttf");

  //loading splash screen
  gSplashScreenTexture.loadFromFile("images/intro.png");
  gSplashScreenSprite.setTexture(gSplashScreenTexture);
  gSplashScreenSprite.setPosition(0.f,0.f);

  //setting gFps info
  gFps.setCharacterSize(20);
  gFps.setFont(gAlexandriaFont);
  gFps.setPosition(0,0);

  //setting the score info
  gScoreText.setFont(gAlexandriaFont);
  gScoreText.setPosition(220,150);
  gScoreText.setScale(10,10);
  gScoreText.setString("0");


  //Set up some of the finner details of the game
  setUpMap();
  setUpPlayerMovements();

  //Perform some sound loading
  //TODO formalize and make nice to work with
  gSounds.addTrack("music/background01.wav");

  /* initialize random seed: */
  srand ((unsigned int) time(NULL));

}


void Game::run(){

  //clocks and times used to get custom game loop working
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  //setting gGameState to be intro on run
  gGameState = 0;

  //main loop to run the entire length of games
  //life
  while (gWindow.isOpen()) {
    sf::Time dt = clock.restart();
    timeSinceLastUpdate += dt;


    while(timeSinceLastUpdate > TIME_PER_FRAME) {

      timeSinceLastUpdate -= TIME_PER_FRAME;
      processEvents();
      update(dt);
    }
    updateFPSCounter(dt);
    playSounds();
    render();
  }
}



//process input events
void Game::processEvents(){

  sf::Event event;

  while(gWindow.pollEvent(event)){


    if(event.type == sf::Event::Closed)
      gWindow.close();

    if(gGameState == INTRO){
      if(event.key.code == sf::Keyboard::Space){
        gGameState = PLAYING;
      }
    }

    if(gGameState == PLAYING){

      if(event.key.code == sf::Keyboard::Escape)
        gGameState = INTRO;

      //Handle a key being pressed
      if(event.type == sf::Event::KeyPressed){
        gplayer.handlePlayerInput(event.key.code, true);
      }

    }

  }

}

//perform logic and call for collision checks
void Game::update(sf::Time elapsedTime){


  handleCollisions();
  gplayer.updateCharacter(elapsedTime);

}


//Put all the collision checking and handling here
void Game::handleCollisions(){

  /*
   * TODO: Add some
   */
}


void Game::updateFPSCounter(sf::Time dt){

  gFpsTimer += dt;
  gFpsNumFrames += 1;

  if( gFpsTimer >= sf::seconds(1.0f)){

    std::ostringstream ss;

    ss << gFpsNumFrames;
    gFps.setString(ss.str());

    gFpsTimer -= sf::seconds(1.0f);
    gFpsNumFrames = 0;
  }

}

//re-apply changes to window
void Game::render(){

  //wipe window clear
  gWindow.clear(sf::Color::Black);

  switch (gGameState) {
  case INTRO:
    //draw splash screen
    gWindow.draw(gSplashScreenSprite);
    break;
  case PLAYING:
    gWindow.draw(gMap);
    gWindow.draw(gplayer);
    break;
  default:
    break;
  }

  //display new screen layout
  gWindow.draw(gFps);
  gWindow.display();


}


void Game::playSounds() {
  switch (gGameState){

  case INTRO:
    gSounds.stopMusic();
    break;
  case PLAYING:
    gSounds.playBackgroundMusic();
    break;
  default:
    break;

  }
}

void Game::setUpPlayerMovements() {

  //setup the player
  std::string character = "images/char.png";

  std::vector<sf::Vector2f> leftMovements, rightMovements, downMovements, upMovements;

  leftMovements.push_back(sf::Vector2f(0, 62));
  leftMovements.push_back(sf::Vector2f(62, 62));
  leftMovements.push_back(sf::Vector2f(124, 62));
  leftMovements.push_back(sf::Vector2f(186, 62));

  rightMovements.push_back(sf::Vector2f(0, 124));
  rightMovements.push_back(sf::Vector2f(62, 124));
  rightMovements.push_back(sf::Vector2f(124, 124));
  rightMovements.push_back(sf::Vector2f(186, 124));

  upMovements.push_back(sf::Vector2f(0, 186));
  upMovements.push_back(sf::Vector2f(62, 186));
  upMovements.push_back(sf::Vector2f(124, 186));
  upMovements.push_back(sf::Vector2f(186, 186));

  downMovements.push_back(sf::Vector2f(0, 0));
  downMovements.push_back(sf::Vector2f(62, 0));
  downMovements.push_back(sf::Vector2f(124, 0));
  downMovements.push_back(sf::Vector2f(186, 0));

  gplayer.setUp(character,62, 62, leftMovements, rightMovements, upMovements, downMovements);


}

void Game::setUpMap() {

  std::vector<int> myVec;

  for(int i = 0; i < 10; i++){

    for(int j = 0; j < 10; j++){
      myVec.push_back(44);
    }
    
  }

  //10x10
  gMap.load(myVec, 10, 10, "images/spriteSheet.png");

}

