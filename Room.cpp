#include <iostream>
#include <string>
#include <deque>
#include <ctime>
#include <cstdlib>
#include "Item.cpp"
using namespace std;

//Room class
class Room{

public:

	Room();
	Room(bool N, bool S, bool E, bool W);
	~Room();

	void Unlock(const char &c, Item &key);
	int getLightlvl const();

private:

	deque<Item> * contents;
	int Lightlvl;
	bool DoorN, DoorS, DoorE, DoorW;

};

//Constructor - randomly generates light level
Room::Room(){

	srand(time(NULL));
	Lightlvl = rand() % 4;
	contents = new deque<Item>();

}

//Destructor
Room::~Room(){

	delete contents;
	contents = nullptr;

}

//Displays the light level out
int Room::getLightlvl const(){

	if(Lightlvl == 0){
		cout << "The room is dark, and you can't see much at all.\n";
		return 0;
	}
	else if(Lightlvl == 1){
		cout << "The room has barely any light, but you can see if you squint.\n";
		return 1;
	}
	else if(Lightlvl == 2){
		cout << "The room is a little dim, but mostly visible.\n";
		return 2;
	}
	else
		cout << "The room is well-lit.\n";
	return 3;

}



//If there is a door to unlock and the user has a key, this function will
//unlock it
void Room::Unlock(const char &c, Item &key){

	if(c == 'N'){

    	if(key.Name() == "KEY"){ 					

    		if(DoorN == true){

    			DoorN == false;
    			cout << "You use the key on the door. ";
    			cout << "The door opens, but the key breaks\n";

    		}
    		else
    			cout << "This door is already unlocked\n";

    	}
    	else
    		cout << "You cannot use that on the door\n";

	}
	else if(c == 'S'){

		if(key.Name() == "KEY"){ 					
 
    		if(DoorS == true){

    			DoorS == false;
    			cout << "You use the key on the door. ";
    			cout << "The door opens, but the key breaks\n";

    		}
    		else
    			cout << "This door is already unlocked\n";

    	}
    	else
    		cout << "You cannot use that on the door\n";

	}
	else if(c == 'E'){

		if(key.Name() == "KEY"){ 					
 
    		if(DoorE == true){

    			DoorE == false;
    			cout << "You use the key on the door. ";
    			cout << "The door opens, but the key breaks\n";

    		}
    		else
    			cout << "This door is already unlocked\n";

    	}
    	else
    		cout << "You cannot use that on the door\n";

	}
	else if(c == 'W'){

		if(key.Name() == "KEY"){ 					
 
    		if(DoorW == true){

    			DoorW == false;
    			cout << "You use the key on the door. ";
    			cout << "The door opens, but the key breaks\n";

    		}
    		else
    			cout << "This door is already unlocked\n";

    	}
    	else
    		cout << "You cannot use that on the door\n";

	}
	else
		cout << "ERROR: INCORRECT DIRECTIONAL CHAR PASSED!\n\n";

	return;
}
