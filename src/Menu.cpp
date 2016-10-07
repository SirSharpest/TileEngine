//
// Created by Nathan on 3/10/2016
//

#include "headers/Menu.hpp"

Menu::Menu():
  gMenuItems(),
  gMenuFontPtr(),
  MENU_SPACING(100),
  gMenuView(sf::FloatRect(0, 0, 640, 640)){

}


void Menu::addItem(std::string menuItem){

  // Set up the properties for the text being added 
  sf::Text tmpText;
  tmpText.setFont(*gMenuFontPtr);
  tmpText.setString(menuItem);
  // Set the spacing between each menu item ... should really be consts 
  tmpText.setPosition(50.0, float(50+(gMenuItems.size()*MENU_SPACING)));
  // I've used magenta for now as IT IS HORRIBLE and stands out
  tmpText.setFillColor(sf::Color::Magenta);
  gMenuItems.push_back(tmpText);
  

}

void Menu::setMenuFont(sf::Font *fontPtr){

  gMenuFontPtr = fontPtr; 
}

std::string Menu::getItem(){
  return ""; 
}

void Menu::handleMenuInput(sf::Keyboard::Key key, bool isPressed){

  //place holder
  

}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const{

  // Set the view correctly
  target.setView(gMenuView);
  
  // draw the menu item list
  for (auto  &item : gMenuItems){
    target.draw(item, states);
  }
  
}
