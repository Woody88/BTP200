#include <iostream>
 using namespace std;
 #include "Fraction.h"

 int unitTests(Fraction* f) {

     cout << "Fraction Simplifier Tests" << endl; 
     cout << "=========================" << endl;

     // fill in code for unit tests
	int result = 0, num, denom, allResult = 1;
 	

		result = testSuite(f, 4, 16, 1, 4);
		if(result){
			cout << "Test 1" << " Passed" << endl;
			f->display();
		}else{ 	
			cout << "Test 1" << " Failed" << endl;
			allResult = 0;
			f->display();
		}

		result = testSuite(f, -4, 16, -1, 4);
                if(result){
                        cout << "Test 2" << " Passed" << endl;
                        f->display();
                }else{
                        cout << "Test 2" << " Failed" << endl;
                        allResult = 0;
			f->display();
		}

		result = testSuite(f, 0, 16, 0, 16);   
                if(result){
                        cout << "Test 3" << " Passed" << endl;
                        f->display();
                }else{
                        cout << "Test 3" << " Failed" << endl;
                        allResult = 0;
			f->display();
                }
		
		result = testSuite(f, 0, 0, 0, 0);   
                if(result){
                        cout << "Test 4" << " Passed" << endl;
                        f->display();
                }else{
                        cout << "Test 4" << " Failed" << endl;
                        allResult = 0;
			f->display();
                }

		result = testSuite(f, 4, 0, 4, 0);   
                if(result){
                        cout << "Test 5" << " Passed" << endl;
                        f->display();
                }else{
                        cout << "Test 5" << " Failed" << endl;
                        allResult = 0;
			f->display();
                }		

	return allResult;
}

 int main() {
     Fraction fraction;
     bool passed;

     passed = unitTests(&fraction);

     if (passed)
         cout << "Passed All Tests" << endl;
     else
         cout << "Failed Tests" << endl;
 }

