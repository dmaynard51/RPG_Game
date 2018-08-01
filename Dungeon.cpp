//
//  Dungeon.cpp
//  finalproj
//
//  Created by Daniel Maynard on 8/13/17.
//  Copyright © 2017 Daniel Maynard. All rights reserved.
//

#include "Dungeon.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;





/*************************************
Description: Creates an 8x8 array. with 1 item on the floor and 2 doors. Will also wrap the walls 
 around the sides.
*************************************/
Dungeon::Dungeon(player *player, string inputNameOfRoom) : Spaces(player, inputNameOfRoom)
{
    rows = 8;
    columns = 8;
    nameOfRoom = inputNameOfRoom;
    		 for (int count = 0; count < rows; count++) //for every row add a column
	 {
		   rooms[count] = new Tiles* [columns];
			for (int count2 = 0; count2 < columns; count2++) //for every column make each element null
			{
				rooms[count][count2] = NULL;
			}
	}
	
    artifact = TileWithItem();
    
    
    rooms[3][3] = &artifact;
    
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
    rooms[7][1] = door;
    
    spell = 0;
    
}

/*************************************
Description: Deletes all dynamically created objects
*************************************/
Dungeon::~Dungeon()
{
    
    rooms[0][1] = NULL;
    
    rooms[3][1] = NULL;
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
Description: Prints out name of the room.
*************************************/
void Dungeon::getNameOfRoom()
{
	cout << nameOfRoom << endl;
}


/*************************************
Description: if player gets to array 7,1 will indicate to the game class the player will be moving down
 to the stairway
*************************************/
int Dungeon::moveDownRoom()
{
    int number =  0;
    if (rooms[7][1] == player1)
    {
        number = 4;
    }
    return number;
}

/*************************************
Description: If the player gets to the door at 0,1 - it indicates to the game class that the player
 is moving up to the next level north.
*************************************/
int Dungeon::moveUpRoom()
{
    int number =  0;
    if (rooms[0][1] == player1)
    {
        number = 3;
    }
    return number;
}

/*************************************
Description: sets the player if they come down to 1, 1 right below the door in the dungeon space.
*************************************/
void Dungeon::setPlayerDown()
{
    rooms[1][1] = player1;
}

/*************************************
Description: sets the player to 6, 1 if they come from the northern space.
*************************************/
void Dungeon::setPlayerUp()
{
    rooms[6][1] = player1;
}


/*************************************
Description: Prints the array to the user after each move.
*************************************/
void Dungeon::printRoom()
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
void Dungeon::movePlayer(player player)
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
Description: Locates location of the player @
*************************************/
void Dungeon::findPlayerLocation(Tiles ***inputRoom, int rows, int columns)
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
Description: checks if the spell was used in the particular space.
*************************************/
int Dungeon::spellCheck()
{

	return spell;
}
