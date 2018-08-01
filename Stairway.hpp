//
//  Stairway.hpp
//  finalproj
//
//  Created by Daniel Maynard on 8/13/17.
//  Copyright © 2017 Daniel Maynard. All rights reserved.
//

#ifndef Stairway_hpp
#define Stairway_hpp
#include "Door.hpp"
#include "Spaces.hpp"
#include "TileWithItem.hpp"
#include "Items.hpp"
#include "Tiles.hpp"
#include "player.hpp"
#include "Walls.hpp"


#include <iostream>
#include <string>
using std::string;

class Stairway : public Spaces
{
    friend class Game;
private:
    
    
public:
    
    Stairway(player *player, string inputNameOfRoom);
    ~Stairway();
    void getNameOfRoom();
    int moveDownRoom();
    int moveUpRoom();
    void setPlayerDown();
    void setPlayerUp();
    Tiles *door;
    Tiles *wall;
    TileWithItem artifact;
	void printRoom();
    void movePlayer(player player);
	void findPlayerLocation(Tiles ***inputRoom, int rows, int columns);
	int spellCheck();
    
};

#endif
