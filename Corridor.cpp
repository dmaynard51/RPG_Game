#include "Corridor.hpp"
#include "Items.hpp"

#include "Tiles.hpp"
#include "player.hpp"
#include "TileWithItem.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*************************************
Description: Will create an dynamic array of 8x8 with walls on the edges and 1 door that leads to
 the library and one artifact.
*************************************/
Corridor::Corridor(player *player, string inputNameOfRoom) : Spaces(player, inputNameOfRoom)
{
	
	rows = 8;
	columns = 8;
    		 for (int count = 0; count < rows; count++) //for every row add a column
	 {
		   rooms[count] = new Tiles* [columns];
			for (int count2 = 0; count2 < columns; count2++) //for every column make each element null
			{
				rooms[count][count2] = NULL;
			}
	}

	nameOfRoom = inputNameOfRoom;
    artifact = TileWithItem();

    
    rooms[1][1] = &artifact;
	rooms[6][2] = player;
	door = new Door;
	rooms[3][0] = door;
	wall = new Walls();

    for (int count = 0; count < columns; count ++)
    {
        rooms[0][count] = wall;
        rooms[count][rows-1] = wall;
        rooms[rows-1][count] = wall;
    }
    
    rooms[1][0] = wall;
    rooms[2][0] = wall;
    rooms[4][0] = wall;
    rooms[5][0] = wall;
    rooms[6][0] = wall;

	spell = 0;
}

/*************************************
Description: Deconstructor deletes the walls and door that were dynamically created.
 It will then delete the dynamic array
*************************************/
Corridor::~Corridor()
{
    rooms[0][0]= NULL;
    
    rooms[3][2] = NULL;
	
    rooms[3][0] = NULL;
    delete door;
	delete wall;

	    for (int count = 0; count < rows; count++)
    {
        for (int count2 = 0; count2 < columns; count2++)
        {
            rooms[count][count2] = NULL; //first sets all parts of the array to null
            delete rooms[count][count2]; //then delete each element
        }
        delete [] rooms[count]; //delete the rows
    }
		delete [] rooms; //finally deletes the room
			rooms = NULL;
}

/*************************************
Description:
*************************************/
void Corridor::getNameOfRoom()
{
    cout << nameOfRoom << endl;
}

/*************************************
Description: When the user enters array 3,0 it will call game to move 
 to the next room - Library.
*************************************/
int Corridor::moveLeftRoom()
{
	int number =  0;
	if (rooms[3][0] == player1)
		{
			number = 1;
		}
		return number;
}

/*************************************
Description: When coming from the right side, sets the user at 3, 1 in the array
*************************************/
void Corridor::setPlayerRight()
{
	rooms[3][1] = player1;
}


/*************************************
Description: prints all parts of the array for the user
*************************************/
void Corridor::printRoom()
{

    cout << endl;
	
	this->getNameOfRoom();
	 for (int count = 0; count < rows; count++)
	{
		for (int count2 = 0; count2 < columns; count2++)
		{
			if (rooms[count][count2] == NULL)
				cout << "#" << " ";
			else if (rooms[count][count2]->getTileType() == 'D')
				cout << 'D' << " ";
			else if (rooms[count][count2]->getTileType() == '|')
				cout << '|' << " ";
			else 
				cout << rooms[count][count2]->getTileType() << " ";
		}
		cout << endl;
        
	}
}

