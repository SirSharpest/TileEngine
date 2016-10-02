//
// Created by nathan on 29/04/16.
//

#ifndef SFML2_PICKUPS_HPP
#define SFML2_PICKUPS_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


class Pickups : public sf::Sprite{

private:
  sf::Texture m_image;
  sf::Vector2f m_position, m_size;
  //  int m_posX, posY;


public:

  /**
   * Setup the initial pickup
   * Takes the XY location of an image file and then the size on the sprite sheet itself and loads it into memory
   */
  Pickups();

  void setup(sf::Texture &image);



};


#endif //SFML2_PICKUPS_HPP
