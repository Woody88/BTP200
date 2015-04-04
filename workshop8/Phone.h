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
