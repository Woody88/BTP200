#include <iostream>

class Fraction {

int num, denom, i;
bool num_sign, denom_sign;

public:
        void set(int, int);
        void simplify();
        int gcd(int, int);
        void display();
};

