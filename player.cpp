#include "player.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/*************************************
Description: Player constructor sets the tile type @, which will represent the player on the map.
 The player will have a bag of 5 items.
*************************************/
player::player()
{
	
	tileType = '@';
    
    bag = new Items*[5];
    for (int count = 0; count < 5; count++)
    {
        bag[count] = NULL;
    }
}


player::~player()
{
    
    
}


/*************************************
Description: prints items in the bag.
*************************************/
void player::printBag()
{
	for (int count = 0; count < 5; count++)
	{
		if (bag[count] == NULL)
		{
			cout <<  "Empty item slot" << endl;
		}

		else
		{
			cout << bag[count]->getNameOfItem() << endl;
		}

	}
}

/*************************************
Description: adds items to the bag.
*************************************/
void player::addToBag(Items *itemToBeAdded)
{
	for (int count = 0; count < 5; count++)
	{
		if (bag[count] == NULL)
		{
            
			bag[count] = itemToBeAdded; //add 1 item to items
            
			return;
		}
		else if (bag[count] != NULL)
		{
			//do nothing
		}
			

	}

	
}

/*************************************
Description: checks if the bag is empty. If the bag is full, then the game class will be notified
 that the player can pass the final door.
*************************************/
int player::isBagEmpty()
{
    bagCounter = 0;
    for (int count = 0; count < 5; count++)
    {
        if (bag[count] == NULL)
            bagCounter = bagCounter + 1;
    }
    return bagCounter;
}
