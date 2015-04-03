#include <iostream>
#include <cstring>
#include <iomanip>
#include "Molecule.h"
using namespace std;

Molecule::Molecule(){
	symbol[0] = '\0';
	description[0] ='\0';
	weight = 0.000;
}

Molecule::Molecule(char* sym, char* desc, double w){
	
	//if (symbol == '\0'){
		strcpy(symbol, sym);
		//symbol[10-1] = '\0';
	//}

	//if ( description == '\0'){
		strcpy(description, desc);
		//description[30-1] = '\0';
	//}
	
	weight = w;

}

void Molecule::display() const {

	if(symbol == '\0' && description == '\0' && weight == 0.000){
		cout << "No Data Available" << endl;
	}
	else{
		cout << left << setw(10) << symbol;
		cout << fixed << setprecision(3); 
		cout << right << setw(7) << weight;  
		cout << " " << description << endl;
		cout.unsetf(ios::right);
	}
}	
