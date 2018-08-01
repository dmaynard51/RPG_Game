#pragma once
#include "Tiles.hpp"
#include "Items.hpp"
class player : public Tiles
{
private:
    
public:
	player();
	~player();
	//void pickUpItem(Tiles itemOnFloor, Tiles player);
    void printBag();
	void addToBag(Items *itemToBeAdded);
    Items **bag;
    
    int isBagEmpty();
    int bagCounter;
    
};

