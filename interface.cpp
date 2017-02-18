#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_in(const std::vector<std::string> array, const std::string check);

int main() {
	
//	vector<string> MOVEMENT[] = {"NORTH","SOUTH","EAST","WEST",
//					"FORWARD","BACKWARD","LEFT","RIGHT"};


	std::vector<std::string> itemcmd;
	std::vector<std::string> wherecmd;
	std::vector<std::string> movement;
	itemcmd.push_back("TAKE");
	itemcmd.push_back("PUT");
	itemcmd.push_back("PLACE");
	itemcmd.push_back("LIFT");
	itemcmd.push_back("RAISE");
	wherecmd.push_back("UP");
	wherecmd.push_back("DOWN");
	wherecmd.push_back("BACK");
	movement.push_back("NORTH");
	movement.push_back("SOUTH");
	movement.push_back("EAST");
	movement.push_back("WEST");
	
	string cmd;
	cout << "COMMAND: ";
	getline(cin,cmd);

	// Why doesn't C++ have an explode or split? Seriously.
	string temp;
	vector <string> splitcmd;
	stringstream s (cmd);
	while(s>> temp)
		splitcmd.push_back(temp);

	
	cout << "The commands entered were: " << splitcmd[0] << "," << splitcmd[1] << "," << splitcmd[2] << endl;
	if(is_in(movement,splitcmd[0])) {
		// TODO
		// This is a movement handler, and should redirect the rest
		// of the command to another function that will handle if 
		// player will be able to actually move. For now, debug.
		cout << "MOVEMENT\n";
	}
	if(is_in(itemcmd,splitcmd[0])) {
		// TODO
		// This will be passed on to another function which will handle
		// all the action past this.
		cout << "ITEM\n";
	}
	if(is_in(wherecmd,splitcmd[2])) {
		// TODO
		// Man, this is gonna be some hard stuff to do..
	}

	return 0;
}

bool is_in(const std::vector<std::string> array, const std::string check){
	return std::find(array.begin(),array.end(),check)!=array.end();
}
