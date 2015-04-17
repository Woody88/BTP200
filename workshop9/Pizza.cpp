#include "Pizza.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;


Pizza::Pizza() {
	diameter = 0;
	totalSlices = 0;
	consumed = 0;
}

Pizza::Pizza(double x, int y ) {
	Pizza();
	diameter = x;
	totalSlices = y;
}
int Pizza::portions() const {
	
	return totalSlices; 
}

void Pizza::consume() {
	consumed++;
}

int Pizza::remaining() const {
	return (totalSlices - consumed);
}

void Pizza::display() const {
	cout << noshowpoint << diameter << "\" " << portions() << " slices " << remaining() << " remaining" << endl;
}

DeluxePizza::DeluxePizza() {
	toppings[0] = '\0';
}

DeluxePizza::DeluxePizza(double x, int y, char* top) : Pizza(x, y){
		DeluxePizza();
		strcpy(toppings, top);
}
void DeluxePizza::display() const {
	Pizza::display();
	cout << "-" << toppings << endl;
}


