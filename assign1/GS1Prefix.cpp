// GS1Prefix.cpp 
// BTP200 - Assignment 1
// WOODSON DELHIA

#include <iostream>
#include <fstream>
#include <cstring>
#include "GS1Prefix.h"
using namespace std;

////////////////////////////////////////////////
// Load prefixRanges.txt into struct             //
//////////////////////////////////////////////
bool load(const char* filename, Prefix* prefix) {
	bool rc = false;
	if (filename != nullptr) {
		std::ifstream file(filename);
		if (file.is_open()) {
			int no = 0;
			while (file.good()) {  // version 1.2
				file >> prefix->area[no] >> prefix->pubLow[no]; // version 1.3
				if (file.good()) {
					file >> prefix->pubHgh[no]; // version 1.3
					prefix->pubLen[no] = std::strlen(prefix->pubLow[no]);
					no++;
				}
			}
			if (no > 0) {
				rc = true;
				prefix->no = no;
			}
		}
	}
	return rc;
}

////////////////////////////////////////////////////////////
// Verifies if area sent match any aread in the struct   //
//////////////////////////////////////////////////////////
bool isRegistered(const Prefix* p, int area){
	
	int valid = 0;
	for(int i = 0; i < p-> no; i++) {
		if(p->area[i] == area){
			valid = 1;
			i = p->no;
		}
	
	}
	
	return valid;
}

////////////////////////////////////////////////////////
// Look for the min length of the area's publisher   //   
//////////////////////////////////////////////////////
int minNoDigits(const Prefix* p, int area){
	int publisherLen = 0;
	
	for(int i = 0; i < p->no; i++){
		if(p->area[i] == area){
			publisherLen = p->pubLen[i];	
			i = p->no;
		}
	}
	return publisherLen;
}

/////////////////////////////////////////////////////////////////
// Verifies if the publisher is within range of all possible  //
// combination of publisher using pubHgh and publow          // 
//////////////////////////////////////////////////////////////
bool isRegistered(const Prefix* p, int area, const char* publisher){
	int valid = 0;
	
	for(int i = 0; i < p->no; i++){
		if(p->area[i] == area && strlen(publisher) == p->pubLen[i] ){
			if(atoi(publisher)>= atoi(p->pubLow[i]) && atoi(publisher) <= atoi(p->pubHgh[i])){
				valid = 1;
			}
		}			
	}
	return valid;
}
