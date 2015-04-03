// Workshop 3-4 - Classes and Dynamic Memory
// w3-4.cpp

#include <iostream>
#include "Molecule.h"
using namespace std;


 int main() {
     int n;
     Molecule* molecule;	
     cout << "Molecular Information\n";
     cout << "=====================" << endl;

     cout << "Number of Molecules : ";
     cin >> n;

     // allocate dynamic memory for an array of n Molecules
     molecule = new Molecule[n];

     for (int i = 0; i < n; i++) {
         char symbol[21];
         char description[201];
         double weight;

         //insert logic that reads input for a single Molecule
         // insert logic that constructs a single Molecule
         // insert logic that copies the Molecule into an element of the array
     	 cout << "Enter Structure: ";
	 cin.ignore(1000, '\n');
         cin.clear();
	 cin.get(symbol, 10, '\n');
	 cout << "Enter Full Name: ";
	 cin.ignore(1000, '\n');
         cin.clear();
	 cin.get(description, 30, '\n');
	 cout << "Enter Weight : ";
	 cin.ignore(1000, '\n');
         cin.clear();
	 cin >> weight;
	 molecule[i] = Molecule(symbol, description, weight);
 

     }
     cout << endl;

     cout << "Structure     Mass Name\n";
     cout << "========================================" << endl; 

     for (int i = 0; i < n; i++) {
         molecule[i].display();
         cout << endl;
     }

     // deallocate dynamic memory for the array of n Molecules
     delete [] molecule; 
	molecule= nullptr;
}
