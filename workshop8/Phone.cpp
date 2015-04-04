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
