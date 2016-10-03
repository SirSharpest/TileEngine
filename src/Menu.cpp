//
// Created by Nathan on 3/10/2016
//

#include "headers/Menu.hpp"

Menu::Menu(){

}

void addItem(std::string menuItem);
std::string getItem(); 


void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const{


  // draw the vertex array
  target.draw(gMenuItems.front(), states);  
  
}
