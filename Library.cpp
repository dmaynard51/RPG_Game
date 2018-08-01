#include "Library.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*************************************
Description: Class constructor creates the 8x8 array, outer walls and item in the space
*************************************/
Library::Library(player *player, string inputNameOfRoom) : Spaces(player, inputNameOfRoom)
{
    
    rows = 8;
    columns = 8;
	nameOfRoom = inputNameOfRoom;
    artifact = TileWithItem();
    		 for (int count = 0; count < rows; count++) //for every row add a column
	 {
		   rooms[count] = new Tiles* [columns];
			for (int count2 = 0; count2 < columns; count2++) //for every column make each element null
			{
				rooms[count][count2] = NULL;
			}
	}


    item = new Items();
    rooms[1][1] = &artifact;
	door = new Door;
	
    wall = new Walls();
    
    for (int count = 0; count < columns; count ++)
    {
        rooms[count][0] = wall;
        rooms[rows-1][count] = wall; //bottom of room
        rooms[0][count] = wall;
        rooms[count][columns-1] = wall;
    }
    rooms[0][1] = door;
    rooms[6][7] = door;

	spell = 0;
}

/*************************************
Description: deletes all dynamically created objects
*************************************/
Library::~Library()
{
    rooms[1][1] = NULL;
	delete item;
    rooms[0][1] = NULL;
    rooms[3][3] = NULL;
	delete door;
    delete wall;

		    for (int count = 0; count < rows; count++)
    {
        for (int count2 = 0; count2 < columns; count2++)
        {
            rooms[count][count2] = NULL;
            delete rooms[count][count2];
        }
        delete [] rooms[count];
    }
    
    delete [] rooms;
    	rooms = NULL;
    
}

/*************************************
Description: Returns the name of the space.
*************************************/
void Library::getNameOfRoom()
{
	cout << nameOfRoom << endl;
}

/*************************************
Description: return 2 to the game class if the player moves to the door at the bottom of the space.
 Which will then switch the player to the southern space.
*************************************/
int Library::moveRightRoom()
{
	int number =  0;
	if (rooms[6][7] == player1)
		{
			//rooms[3][0] = NULL;
			number = 2;
		}
		return number;
}

/*************************************
Description: Returns 3 to the game space, which will switch the player to the northern space. The
 Stairway.
*************************************/
int Library::moveUpRoom()
{
    int number = 0;
    if (rooms[0][1] == player1)
    {
        
        number = 3;
    }
    return number;
    
}

/*************************************
Description: If player comes from the right,sets the player 6, 6
*************************************/
void Library::setPlayerLeft()
{
	rooms[6][6] = player1;
}

/*************************************
 Description: If player comes from the northern space, set the player at 1, 1
 *************************************/
void Library::setPlayerDown()
{
    rooms[1][1] = player1;
}


/*************************************
Description: prints the rooms for the user.
*************************************/
void Library::printRoom()
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
			else 
				cout << rooms[count][count2]->getTileType() << " ";
		}
		cout << endl;
        
	}
}

/*************************************
 Description: This menu allows the players to move up, down, left , right, pick up item to the north, print out their current bag
 and cast the unlock door spell.
 
 It will make sure if there is a tile with | it won't allow the player to move through. If the northern door is locked will also
 tell the user to its locked. The player can unlock it by hitting 7.
*************************************/
void Library::movePlayer(player player)
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

			if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'D' && spellCheck() == 0)
			{
				cout << "the door is locked" << endl;
				return;
			}

            
            if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'D')
            {
                cout << "";
            }
        }
        findPlayerLocation(rooms, rows, columns);
        rooms[currentRowOfPlayer-1][currentColumnOfPlayer] = player1;
        rooms[currentRowOfPlayer][currentColumnOfPlayer] = NULL;
        findPlayerLocation(rooms, rows, columns);
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
    
    //if player moves to down, checks if there is a wall or item
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
        if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1] != NULL)
        {
            if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == '|' || rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == 'o')
            {
                cout << "the way is blocked" << endl;
                return;
            }
            
            if (rooms[currentRowOfPlayer][currentColumnOfPlayer-1]->getTileType() == 'D')
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
Description: locates the location of the player @
*************************************/
void Library::findPlayerLocation(Tiles ***inputRoom, int rows, int columns)
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
Description: checks if the user casted a spell in the space to unlock the door.
*************************************/
int Library::spellCheck()
{

	return spell;
}
