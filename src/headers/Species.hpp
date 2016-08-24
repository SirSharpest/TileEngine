//
// Created by Nathan on 24/8/2016
//

#ifndef SFML2_SPECIES_HPP
#define SFML2_SPECIES_HPP

#include <string>

class Species{


public:

  /*
    Default constructor for a species 
   */ 
  Species();

private:

  // Each species will need a unique name (checking done at a higher level though) 
  std::string mName;

  /* A monster of a specific species will also have max/min thresholds for potential
     Power, I think this could be a % based modifier
     
     e.g. a pikachu of attack 100 would have a modifier of 10% so it's battle power = 110
          a Mewtwo of attack 100 would have a modifier of 50% so it's battle power = 150
  */
  unsigned char mModifier; 
  
  //Type t = x
  //evolveStage = {0-3} this as an enum of this range
  // ^^ this needs to be a thing!


  
};

#endif //SFML_SPECIES_HPP
