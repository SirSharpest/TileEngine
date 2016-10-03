//
// Created by nathan on 29/04/16.
//

#ifndef SFML2_MENU_HPP
#define SFML2_MENU_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


class Menu : public sf::Drawable{

private:

  //TODO: build a mutable list object 

public:

  /**
   * Setup the menu system
   */
  Menu();

  protected:
  
  /**
   * This is required when inheriting from the Drawable SFML class
   */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //SFML2_PICKUPS_HPP
