#pragma once
#include "Items.hpp"

class Tiles
{
	friend class Game;
	friend class Spaces;
protected:
	int attack;
	int defense;
	int armor;
	int health;
    
private:
	
    

public:
	Tiles();
    Tiles(Items name);
	char tileType;
    virtual ~Tiles() = 0;
	char getTileType() const;
	void setTileType(char p);

    Items itemOnFloor;
    
};

