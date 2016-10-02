/*
 * Game.h
 *
 *  Created on: 24 Mar 2015
 *      Author: nathan
 */

#include <SFML/Graphics.hpp>
#include <string.h>
#include "Player.hpp"
#include "tileMap.hpp"
#include "Pickups.hpp"
#include <stdlib.h>
#include <time.h>
#include "SoundManager.hpp"

#ifndef GAME_H_
#define GAME_H_
 
class Game {
public:
  Game();
  void run();



  //private functions
private:
  void update(sf::Time elapsedTime);
  void render();
  void processEvents();
  void handleCollisions();
  void updateFPSCounter(sf::Time dt);
  void setUpMap();
  void setUpPlayerMovements();
  void playSounds();


private:
  sf::RenderWindow gWindow;
  SoundManager gSounds;

  //Creating font
  sf::Font gAlexandriaFont;

  const int FRAMES_PER_SECOND;
  const sf::Time TIME_PER_FRAME;

  //gFps text object
  sf::Text gFps;
  sf::Time gFpsTimer;
  int gFpsNumFrames;

  int gGameState;
  enum states{INTRO = 0, PLAYING = 1, MENU = 2};

  sf::Texture gSplashScreenTexture;
  sf::Sprite gSplashScreenSprite;
  sf::Sprite gBackgroundSprite;
  sf::Texture gBackgroundTexture;

  tileMap gMap;
  Player gplayer;


};

#endif /* GAME_H_ */
