// EAN.cpp
// BTP200 - Assignment 1
// Woodson Delhia

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;	
#include "EAN.h"
#include "GS1Prefix.h"
#define  PREFIX_LIST "prefixRanges.txt"

///////////////////////////////////////////////////////////////
// Check if its a valid EAN format                          //
// Validates if first 3 digits is equal to 978 or 979      //
// Validates if ean is 13 digits                          //
// Validates Check digits				 //
//////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
// Validates if string a is valid EAN number 		   //
// If is contained in prefix table EAN is registered      //
///////////////////////////////////////////////////////////
bool isRegistered(const Prefix* p, const char* str, char area[],
	char publisher[], char title[]){
	int valid = 0, areaCheck = 0, startPos = 3, areaMax = 5, pubMax = 7, titleMax = 6, position = 0;

	area[0] = {'\0'};
	publisher[0] = {'\0'};
	title[0] = {'\0'};

	/////start at position 3 to skip first 3 digits and check if area registered/////
	for(int i = startPos; i < startPos + areaMax; i++){ 
		area[i-startPos] = str[i];
		area[(i-startPos)+1] = '\0';
		areaCheck = atoi(area);
		if(isRegistered(p, areaCheck)){
			valid = 1;
			position = i + 1;
			i = startPos + areaMax;
		}
	}

	/////If area valid check min length of that area's publisher/////
	if(valid == 1){
		int minPublen = 0;
		minPublen = minNoDigits(p, areaCheck);	
		if(minPublen == 0)
			valid =0;
			
	}
	
	/////If length found verifies if publisher is valid/////
	if(valid == 1){
		int k = 0, tempPos = 0;
		
		valid = 0;
		
		for(int i = position; i < position + pubMax; i++){
			publisher[k] = str[i];
			publisher[k+1] = '\0';
			if(isRegistered(p,areaCheck, publisher)){		
				valid = 1;
				tempPos = i;
				i = position + pubMax;
			}
			k++;
		}
		position = tempPos + 1;
	}
	
	/////If publisher valid last remaining digits aside from the last digit are the title/////
	if(valid == 1){
		int l = 0; 

		while(position < 12){
			title[l] = str[position];
			title[l+1] = '\0';
			l++;
			position++;
		}	
	}
	return valid;
}
