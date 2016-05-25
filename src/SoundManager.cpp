//
// Created by nathan on 25/05/16.
//

#include <iostream>
#include "headers/SoundManager.hpp"



void SoundManager::addTrack(std::string fileLocation) {

    auto ptr = std::make_unique<sf::Music>();

    if(ptr->openFromFile(fileLocation))
        mCollection.push_back(std::move(ptr));
    else
        std::cout << "Error loading music file: " << fileLocation;

}


void SoundManager::playBackgroundMusic() {

    if(!isPlaying){
        mCollection[0]->setVolume(100);
        mCollection[0]->play();
        isPlaying = true;
    }

}

SoundManager::SoundManager():
isPlaying(false){

}