/*************************************
 Description: This menu allows the players to move up, down, left , right, pick up item to the north, print out their current bag
 and cast the unlock door spell.
 
 It will make sure if there is a tile with | it won't allow the player to move through. If the western door is locked will also
 tell the user to its locked. The player can unlock it by hitting 7.
*************************************/
void Corridor::movePlayer(player player)
{
    cout << "1. Move up." << endl;
    cout << "2. Move down" << endl;
    cout << "3. Move right" << endl;
    cout << "4. Move left" << endl;
	cout << "5. Pick up item above player" << endl;
	cout << "6. Print inventory" << endl;
	cout << "7. Cast open door spell" << endl;
    int choice;
	    findPlayerLocation(rooms, rows, columns);

    choice = inputValidation(1, 7);
    
    //player moves north, verifies if there is a wall, or item. And will then move the player up one
    //and replace previous location with NULL
    if (choice == 1)
    {

        if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer] != NULL)
        {
			if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == '|' || rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'o')
            {
			cout << "the way is blocked" << endl;
            return;
            }
            
            if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'D')
            {
                cout << "";
            }
        }
		else
		{
        findPlayerLocation(rooms, rows, columns);
        rooms[currentRowOfPlayer - 1][currentColumnOfPlayer] = player1;
        rooms[currentRowOfPlayer][currentColumnOfPlayer] = NULL;
        findPlayerLocation(rooms, rows, columns);
		}
    }
    
    //if player moves to down, checks if there is a wall or item
    if (choice == 2)
    {
        if (rooms[currentRowOfPlayer+1][currentColumnOfPlayer] != NULL)
        {
            if (rooms[currentRowOfPlayer+1][currentColumnOfPlayer]->getTileType() == '|' || rooms[currentRowOfPlayer+1][currentColumnOfPlayer]->getTileType() == 'o')
            {
            cout << "the way is blocked" << endl;
            return;
            }
            
            if (rooms[currentRowOfPlayer+1][currentColumnOfPlayer]->getTileType() == 'D')
            {
                cout << "";
            }
            
        }
        findPlayerLocation(rooms, rows, columns);
        rooms[currentRowOfPlayer + 1][currentColumnOfPlayer] = player1;
        rooms[currentRowOfPlayer][currentColumnOfPlayer] = NULL;
        findPlayerLocation(rooms, rows, columns);
        
    }
    
    //if the player moves to the right, checks if there is a wall or item.
    if (choice == 3)
    {
        if (rooms[currentRowOfPlayer][currentColumnOfPlayer+1] != NULL)
        {
            if (rooms[currentRowOfPlayer][currentColumnOfPlayer+1]->getTileType() == '|' || rooms[currentRowOfPlayer][currentColumnOfPlayer+1]->getTileType() == 'o')
            {
                cout << "the way is blocked" << endl;
                return;
            }
            
            if (rooms[currentRowOfPlayer][currentColumnOfPlayer+1]->getTileType() == 'D')
            {
                cout << "";
            }
            
        }
        findPlayerLocation(rooms, rows, columns);
        rooms[currentRowOfPlayer][currentColumnOfPlayer + 1] = player1;
        rooms[currentRowOfPlayer][currentColumnOfPlayer] = NULL;
        findPlayerLocation(rooms, rows, columns);
        
    }
    
    //if player moves to the left, checks if there is a wall or item.
    if (choice == 4)
    {
		cout << spellCheck() << endl;
        if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1] != NULL)
        {
            if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == '|' || rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == 'o')
            {
                cout << "the way is blocked" << endl;
                return;
            }
            
			if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == 'D' && spellCheck() == 0)
			{
				cout << "the door is locked" << endl;
				return;
			}

            if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == 'D' && spellCheck() == 1)
            {
                cout << "";

            }
        }
        findPlayerLocation(rooms, rows, columns);
        rooms[currentRowOfPlayer][currentColumnOfPlayer - 1] = player1;
        rooms[currentRowOfPlayer][currentColumnOfPlayer] = NULL;
        findPlayerLocation(rooms, rows, columns);
        
    }
    
    //will pick up an item if is one north of the player.
	if (choice == 5)
	{
		if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer] == NULL)
		{
			cout << "item not here" << endl;
		}
		else if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'o')
		{
			cout << "item here" << endl;
			this->player1->addToBag(&rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->itemOnFloor);
			cout << rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->itemOnFloor.getNameOfItem() << "!" <<endl;
			rooms[currentRowOfPlayer-1][currentColumnOfPlayer] = NULL;
		}
	}

    //prints items that are in the players bag
	if (choice == 6)
	{
        this->player1->printBag();
	}

	if (choice == 7)
	{
		cout << "You hear the click of an unlocked door." << endl;
		spell = 1;
	}
    
}

/*************************************
Description: Locates where @ is in the array
*************************************/
void Corridor::findPlayerLocation(Tiles ***inputRoom, int rows, int columns)
{
    for (int count = 0; count < rows; count++)
    {
        for (int count2 = 0; count2 < columns; count2++)
        {
            if (inputRoom[count][count2] == NULL)
            {
                //do nothing
            }
            else if (inputRoom[count][count2]->getTileType() == '@')
            {
                currentRowOfPlayer = count;
                currentColumnOfPlayer = count2;
            }
            
        }
        
    }
}

/*************************************
Description: checks if the user casted the unlock door spell in the array.
*************************************/
int Corridor::spellCheck()
{

	return spell;
}
