//
// Created by nathan on 29/04/16.
//

#ifndef SFML2_MENU_HPP
#define SFML2_MENU_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

class Menu : public sf::Drawable{
  
private:

  // This vector contains all of the menu items 
  std::vector<sf::Text> gMenuItems; 
  sf::Font * gMenuFontPtr;
  const unsigned int MENU_SPACING; 
public:

  /**
   * Setup the menu system
   */
  Menu();

  /**
   * Setters, getters for menu items 
   */
  void addItem(std::string menuItem);
  void setMenuFont(sf::Font *fontPtr);
  std::string getItem(); 

protected:

  /**
   * This is required when inheriting from the Drawable SFML class
   */
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


#endif //SFML2_PICKUPS_HPP
