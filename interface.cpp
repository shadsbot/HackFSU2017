#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

/* *
 * TODO: Hook functions to work with the backends.
 * 
 * Hook functions will need to pass in entire command and
 * return the details of the room / items in order to spit
 * out the text.
 * */



bool is_in(const std::vector<std::string> array, const std::string check);

int main() {
	
	bool RUNNING = true;
	
	
	//	vector<string> MOVEMENT[] = {"NORTH","SOUTH","EAST","WEST",
//					"FORWARD","BACKWARD","LEFT","RIGHT"};


	std::vector<std::string> itemcmd;
	std::vector<std::string> wherecmd;
	std::vector<std::string> movement;
	itemcmd.push_back("TAKE");
	itemcmd.push_back("PUT");
	itemcmd.push_back("PLACE");
	itemcmd.push_back("PICK");
	itemcmd.push_back("LIFT");
	itemcmd.push_back("RAISE");
	itemcmd.push_back("DROP");
	wherecmd.push_back("UP");
	wherecmd.push_back("DOWN");
	wherecmd.push_back("BACK");
	wherecmd.push_back("LEFT");
	wherecmd.push_back("RIGHT");
	wherecmd.push_back("FORWARD");
	movement.push_back("WALK");
	movement.push_back("GO");
	movement.push_back("HEAD");
	movement.push_back("PROCEED");

	std::vector<std::string>damp;
	std::vector<std::string>regular;
	
	std::vector<std::vector<std::string>> responses;
	responses.resize( 3, std::vector<std::string>>(4, "0"));

	string line;
	ifstream ifile("scenarios");
	while(getline(ifile,line)) {
		if (ifile.at(1) == "O") {
			responses[0][static_cast<int>(ifile.at(2))].push_back(ifile.substr(4));
		}
		if(ifile.at(1) == "R") {
			responses[1][static_cast<int>(ifile.at(2))].push_back(ifile.substr(4));
		}
		ifile (ifile.at(1) == "D") { 
			responses[2][static_cast<int>(ifile.at(2))].push_back(ifile.substr(4));
		}
	}
	ifile.close();
	
	while(RUNNING) {

		string cmd;
		cout << "COMMAND: ";
		getline(cin,cmd);
	
		// Why doesn't C++ have an explode or split? Seriously.
		string temp;
		vector <string> splitcmd;
		stringstream s (cmd);
		while(s>> temp)
			splitcmd.push_back(temp);
		
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
		// This causes a segmentation fault if there are not three args
/*		if(is_in(wherecmd,splitcmd[2])) {
			// TODO
			// Man, this is gonna be some hard stuff to do..
		}
*/		if(splitcmd[0] == "EXIT" || splitcmd[0] == "QUIT") {
			RUNNING = false;
		}
	}
	return 0;
}

bool is_in(const std::vector<std::string> array, const std::string check){
	return std::find(array.begin(),array.end(),check)!=array.end();
}
