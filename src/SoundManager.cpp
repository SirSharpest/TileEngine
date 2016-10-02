//
// Created by nathan on 25/05/16.
//

#include <iostream>
#include "headers/SoundManager.hpp"



void SoundManager::addTrack(std::string fileLocation) {


  //Check if file already is loaded
  if(exists(fileLocation))
    return;

  //If still going then we know it hasn't been found
  //and can happily make it.
  auto ptr = std::make_unique<sf::Music>();

  if(ptr->openFromFile(fileLocation))
    mCollection[fileLocation] = std::move(ptr);
}


void SoundManager::playBackgroundMusic() {

  if(mCollection["music/background01.wav"]->getStatus() != sf::Music::Playing){
    mCollection["music/background01.wav"]->play();
    mCollection["music/background01.wav"]->setVolume(100);
  }
}


bool SoundManager::exists(std::string fileLocation) {
  //first check if track exists
  for(std::map<std::string, std::unique_ptr<sf::Music>>::const_iterator it =
        mCollection.begin(); it!=mCollection.end(); ++it){

    if(fileLocation == it->first){
      std::cout << "File already exists in memory" << std::endl;
      return true;
    }
  }
  return false;
}

void SoundManager::stopMusic() {

  //Stop all music

  for(std::map<std::string, std::unique_ptr<sf::Music>>::const_iterator it =
        mCollection.begin(); it!=mCollection.end(); ++it) {
    if(it->second->getStatus() == sf::Music::Playing){
      it->second->pause();
    }
  }

}
