

#include "Walls.hpp"


/*************************************
Description: The tile type is | indicating a wall.
*************************************/
Walls::Walls()
{
    tileType = '|';

    
}

Walls::~Walls()
{

}

/*************************************
Description: used for the print function and move function - which contain rules that the player
 can't walk over walls.
*************************************/
char Walls::getWallType()
{
	return tileType;
}
