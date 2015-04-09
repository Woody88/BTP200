// EAN Processor
// BTP200 - Assignment 3
// EAN.cpp
// Woodson Delhia
// date--

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;	

#include "EAN.h"
#include "GS1Prefix.h"
#define  PREFIX_LIST "prefixRanges.txt"

bool isValid(const char* str){
	int oddNum = 0, evenNum = 0, total, valid = 0, tempSum = 0;			
		
	if(str == NULL|| str[0] != '9' || str[1] != '7')
		valid = 0;
	else 
		if(!(str[2] != '8' || str[2] != '9'))
			valid = 0;
		else{
			////////// This point we know its EAN number //////////

			if(strlen(str) == 13) {
				valid = 1;
				for(int i = 0; i < strlen(str); i++){                  //Loop through str array
					if(!isdigit(str[i])){                         //Validate if str at i position is a digit
						valid = 0;
						break;                               //If not digit break loop
					}
		
		
					else	{
							if((i+1)%2 == 0){           //Valid if i is not equal to 12 and is an even digit
								evenNum+=((str[i] - '0')*3);
								tempSum += evenNum;
							}	 
							else{ 
								oddNum+=(str[i] - '0');
								tempSum += oddNum;
							}	
						}
				}
			}

			if(oddNum != 0 && evenNum != 0){            //Validate that there is a value greate than 0 in even and odd Num
				total = oddNum + evenNum;
				if((total%10) == 0)                //If total a modulo of 10 EAN number is valid
					valid = 1;
				else
					valid = 0;
			}	
		}
	return valid;
}

bool EAN::isRegistered(const Prefix& list){

	//cout << "INSIDE IS REGISTERED!" << endl; 
	//cout << "EAN: " << ean << endl;
	int valid = 0, areaCheck = 0, startPos = 3, areaMax = 5, pubMax = 7, titleMax = 6, position = 0;
	
	
	for(int i = startPos; i < startPos + areaMax; i++){
		area[i-startPos] = ean[i];
		area[(i-startPos)+1] = '\0';
		areaCheck = atoi(area);
		if(list.isRegistered(areaCheck)){
			valid = 1;
			position = i + 1;
			i = startPos + areaMax;
		}
	}

	if(valid == 1){
		int minPublen = 0;
		minPublen = list.minNoDigits(areaCheck);	
		if(minPublen == 0)
			valid =0;
			
	}

	if(valid == 1){
		int k = 0, tempPos = 0;
		
		valid = 0;
		
		for(int i = position; i < position + pubMax; i++){
			publisher[k] = ean[i];
			publisher[k+1] = '\0';
			if(list.isRegistered(areaCheck, publisher)){		
				valid = 1;
				tempPos = i;
				i = position + pubMax;
			}
			k++;
		}
		position = tempPos + 1;
	}

	if(valid == 1){
		int l = 0; 

		while(position < 12){
			title[l] = ean[position];
			title[l+1] = '\0';
			l++;
			position++;
		}		
	}
	
	registered = valid;
	return valid;
		
}

EAN::EAN(){
	ean[0] = '\0';
	strStyle[0] = '\0';
	area[0] = '\0';
	publisher[0] = '\0';
	title[0] = '\0';
	registered = false;
}

EAN::EAN(const char* str, const Prefix& list){
	if( isValid(str) ){
		strcpy(ean, str);
		isRegistered(list);
		strStyle[0] = '0';
		strStyle[1] = '\0';
	}
	else{
		ean[0] = '\0';
	        strStyle[0] = '\0';
        	area[0] = '\0';
        	publisher[0] = '\0';
        	title[0] = '\0';
		registered = false;
		
	}	
}

bool EAN::empty() const{
	if(ean[0] == '\0' && strStyle[0] == '\0' && area[0] == '\0' && publisher[0] == '\0' && title[0] == '\0')
		return true;
	else
		return false;
}

bool EAN::isRegistered() const{
	// if(area[0] != '\0' && publisher[0] != '\0' && title[0] != '\0')
	if (registered)
		return true;
	else 
		return false;
}

void EAN::style(char s){

	strStyle[0] = s;
	strStyle[1] = '\0';
}
void EAN::toStr(char* str) const{
	strcpy(str, ean);		
}
void EAN::toStrWithStyle(char* str) const{
	int i = 3 + strlen(area) + strlen(publisher) + strlen(title);
        char string[17] = {'\0'};
        char styling[2];
        char lastDigit[2] = {'\0'};
        str[0] = '\0';
        lastDigit[0] = ean[12];
        lastDigit[1] = '\0';

//      cout << "MY STRING IS: " << str << endl;
        if(isRegistered()){
                if(strcmp(strStyle, "0") == 0)
                        strcpy(styling, "-");
                else
                        strcpy(styling, strStyle);

                strcat(str, "978");
                strcat(str, styling);
                strcat(str, area);
                strcat(str, styling);
                strcat(str, publisher);
                strcat(str, styling);
                strcat(str, title);
                strcat(str, styling);
                strcat(str, lastDigit);
        }
        else{
                strcat(str, ean);
                //str[strlen(str)] = ean[12];
                //str[strlen(str)+1] = '\0';
               
        }

}

bool EAN::read(std::istream& is, const Prefix& list){
	char eanNum[14];
	eanNum[0] = '\0';
	int valid = 0, loop = 1;

	
	do{
		
		cout << "Add EAN(0 to quit): ";
		is.getline(eanNum, 14);
			
		if( strlen(eanNum)== 0 ){
			is.clear();
			is.ignore(2000,'\n');
			cerr << "Error. Try Again." << endl; 
		}
		else if ( strcmp(eanNum,"0") == 0 ){
			loop = 0;
			cout << "<-Returning to menu" << endl;
		}
		 else if(strlen(eanNum)!= 13){
                        cerr << "Incorrect number of digits. Try Again" << endl;

                }
		else if( !isValid(eanNum) ){
			cout << "Invalid check digit. Try again." << endl;
		}
		else{
			strcpy(ean, eanNum);
			*this = EAN(eanNum, list);
			loop = 0;
			valid = 1;
		}
	
			
	
		
	}while(loop == 1);	
	
	return valid;
}

 void EAN::display(std::ostream& os) const {
	char eanNum[18];
	eanNum[0] = '\0'; 
	toStrWithStyle(eanNum);

	os << right << setw(17) <<  eanNum;
}

bool operator==(const EAN& left, const EAN& right) {
 	char lstr[18] = {'\0'};	
 	char rstr[18] = {'\0'};

	left.toStr(lstr);
	right.toStr(rstr);
	
	if (strcmp(lstr,rstr) == 0)
		return true;
	else 
		return false;

}


std::ostream& operator<<(std::ostream& os, const EAN& ean){
	ean.display(os);
}
