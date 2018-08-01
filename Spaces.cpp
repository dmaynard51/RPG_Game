/******************************************
Name: Daniel Maynard
Assignment: Final Project
Description: This game contains 6 spaces, 5 of which have items and the last one has a door, and it order to 
get passed it all the artifacts in the 5 spaces must be collected. Furthermore each space has a door to go 
to the next space, but in order to unlock it, an unlock door spell must be cast (7).
Date: 8/15/17
******************************************/

#include "Spaces.hpp"
#include "Items.hpp"
#include "TileWithItem.hpp"
#include <iostream>
#include <limits>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

/*************************************
Description: Sets up each space with an 8x8 array. Also contains the 4 pointers, up, down, left, right. Each space
will then extend's the double pointer into a 2d array of NULL pointers, allocating walls/items by its own "space"
*************************************/
Spaces::Spaces(player *player, string inputNameOfRoom)
{
    rows = 8;
    columns = 8;
	rooms = new Tiles**[rows];
    player1 = NULL;
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    currentRowOfPlayer = 2;
    currentColumnOfPlayer = 2;
    player1 = player;
    
    
}

/*************************************
Description: This deconstructor will be virtual, each space will delete its own array 
*************************************/
Spaces::~Spaces()
{
	

    

    
}

/*************************************
Description:The following functions will be used its own individual spaces since they will have their own map.
*************************************/
void Spaces::getNameOfRoom()
{
    
}

void Spaces::printRoom() 
{

}

void Spaces::movePlayer(player player)
{
  
}

void Spaces::findPlayerLocation(Tiles ***inputRoom, int rows, int columns)
{

}


int Spaces::moveLeftRoom()
{

    return 0;
}

int Spaces::moveRightRoom()
{

    return 0;
}

int Spaces::moveUpRoom()
{
    return 0;
}


int Spaces::moveDownRoom()
{
    return 0;
}


/*************************************
Description:the setter/getter will be the same throughout each space, so these functions will be called from the Game class to set
and get the up/down/left/right rooms.
*************************************/
void Spaces::setLeft(Spaces *room)
{
	this->left = room;
}

void Spaces::setRight(Spaces *room)
{
	this->right = room;
}

void Spaces::setDown(Spaces *room)
{
    this->down = room;
}

void Spaces::setUp(Spaces *room)
{
    this->up = room;
}


Spaces* Spaces::getLeft()
{
	return this->left;
}

Spaces* Spaces::getRight()
{
	return this->right;
}

Spaces* Spaces::getDown()
{
    return this->down;
}

Spaces* Spaces::getUp()
{
    return this->up;
}

/*************************************
Description:the specific location of the player will depend on the space they are in, so for example if they are in the "Corridor",
the set player left function will change depending on the space to the left of "Corridor"
*************************************/
void Spaces::setPlayerLeft()
{
	

}

void Spaces::setPlayerRight()
{
	

}


void Spaces::setPlayerUp()
{
    
    
}


void Spaces::setPlayerDown()
{
    
    
}


void Spaces::pickUpItem()
{

}
int Spaces::winCheck()
{
    return 0;
}

/*************************************
Description: This is the virtual function that will be used to check each room if the player used an unlock spell on the door.
*************************************/
int Spaces::spellCheck()
{
	return 0;
}


/********************************
Description: This holds the input validation for the game. Making sure numbers are chosen with min and
 max as arguments. In my group project we used this function, and found it more useful then the older
 one I was using since it detects strings.
********************************/
int Spaces::inputValidation(int min, int max)
{
	bool inputFail = true;
	int input = 0;


	while (inputFail) //will loop as long as the boolean inputFail is true.
	{
		cin >> input;
		inputFail = cin.fail(); //checks to make sure the right type of value is inputted

		//clears the input stream
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Lets the user know invalid input.
		if ((inputFail) || (input < min) || (input > max))
		{
			cout << "\nYour input is invalid.\n";
			cout << "Please enter an integer from ";
            cout << min << " to " << max << endl;

			inputFail = true;
		}
	}
	return input;
}
