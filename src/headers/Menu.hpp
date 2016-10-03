//
// Created by nathan on 29/04/16.
//

#ifndef SFML2_MENU_HPP
#define SFML2_MENU_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>


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
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


#endif //SFML2_PICKUPS_HPP
