//
// Created by nathan on 15/03/16.
//

#include "headers/tileMap.hpp"


tileMap::tileMap() {

}

void tileMap::load(std::vector<int> tiles, int width, int height, std::string fileToLoad){

    quads.setPrimitiveType(sf::Quads); //Set as a type quads

    quads.resize((size_t) (width * height * 4));

    int tileSize = 64;

    //Load the texture into memory
    if(!m_tileset.loadFromFile(fileToLoad))
        return;


    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &quads[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
            quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
            quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
            quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
            quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
        }

}

void tileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(quads, states);
}
