
#include "TileWithItem.hpp"

/*************************************
Description: Default constructor sets the tile type of 'o' and this tile will contain an item
*************************************/
TileWithItem::TileWithItem()
{
    tileType = 'o';
    artifact = Items();   
}

TileWithItem::~TileWithItem()
{

}
