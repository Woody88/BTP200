#include <iostream>
#include "Sum.h"

Sum::Sum(){
	array = nullptr;
	size = sum = 0;	
}

Sum::Sum(int n){
	array = new int[n];
	array[0] = 0;
	sum = 0;
	k = 0;
	size = n;
}
Sum::Sum(const int* numbers,int nSize){	
	
	array = new int[nSize];
	array[0] = 0; 
	size = nSize;
	sum = 0;
        for(int i = 0; i < size; i++){
                array[i]+=numbers[i];
	}
}
void Sum::display() const{
	int total = 0;
	for(int i = 0; i < size; i++){
		if (i == (size-1)) {
			total+=array[i];
			std::cout << array[i] << " = " << total << std::endl;
		}
		else 
			std::cout << array[i]<< "+";
			total+=array[i];
	}
}

Sum& Sum::operator+=(int n){
	if(k < size){
		array[k] = n;
		k++;
	}
	else {
		std::cout << "No Room for anymore numbers " << n << " has not been added"<< std::endl;
	}
	return *this;
}

