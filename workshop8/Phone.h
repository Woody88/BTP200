#include <string>
using namespace std;
class Phone {
	int area, n;
	
	public:
	
	Phone();
	Phone(int a, int b);
	virtual void display() const;
	bool isValid() const;	
};

class IntlPhone : public Phone {
	int intl;

	public:	
	IntlPhone();
	IntlPhone(int a,int b, int c);
	void display() const;
	bool isValid() const;

};

std::istream& operator>>(std::istream&, Phone& p);
std::istream& operator>>(std::istream&, IntlPhone& p);
std::ostream& operator<<(std::ostream&, const Phone& p);
std::ostream& operator<<(std::ostream&, const IntlPhone& p);
