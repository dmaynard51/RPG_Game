#ifndef Item_hpp
#define Item_hpp

#include "Items.hpp"
#include <string>
using std::string;


class Items
{
	friend class Spaces;
	friend class Game;
protected:
    string nameOfItem;
    int strength;
    
public:
    Items(string inputItemName);
	~Items();
    virtual int specialItemAbility();
    Items();
    virtual string getNameOfItem();
};

#endif
