#pragma once
#include "Spaces.hpp"
#include "Items.hpp"
#include "Corridor.hpp"

#include "Tiles.hpp"
#include "Library.hpp"
#include "Door.hpp"
#include "Stairway.hpp"
#include "Dungeon.hpp"
#include "EscapeRoom.hpp"

class Game
{
private: 


public:
	Game();
	~Game();
	void menu();


	void makeMove();
	Spaces *corridor;
	Spaces *library;
    Spaces *stairway;
    Spaces *dungeon;
    Spaces *dungeon2;
    Spaces *escaperoom;
    void playGame(player player1);
	Spaces *currentRoom;
    player *player1;
	Tiles *door;
	int inputValidation(int min, int max);

};

