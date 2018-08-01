#include "Items.hpp"


/*************************************
Description: Item constructor if a username is entered.
*************************************/
Items::Items(string inputItemName)
{
    nameOfItem = inputItemName;
    strength = 0;
    
}


Items::~Items()
{
    
}

/*************************************
Description: Default item constructor with the item name of artifact.
*************************************/
Items::Items()
{
    nameOfItem = "artifact";
}

int Items::specialItemAbility()
{
    return 0;
}

/*************************************
Description: Returns the name of the item - which will be artifact.
*************************************/
string Items::getNameOfItem()
{
    return nameOfItem;
}
