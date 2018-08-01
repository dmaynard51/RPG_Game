#ifndef Corridor_hpp
#define Corridor_hpp
#include "Spaces.hpp"
#include "Items.hpp"
#include "Tiles.hpp"
#include "player.hpp"
#include "Door.hpp"
#include "TileWithItem.hpp"
#include "Walls.hpp"

#include <iostream>
#include <string>
using std::string;

class Corridor : public Spaces
{
	friend class Game;
private:

    
public:
    
	Corridor(player *player, string inputNameOfRoom);
	~Corridor();
	void getNameOfRoom();

	int moveLeftRoom();
	void setPlayerRight();
	Tiles *door;
	Tiles *wall;
    TileWithItem artifact;
	void printRoom();
	void movePlayer(player player);
	void findPlayerLocation(Tiles ***inputRoom, int rows, int columns);
	int spellCheck();

};

#endif
