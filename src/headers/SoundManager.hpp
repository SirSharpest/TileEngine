//
// Created by nathan on 25/05/16.
//

#ifndef SFML2_SOUNDMANAGER_HPP
#define SFML2_SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>
#include <algorithm>


class SoundManager {


public:

    /*
     * Empty for now
     */
    SoundManager();

    /*
     * Adds a track to the music collection container
     */
    void addTrack(std::string fileLocation);

    void playBackgroundMusic();


private:


    //Collection of music loaded currently in memory
    std::vector<std::unique_ptr<sf::Music>> mCollection;
    bool isPlaying;
};


#endif //SFML2_SOUNDMANAGER_HPP
