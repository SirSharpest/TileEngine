//
// Created by nathan on 29/04/16.
//

#include "Pickups.hpp"

Pickups::Pickups(sf::Texture image, sf::Vector2f size) {

    //Set the defaults
    this->m_image = image;
    image.setSmooth(true);
    m_size = size;
    this->m_sprite.setTexture(image);
    m_sprite.setScale(m_size);
}


Pickups::Pickups(sf::Texture image) {

    //Set the defaults
    this->m_image = image;
    image.setSmooth(true);
    m_size = sf::Vector2f(1,1);
    this->m_sprite.setTexture(image);
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



