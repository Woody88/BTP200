#include <iostream>
#include <iomanip>
#include "Order.h"
using namespace std;

Order::Order(){
	ean = EAN();
	ordered = 0;
	delivered = 0;
}

Order::Order(const EAN& ean){
	this->ean = ean;
	ordered = 0;
	delivered = 0;
}

EAN& Order::getEAN(){
	return ean;
}

bool Order::add(std::istream& is){
	int n, keepgoing = 1;
        bool valid;

        do{
                n = 0;
                cout << "Quantity (0 to quit): ";
                is >> n;
		is.clear();
                is.ignore(2000,'\n');


                if(n < 0){
                        cout << "Enter a positive number. Try again."<< endl;
                }
                else if(n == 0) {
			cout << "**No Order Added." << endl;
                        keepgoing = 0;
                        valid = false;
                }
                else {
                        ordered = n;
			keepgoing = 0;
                        valid = true;
                }

        }while(keepgoing == 1);

        return valid;

}


bool Order::add(int n){
	if(!(ean == EAN()) && !(n < 0)){
		ordered+=n;
		return true;
	}
	else	
		return false;
}

bool Order::receive(std::istream& is){
 int n, keepgoing = 1;
        bool valid;

        do{
                n = 0;
                cout << "Quantity (0 to quit): ";
                is >> n;
		is.clear();
                is.ignore(2000,'\n');
	
                if(n < 0){
                        cout << "Enter a positive number. Try again."<< endl;
                }
                else if(n == 0) {
			cout << "**No delivery recorded!" << endl;
                        keepgoing = 0;
                        valid = false;
                }
		else if(n > ordered){
			cout << n << " not on order. Only " << ordered << " are on order. Try again." << endl;
		}
                else {
                        delivered = n;
                        keepgoing = 0;
                        valid = true;
                }

        }while(keepgoing == 1);

        return valid;

}

void Order::display(std::ostream& os) const{
	os << left << setw(17);
	os << ean;
	os << setw(9);
	os << ordered;
	os << setw(11);
	os << delivered;
	 
}

int Order::outstanding()const {
	//cout << "outstand: " << ordered << endl; 
	return ordered;
}

ostream& operator<<(std::ostream& os, const Order& order){
	order.display(os);
}
SpecialOrder::SpecialOrder();
SpecialOrder::SpecialOrder(const EAN& isbn, const char* instr);
SpecialOrder::SpecialOrder(const SpecialOrder& source);
SpecialOrder::SpecialOrder& operator=(const SpecialOrder& source);
SpecialOrder::~SpecialOrder();
SpecialOrder::bool add(std::istream& is);
SpecialOrder::void display(std::ostream& os) const;













