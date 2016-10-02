//
// Created by Nathan on 20/8/2016
//

/*
  Somewhat important distinction to make between a Monster
  and a character/NPC is that a monster is only available in 
  the battle system and in specific menus. They have no presence in the 
  over-world and so do not need movement and "proper" animations. 
 */

#ifndef SFML2_MONSTER_HPP
#define SFML2_MONSTER_HPP

#include <string>

class Monster{


public:

  /*
    Default constructor for a monster! 
   */ 
  Monster();

private:

  /*
    Monsters will all have to have attributes/stats 
    that is to say attack power, defence rating, etc! 
    
    To simplify the system we will say that u char 

    Also I'm leaving sp. att/def and some other vital stats
    for now... 
   */

  //  unsigned char mAttack, mDefence, mSpeed;
  
  //std::string mName;

  //TODO: Species will need to be defined as another class somehow
  //Mayhaps a class or enum(1-151) hardcoded to keep it safe?

  
};

#endif //SFML_MONSTER_HPP
