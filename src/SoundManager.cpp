//
// Created by nathan on 25/05/16.
//

#include <iostream>
#include "headers/SoundManager.hpp"



void SoundManager::addTrack(std::string fileLocation) {


    //first check if track exists
    for(std::map<std::string, std::unique_ptr<sf::Music>>::const_iterator it =
            mCollection.begin(); it!=mCollection.end(); it++){

        if(fileLocation == it->first){
            std::cout << "File already exists in memory" << std::endl;
            //Could return here if getting
            break;
        }
    }

    //If still going then we know it hasn't been found
    //and can happily make it.
    auto ptr = std::make_unique<sf::Music>();

    if(ptr->openFromFile(fileLocation))
        mCollection[fileLocation] = std::move(ptr);
}


void SoundManager::playBackgroundMusic() {

    if(!isPlaying){
        mCollection["music/background01.wav"]->play();
        mCollection["music/background01.wav"]->setVolume(100);
        isPlaying = true;
    }

}

SoundManager::SoundManager():
isPlaying(false){

}















