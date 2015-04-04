#include <string>
using namespace std;
class Phone {
	int area, n;
	
	public:
	
	Phone();
	Phone(int a, int b);
	void display() const;
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
