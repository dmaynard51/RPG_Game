#include "Game.hpp"
#include <iostream>

#include <limits>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;



/*************************************
Description: Will dynamically create objects for the player, and spaces. The player is derived from the
 tile object, while the corridor, library, dungeons, stairway and escaperoom are derived from 
 Spaces class. A door is also dynamically created so that when the player walks over a door
 in it's derived space, we re-create it.
 
 The constructor also contain rules for each space indicating which spaces are next to each
 other.
*************************************/
Game::Game()
{
    player1 = new player;
    corridor = new Corridor(player1, "main corridor");
	library = new Library(player1, "Library");
    stairway = new Stairway(player1, "Stairway");
    dungeon = new Dungeon(player1, "Dungeon Level 1");
    dungeon2 = new Dungeon(player1, "Dungeon Level 2");
    escaperoom = new EscapeRoom(player1, "Final Room");
    corridor->setLeft(library);
	library->setRight(corridor);
    
    
    library->setUp(stairway);
    stairway->setDown(library);
    
    stairway->setUp(dungeon);
    dungeon->setDown(stairway);
    
    dungeon->setUp(dungeon2);
    dungeon2->setDown(dungeon);
    
    dungeon2->setUp(escaperoom);
    escaperoom->setDown(dungeon2);
    
	currentRoom = corridor;
	door = new Door;

}

/*************************************
Description: Deletes dynamic objects created in the constructor.
*************************************/
Game::~Game()
{
    
	delete corridor;
    delete library;
    delete stairway;
    delete dungeon;
    delete dungeon2;
    delete player1->bag;
    delete player1;
    delete door;
    delete escaperoom;
	
}


/*************************************
Description: When the game is started, shows an option to start or quit the game.
*************************************/
void Game::menu()
{
	cout << "1. Play Game" << endl;
	cout << "2. Quit Game" << endl;
	int choice;
	choice = inputValidation(1,2);
	if (choice == 1)
	{
		
		playGame(*player1);
	}
	if (choice == 2)
	{
		//end game
		return;
	}
}

/*************************************
Description: Contain the rules for the game. At the start, explains the plot of the game.
 
 If the player does not collect all of the objects, then the player will lose and cannot move 
 to through the last door.  Win check indicates the player made it to the final door, and all the
 items have been collected. If the steps get down to 0, then the player loses.
 
 Also contains the rules if the player moves to a different location for each room. Each step will be decreased if the player makes an action, like moving around the room, casting a spell etc.
*************************************/
void Game::playGame(player player1)
{
	cout << "You are in wizard's training school, and you must collect the artifacts for"  << endl;
	cout << "Master Dumbledore. He wants you to practice your unlock door spell and" << endl;
    cout << "to collect artifacts that he left throughtout the floors of the castle."<< endl;
    cout << "After you collect all of the items, and cast the unlock spell in each room" << endl;
    cout << "exit the door on the north side of the final room." << endl;
	cout << "Use your actions wisely as magic can be exhausting!" << endl;
    int steps = 80;
    while (steps >= 0)
    {
       //verifies if the players bag is full and if the player exits the final door.
        if (currentRoom->winCheck() == 1 && player1.isBagEmpty() == 0)
        {
            cout << "You have collected all of the artifacts, and the door opens. You have won!" << endl;
            break;
        }
        
		if (steps == 0)
		{
			cout << "You're exhausted. You lose!" << endl;
		}

        cout << "You have " << steps << "  steps remaining" << endl;
        currentRoom->printRoom();
        currentRoom->movePlayer(player1);
        steps = steps - 1;

//if user is moving to the left floor sets the current room to the left room
		if (currentRoom->moveLeftRoom() == 1)
		{
				currentRoom->rooms[3][0] = door;
				currentRoom = currentRoom->getLeft(); // changes room to the left
				currentRoom->setPlayerLeft(); //changes player to left room
		}

        //if player is moving to the right room, sets the current location to the right room.
			if (currentRoom->moveRightRoom() == 2)
		{
				currentRoom->rooms[6][7] = door;
				currentRoom = currentRoom->getRight();
				currentRoom->setPlayerRight();
		}
        
        //if player is moving to the northern room, sets the player to the northern room
        if (currentRoom->moveUpRoom() == 3)
        {
            if (currentRoom == library || currentRoom == dungeon || currentRoom == dungeon2)
            {
            currentRoom->rooms[0][1] = door;
            }
            if (currentRoom == stairway)
            {
                currentRoom->rooms[0][1] = door;
            }
            
            currentRoom = currentRoom->getUp();
            currentRoom->setPlayerUp();
        }
        
        //if user moves to the southern room, sets the player to the southern room.
        if (currentRoom->moveDownRoom() == 4)
        {
            if (currentRoom == stairway || currentRoom == dungeon || currentRoom == dungeon2 || currentRoom == escaperoom)
            {
            currentRoom->rooms[7][1] = door;
            }
            currentRoom = currentRoom->getDown();
            currentRoom->setPlayerDown();
        }
		
    }

    
}


/********************************
Description: This holds the input validation for the game. Making sure numbers are chosen with min and
 max as arguments. In my group project we used this function, and found it more useful then the older
 one I was using since it detects strings.
********************************/
int Game::inputValidation(int min, int max)
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
