#ifndef Spaces_hpp
#define Spaces_hpp
#include "Items.hpp"
#include "Tiles.hpp"
#include "player.hpp"


#include <iostream>
#include <string>
using std::string;


class Spaces
{
		friend class Game;

private:

protected:

	Tiles ***rooms;
	char location;
    player *player1;
	
    Spaces *up;
    Spaces *down;
    Spaces *left;
    Spaces *right;
    int rows;
    int columns;
    int currentRowOfPlayer;
    int currentColumnOfPlayer;


public:
	//Spaces(string inputNameOfRoom);
	Spaces(player *player, string inputNameOfRoom);
	virtual ~Spaces() = 0;
	//void displayMap(Spaces **rooms);
	virtual void getNameOfRoom();
	string nameOfRoom;
    int locationCheck;
	int spell;

	Items *item;
	virtual void printRoom();
    virtual void movePlayer(player player);
    virtual void findPlayerLocation(Tiles ***inputRoom, int rows, int columns);
	virtual int moveLeftRoom(); //will check the user goes through a door
	virtual int moveRightRoom(); //will check the user goes through a door
    virtual int moveUpRoom(); //will check the user goes through a door
    virtual int moveDownRoom();

	virtual void setLeft(Spaces *room);
	virtual void setRight(Spaces *room);
    virtual void setDown(Spaces *room);
    virtual void setUp(Spaces *room);

	virtual Spaces *getLeft();
	virtual Spaces *getRight();
    virtual Spaces *getDown();
    virtual Spaces *getUp();

	virtual void setPlayerLeft();
	virtual void setPlayerRight();
    virtual void setPlayerUp();
    virtual void setPlayerDown();

	virtual void pickUpItem();
    virtual int winCheck();
	virtual int spellCheck();
	int inputValidation(int min, int max);
    
    
    
};


#endif
