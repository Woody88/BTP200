//Workshop 2 - Fraction Simplifier
//w2.cpp

#include <iostream>
using namespace std;
#include "Fraction.h"

 int main() {
     Fraction fraction;
     int num, den;

     cout << "Fraction Simplifier" << endl;
     cout << "===================" << endl;

     cout << "Numerator   : ";
     cin >> num;
     cout << "Denominator : ";
     cin >> den;
     cout << endl;

     fraction.set(num, den);
     fraction.display();
     cout << endl;
 }
