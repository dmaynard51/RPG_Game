
#include "EscapeRoom.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;





/*************************************
Description:
*************************************/
EscapeRoom::EscapeRoom(player *player, string inputNameOfRoom) : Spaces(player, inputNameOfRoom)
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
    
    locationCheck = 0;
    
}

/*************************************
Description:
*************************************/
EscapeRoom::~EscapeRoom()
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
Description:
*************************************/
void EscapeRoom::getNameOfRoom()
{
    cout << nameOfRoom << endl;
}

/*************************************
Description:
*************************************/
int EscapeRoom::moveDownRoom()
{
    int number =  0;
    if (rooms[7][1] == player1)
    {
        number = 4;
    }
    return number;
}



/*************************************
Description:
*************************************/
void EscapeRoom::setPlayerUp()
{
    rooms[6][1] = player1;
}


/*************************************
Description:
*************************************/
void EscapeRoom::printRoom()
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
 
 Also since this is the final room, if the player does not have 5 items and tries to exit the door
 it will not allow them to move forward.
*************************************/
void EscapeRoom::movePlayer(player player)
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
            if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'D' && winCheck() != 1 && player1->isBagEmpty() != 0)
			{
				cout << "you have not collected all of the artifacts and may not pass" << endl;
				return;
			}


            if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer]->getTileType() == 'D')
            {
                cout << "";
            }
            
            if (rooms[currentRowOfPlayer-1][currentColumnOfPlayer] == rooms[0][1])
            {
                locationCheck = 1;
                
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
    
}

/*************************************
Description: Locates location of the player @
*************************************/
void EscapeRoom::findPlayerLocation(Tiles ***inputRoom, int rows, int columns)
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
Description: If the player has all the items, and makes it through the door then location check
 is changed to 1, which will be used by the game class to determine if a win is made.
*************************************/
int EscapeRoom::winCheck()
{
    return locationCheck;
}
