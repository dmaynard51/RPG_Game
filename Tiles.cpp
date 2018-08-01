#include "Tiles.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*************************************
Description: Originally I left objects like health/attack/defense to allow for a fight, but running out of time 
I was unable to include the fight function.
*************************************/
Tiles::Tiles()
{
	this->tileType = '#';
	health = 0;
	attack = 0;
	defense = 0;

}


Tiles::~Tiles()
{
}

/*************************************
Description: Returns the type of icon displayed in the room. Ie. #, o, D
*************************************/
char Tiles::getTileType() const
{
	return this->tileType;
}


/*************************************
Description: Sets the type of the tile to be displayed in the room.
*************************************/
void Tiles::setTileType(char p)
{
	tileType = p;
}


/*************************************
Description: This constructor allows the name of the tile to be inputted.
*************************************/
Tiles::Tiles(Items name)
{

	itemOnFloor = name;
	
}


