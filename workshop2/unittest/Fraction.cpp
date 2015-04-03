#include <iostream>
#include "Fraction.h"
void Fraction::set(int x, int y){	
	
	originalNum = num = x;
	originalDenom = denom = y;
		if(denom == 0 || num == 0){
		}
		else{
			simplify();
		}
	
}

void Fraction::simplify(){

        int a, b, result;
     		
        if(num  == 0){
                set(0, 0);
        }
        else if (denom  == 0) {
                set(0,0);
        }

        if (num != 0 && denom != 0){
                
		if (num < 0) {
			num_sign = true;
			a = num * -1;
		}
		else
			a = num;

		if (denom < 0) {
			denom_sign = true;
			b = denom * -1;
		}
		else
			b = denom;

		result = gcd(a, b);

		if(num_sign){
			a = a * -1;
		}
		if (denom_sign) {
			b = b * -1;
		}
                num = num / result;
		denom = denom / result;
        }	
}


int Fraction::gcd(int k, int l){
        int a, b, c, d;
        a = k;
        b = l;
        c = a/b;
        d = a%b;

        if(d != 0){
                gcd(b, d);
        }
        else {
                return b;
        }

}


void Fraction::display(){
	int nume, denome;
	nume = numerator();
	denome = denomenator();
	
	if (denome == 0 || denome == 0 && nume == 0){
		std::cout << "Input: " << originalNum << "/" << originalDenom << std::endl;
		std::cout << "Output: Undefined" << std::endl;
	}
	else{
		std::cout << "Input: " << originalNum << "/" << originalDenom << std::endl;
        	std::cout << "Output: " << numerator() << "/" << denomenator() << std::endl;
	}
}

int Fraction::numerator() const {
	return num;
}

int Fraction::denomenator() const {
	return denom;
}

int testSuite(Fraction *f, int num, int denom, int resultNum, int resultDenom){
	int passed = 0;
		f->set(num,denom);
                if(f->numerator() == resultNum && f->denomenator() == resultDenom){
                        passed = 1;
                }
                else    
			 passed = 0;
	return passed;
}
