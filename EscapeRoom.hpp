//
//  EscapeRoom.hpp
//  finalproj
//
//  Created by Daniel Maynard on 8/14/17.
//  Copyright © 2017 Daniel Maynard. All rights reserved.
//

#ifndef EscapeRoom_hpp
#define EscapeRoom_hpp


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

class EscapeRoom : public Spaces
{
    friend class Game;
private:
    
    
public:
    
    EscapeRoom(player *player, string inputNameOfRoom);
    ~EscapeRoom();
    void getNameOfRoom();
    int moveDownRoom();
    
    
    void setPlayerUp();
    Tiles *door;
    Tiles *wall;
    TileWithItem artifact;
    void printRoom();
    void movePlayer(player player);
    void findPlayerLocation(Tiles ***inputRoom, int rows, int columns);
    int winCheck();
    
};



#endif /* EscapeRoom_hpp */
