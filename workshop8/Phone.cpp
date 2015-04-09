#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "Phone.h"

using namespace std;

Phone::Phone() {
	area = 0;
	n = 0;
} 

Phone::Phone(int a, int b){	
	area = a;
	n = b;
}

void Phone::display() const {
	stringstream x;
	string s;
	
	x << n;
	s = x.str();
	
	cout << area << "-";	
	for(int i = 0; i < s.length(); i++){
		if(i < 3){
			cout <<  s.at(i);
		}
		else if (i == 3) {
			cout << "-" << s.at(i);
		}
		else
			cout << s.at(i);	
	}


}

bool Phone::isValid() const {
	bool valid = true;
	if (area < 100 || area > 999)
		valid = false;

	if (n < 1000000 || n > 9999999 )
		valid = false;

	if (area == 0 && n == 0)
		valid = false;	
	
	return valid;
}

IntlPhone::IntlPhone() {
	intl = 0;
	
}

IntlPhone::IntlPhone(int a, int b , int c):Phone(b,c) {
        intl = a;
}

void IntlPhone::display() const {
	cout << intl;
	cout << "-";	
	Phone::display();
	
	
}

bool IntlPhone::isValid() const {
	int valid = true;
	
	if(intl < 100 || intl > 999)
		valid = false;

	valid = Phone::isValid();

	return valid;
}

std::istream& operator>>(std::istream& is, Phone& p){
	cout << "inside 1" << endl;
	
}
std::istream& operator>>(std::istream& is, IntlPhone& p){
	cout << "inside 2" << endl;
	Phone phone;

	int n = 0, country = 0;
	cout << "Enter a Country: ";
	is >> country;
	is >> phone
}
std::ostream& operator<<(std::ostream&, const Phone& p){
	cout << "inside 3" << endl;
}
std::ostream& operator<<(std::ostream&, const IntlPhone& p){
	cout << "inside 4" << endl;
}
 
