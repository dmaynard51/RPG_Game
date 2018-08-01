//
//  Dungeon.hpp
//  finalproj
//
//  Created by Daniel Maynard on 8/13/17.
//  Copyright © 2017 Daniel Maynard. All rights reserved.
//

#ifndef Dungeon_hpp
#define Dungeon_hpp

#include "Door.hpp"
#include "Items.hpp"
#include "Tiles.hpp"
#include "player.hpp"
#include "TileWithItem.hpp"
#include "Spaces.hpp"
#include "Walls.hpp"


#include <iostream>
#include <string>
using std::string;

class Dungeon : public Spaces
{
    friend class Game;
private:
    
    
public:
    
    Dungeon(player *player, string inputNameOfRoom);
    ~Dungeon();
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

