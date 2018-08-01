

#ifndef TileWithItem_hpp
#define TileWithItem_hpp
#include "Tiles.hpp"
#include "Items.hpp"
class TileWithItem : public Tiles
{

    
public:
    TileWithItem();
    ~TileWithItem();
    Items artifact;
};


#endif /* TileWithItem_hpp */
