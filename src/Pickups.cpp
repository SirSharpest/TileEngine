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
    this->m_sprite.setTexture(m_image);
    m_sprite.setScale(m_size);
}

void Pickups::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_image;

    // draw the vertex array
    target.draw(m_sprite, states);

}

sf::FloatRect Pickups::getBounds() {
    return sf::FloatRect(this->getPosition().x, this->getPosition().y, 10, 10);
}





