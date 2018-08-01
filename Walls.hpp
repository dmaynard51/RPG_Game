
#ifndef Walls_hpp
#define Walls_hpp
#include "Tiles.hpp"
#include "Items.hpp"

class Walls : public Tiles
{

    
public:
    Walls();
    ~Walls();
    //void pickUpItem(Tiles itemOnFloor, Tiles player);
    char getWallType();
	char getTileType();
};


#endif /* TileWithItem_hpp */
