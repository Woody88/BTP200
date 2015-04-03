#include <iostream>
#include "EAN.h"

class Order {

private:

EAN ean;
int ordered, delivered;

public:

Order();
Order(const EAN& ean);
EAN& getEAN();
bool add(std::istream& is);
bool add(int n);
bool receive(std::istream& is);
void display(std::ostream& os) const;
int outstanding() const;
};

std::ostream& operator<<(std::ostream& os, const Order& order);
