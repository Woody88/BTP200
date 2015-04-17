#include "iFood.h"

class iFood;

class Pizza : public iFood {

	double diameter;
	int totalSlices, consumed;
	
	public:

	Pizza();
	Pizza(double x, int y);
	int portions() const;
	void consume();
	int remaining() const;
	void display() const;

};

class DeluxePizza : public Pizza {
	char toppings[40];

	public:

	DeluxePizza();
        DeluxePizza(double x, int y, char* top);
        void display() const;

};
