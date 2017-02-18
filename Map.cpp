#include <iostream>
#include <deque>
#include "Room.cpp"
//#include "player.cpp"
using namespace std;

//player class
class player {
	public:
		int score = 0;
		std::deque<Item>  items;
};

//Map class
class Map{

public:

	Map();
	~Map();

	Room * getRoom(const int &x, const int &y);
	player * getPlayer();

private:

	void makeBorders();
	void makeExit();

	Room mapgrid[6][6];
	player person;

};

//constructor
Map::Map(){

	makeBorders();
	makeExit();

}

//destructor, nothing needed
Map::~Map(){}

void Map::makeBorders(){

	mapgrid[0][0].setWall('W',1);
	mapgrid[0][1].setWall('W',1);
	mapgrid[0][2].setWall('W',1);
	mapgrid[0][3].setWall('W',1);
	mapgrid[0][4].setWall('W',1);
	mapgrid[0][5].setWall('W',1);

	mapgrid[0][0].setWall('S',1);
	mapgrid[1][0].setWall('S',1);
	mapgrid[2][0].setWall('S',1);
	mapgrid[3][0].setWall('S',1);
	mapgrid[4][0].setWall('S',1);
	mapgrid[5][0].setWall('S',1);

	mapgrid[5][0].setWall('E',1);
	mapgrid[5][1].setWall('E',1);
	mapgrid[5][2].setWall('E',1);
	mapgrid[5][3].setWall('E',1);
	mapgrid[5][4].setWall('E',1);
	mapgrid[5][5].setWall('E',1);

	mapgrid[0][5].setWall('N',1);
	mapgrid[1][5].setWall('N',1);
	mapgrid[2][5].setWall('N',1);
	mapgrid[3][5].setWall('N',1);
	mapgrid[4][5].setWall('N',1);
	mapgrid[5][5].setWall('N',1);

}

//Returns a room. If coordinates are invalid, returns location 0,0
Room * Map::getRoom(const int &x, const int &y){

	Room * p;

	if(x >= 0 && x < 6 && y >= 0 && y < 6)
		p = &mapgrid[x][y];
	else
		p = &mapgrid[0][0];

	return p;
}

//returns
player * Map::getPlayer(){

	player * p = &person;

	return p;
}