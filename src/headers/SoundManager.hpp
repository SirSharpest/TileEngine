//
// Created by nathan on 25/05/16.
//

#ifndef SFML2_SOUNDMANAGER_HPP
#define SFML2_SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>
#include <algorithm>
#include <map>


class SoundManager {


public:

  /*
   * Pauses/stops all music from playing
   */
  void stopMusic();

  /*
   * Adds a track to the music collection container
   */
  void addTrack(std::string fileLocation);

  /*
   * Check if track by name already exists in container
   */
  bool exists(std::string fileLocation);

  /*
   * Plays the background music
   */
  void playBackgroundMusic();


private:

  //Collection of music loaded currently in memory
  std::map<std::string, std::unique_ptr<sf::Music>> mCollection;

};


#endif //SFML2_SOUNDMANAGER_HPP
