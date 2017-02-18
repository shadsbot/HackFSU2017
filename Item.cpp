#include <iostream>
#include <string>
using namespace std;

class Item{

	friend ostream& operator<<(ostream &s, const Item &i);
	friend bool operator ==(const Item &i1, const Item &i2);

public:

	Item(const string &n);
	~Item();
	string Name();

private:

	string name;

}

//constructor
Item(const string &n){

	name = n;

}

//destructor - does nothing lol
~Item(const string &n){}

//fetches the name held in the item
string Name(){

	return name;

}

ostream& operator<<(ostream &os, const Item &i){

	os << i.Name();

	return os;
}

bool operator==(const Item &i1, const Item &i2){

	
	
}