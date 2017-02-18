#include <iostream>
#include <string>
using namespace std;

//Take a guess what this is
class Item{

	friend ostream& operator<<(ostream &s, const Item &i);
	friend bool operator ==(const Item &i1, const Item &i2);

public:

	Item(const string &n);
	~Item();
	string Name() const;

private:

	string name;

};

//constructor
Item::Item(const string &n){

	name = n;

}

//destructor - does nothing lol
Item::~Item(){}

//fetches the name held in the item
string Item::Name() const{

	return name;

}

// you can now cout << the Item object
ostream& operator<<(ostream &os, const Item &i){

	os << i.Name();

	return os;
}

//Items are comparable
bool operator==(const Item &i1, const Item &i2){

	return (i1.Name() == i2.Name());

}
