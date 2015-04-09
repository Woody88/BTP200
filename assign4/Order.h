#include <iostream>
#include "EAN.h"

class iOrder {

	virtual EAN& getEAN()= 0;
	virtual bool add(int) = 0;
	virtual bool add(std::istream&)= 0;
	virtual bool receive(std::istream&)= 0;
	virtual int outstanding() const = 0;
	virtual void display(std::ostream&) const = 0;
};


class Order :public iOrder {

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

class SpecialOrder : public Order {
	private:

	char instruction[61];
	
	public: 
	
	SpecialOrder();
	SpecialOrder(const EAN& isbn, const char* instr);
	SpecialOrder(const SpecialOrder& source);
	SpecialOrder& operator=(const SpecialOrder& source);
	~SpecialOrder();
	bool add(std::istream& is);
	void display(std::ostream& os) const;
		
	
};
std::ostream& operator<<(std::ostream& os, const Order& order);
