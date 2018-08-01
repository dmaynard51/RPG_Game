#pragma once
#include "Door.hpp"
#include "Spaces.hpp"
#include "TileWithItem.hpp"
#include "Items.hpp"
#include "Tiles.hpp"
#include "player.hpp"
#include "Walls.hpp"
class Library : public Spaces
{
	friend class Game;
private:

    
public:
    
	Library(player *player, string inputNameOfRoom);
	~Library();

	void getNameOfRoom();
	int moveRightRoom();
    int moveUpRoom();
    
    
	void setPlayerLeft();
    void setPlayerDown();
	Tiles *door;
    Tiles *wall;
    TileWithItem artifact;
		void printRoom();
	void movePlayer(player player);
	void findPlayerLocation(Tiles ***inputRoom, int rows, int columns);
	int spellCheck();
};



