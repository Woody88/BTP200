#include <iostream>
#include <iomanip> 
#include <cstring>
#include "Item_Y.h"

using namespace std;

Item::Item(){

	itemNumber = 0;
	itemPrice = 0;
	description = new char;
	description = nullptr;
}

Item::~Item() {
	description = nullptr;
	delete description;
}
void Item::operator=(double p) {
	itemPrice = p;
} 

void Item::operator=(int n) {
	itemNumber = n;
}


void Item::operator=(char* c) {
	if(description == nullptr)
		strcpy(description, c);
}
bool Item::empty() const {
	if (itemNumber == 0 && itemPrice == 0) 
		return true;
	else 
		return false;

} 

void Item::display(std::ostream& os) const {
	os << left << setw(8);
	os << itemNumber;
	os << right << setw(10);
	os << itemPrice;
	os << description;
}
std::istream& operator>>(std::istream& is, Item& i) {
	double price;
	int number;
	char* description;
	description = new char;

	cout << "Enter an item number: ";
	is >> number;
	if (number < 0 )
		cout << "Invalid Item Number!" << endl;
	else {

			is.ignore(1000,'\n');
			is.clear();
			cout << "Enter an item price: ";
			is >> price;
			is.ignore(1000,'\n');
			is.clear();
			cout << "Enter a description: ";
			is >> description;
			is.ignore(1000,'\n');
			is.clear();

			i = price;
			i = number;
	}

	delete description;

}
std::ostream& operator<<(std::ostream& os, const Item& i) {
	i.display(os);
}