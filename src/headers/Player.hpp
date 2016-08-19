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
#include "Character.hpp"

class Player : public Character{
public:
  Player(sf::Vector2f gridSize, float tileSize);

  virtual ~Player();
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

#endif /* PLAYER_H_ */
