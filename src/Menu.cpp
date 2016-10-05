//
// Created by Nathan on 3/10/2016
//

#include "headers/Menu.hpp"

Menu::Menu():
  gMenuItems(),
  gMenuFontPtr(),
  MENU_SPACING(100){

}



void Menu::addItem(std::string menuItem){

  sf::Text tmpText;
  tmpText.setFont(*gMenuFontPtr);
  tmpText.setString(menuItem);
  tmpText.setPosition(50, 50+(gMenuItems.size()*MENU_SPACING));
  tmpText.setFillColor(sf::Color::Magenta);
  gMenuItems.push_back(tmpText);

}

void Menu::setMenuFont(sf::Font *fontPtr){

  gMenuFontPtr = fontPtr; 
}

std::string getItem(); 


void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const{


  // draw the menu item list
  for (auto  &item : gMenuItems){
    target.draw(item, states);
  }
   
}
