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
  sf::RenderWindow g_Window;
  SoundManager g_Sounds;

  //Creating font
  sf::Font g_AlexandriaFont;

  const int FRAMES_PER_SECOND;
  const sf::Time TIME_PER_FRAME;

  //g_Fps text object
  sf::Text g_Fps;
  sf::Time g_FpsTimer;
  int g_FpsNumFrames;

  int g_GameState;
  enum states{INTRO = 0, PLAYING = 1};

  sf::Texture g_SplashScreenTexture;
  sf::Sprite g_SplashScreenSprite;
  sf::Sprite g_BackgroundSprite;
  sf::Texture g_BackgroundTexture;

  tileMap g_Map;
  Player g_player;

  sf::Text g_scoreText;
  u_int g_score;


};

#endif /* GAME_H_ */
