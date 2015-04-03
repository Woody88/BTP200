#include <iostream>

using namespace std;

#include "Fraction.h"

void Fraction::set(int x, int y){

        num = x;
        denom = y;
	        
	if(num == 0 || denom == 0){
	
	}
	else
		simplify();
}

void Fraction::simplify(){

        int a, b, result;
	num_sign = false;
	denom_sign = false;

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
		else {
			a = num;
		}
                if (denom < 0) {
                        denom_sign = true;
                        b = denom * -1;
                }
		else {
			b = denom;
		}
                result = gcd(a, b);
                i++;
                if(num_sign){
                        a = a * -1;
                }
                if (denom_sign) {
                        b = b * -1;
                }
                num = a/result; 
		denom = b/result;
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
        if(denom == 0 ){
		if(num == 0)
			cout << num << "/" << denom;
		else 
			cout << "Undefined";
	}
	else
		cout << num << "/" << denom;
}

