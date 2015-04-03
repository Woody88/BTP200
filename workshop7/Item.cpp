#include <iostream>
#include <iomanip> 
#include "Item.h"

using namespace std;

Item::Item(){

	itemNumber = 0;
	itemPrice = 0;
}
void Item::operator=(double p) {
	itemPrice = p;
} 

void Item::operator=(int n) {
	itemNumber = n;
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
}
std::istream& operator>>(std::istream& is, Item& i) {
	double price;
	int number;
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

			i = price;
			i = number;
	}

}
std::ostream& operator<<(std::ostream& os, const Item& i) {
	i.display(os);
}
