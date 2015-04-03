class Fraction {

int num, denom, originalNum, originalDenom;
bool num_sign, denom_sign;

public:
	void set(int, int);
	void simplify();
	int gcd(int, int);
	int numerator() const;
	int denomenator() const;
	void display();
};

int testSuite(Fraction *, int, int, int, int);
