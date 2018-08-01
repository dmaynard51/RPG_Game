output: main.o Tiles.o Game.o Items.o Spaces.o Library.o player.o Corridor.o Door.o TileWithItem.o Stairway.o Dungeon.o Walls.o EscapeRoom.o
	g++ Tiles.o Game.o Items.o Spaces.o Library.o player.o Corridor.o Door.o TileWithItem.o Stairway.o Dungeon.o Walls.o EscapeRoom.o main.o -o finalproject

main.o: main.cpp 
	g++ -c main.cpp

Tiles.o: Tiles.cpp Tiles.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Tiles.cpp

Game.o: Game.cpp Game.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Game.cpp

Items.o: Items.cpp Items.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Items.cpp

Spaces.o: Spaces.cpp Spaces.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Spaces.cpp

Library.o: Library.cpp Library.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Library.cpp

player.o: player.cpp player.hpp
	g++ -g -c -std=c++11 -std=gnu++0x player.cpp

Corridor.o: Corridor.cpp Corridor.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Corridor.cpp

Door.o: Door.cpp Door.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Door.cpp

TileWithItem.o: TileWithItem.cpp TileWithItem.hpp
	g++ -g -c -std=c++11 -std=gnu++0x TileWithItem.cpp

Stairway.o: Stairway.cpp Stairway.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Stairway.cpp

Dungeon.o: Dungeon.cpp Dungeon.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Dungeon.cpp

Walls.o: Walls.cpp Walls.hpp
	g++ -g -c -std=c++11 -std=gnu++0x Walls.cpp

EscapeRoom.o: EscapeRoom.cpp EscapeRoom.hpp
	g++ -g -c -std=c++11 -std=gnu++0x EscapeRoom.cpp

clean:
	rm *.o finalproject
