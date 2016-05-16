//
// Created by nathan on 29/04/16.
//

#include "Pickups.hpp"

Pickups::Pickups(){
}


void Pickups::setup(sf::Texture &image){

    //Set the defaults
    this->m_image = image;
    image.setSmooth(true);
    m_size = sf::Vector2f(1,1);
    this->setTexture(m_image);
    this->setScale(m_size);
}









