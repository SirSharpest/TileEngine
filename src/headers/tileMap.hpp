//
// Created by nathan on 15/03/16.
//

#ifndef SFML2_TILEMAP_H
#define SFML2_TILEMAP_H


#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class tileMap : public sf::Drawable, public sf::Transformable {

public:

    tileMap();

    void load(std::vector<int> tiles, int width, int height, std::string fileToLoad);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray quads;

    sf::Texture m_tileset;


};


#endif //SFML2_TILEMAP_H
