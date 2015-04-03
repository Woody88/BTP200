#include <iostream>
#include <fstream>
#include <cstring>
#include "GS1Prefix.h"
using namespace std;

Prefix::Prefix(const char* filename){
	
	bool rc = false;
	if (filename != nullptr) {
		std::ifstream file(filename);
		if (file.is_open()) {
			int no = 0;
			while (file.good()) {  // version 1.2
				file >> area[no] >> pubLow[no]; // version 1.3
				if (file.good()) {
					file >> pubHgh[no]; // version 1.3
					pubLen[no] = std::strlen(pubLow[no]);
					no++;
				}
			}
			if (no > 0) {
				rc = true;
				this->no = no;
			}
		}
	}

}

bool Prefix::isRegistered(int marea) const{
	int valid = 0;
	for(int i = 0; i < no; i++) {
		if(area[i] == marea){
			valid = 1;
			i = no;
		}
	
	}
	
	return valid;
}

int Prefix::minNoDigits(int area) const{
	int publisherLen = 0;
	
	for(int i = 0; i < this->no; i++){
		if(this->area[i] == area){
			publisherLen = this->pubLen[i];	
			i = this->no;
		}
	}
	return publisherLen;
}
bool Prefix::isRegistered(int marea, const char* publisher) const{
	int valid = 0;
	for(int i = 0; i < no; i++){
		if(area[i] == marea && strlen(publisher) == pubLen[i] ){
			if(atoi(publisher)>= atoi(pubLow[i]) && atoi(publisher) <= atoi(pubHgh[i])){
				valid = 1;
			}
		}			
	}
	return valid;
}
