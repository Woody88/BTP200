#include <iostream> 
#include "Sum.h"

using namespace std;

int main(){
	int n=0;
	cout<<"how many numbers to sum together? ";
	cin>>n;
	Sum list(n);

	do{
		if(cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');

		}
		cout<<"Add a number to the sum (0 to quit):";
		if(cin>>n && n!=0){
			list+=n;
			cout << "next should be in operator" << endl;
		}
		else if(cin.fail())
			cerr<<"Error, please re-enter"<<endl;
	}while(cin.fail() || n !=0  );
	list.display();

	cout<<"--------------------------------------"<<endl;
	cout<<"Copy Tests(Should not crash/Segfault!)"<<endl;
	Sum blank;
	int numbers[]={1,2,3,4};
	Sum set(numbers,4);

	cout<<"Copy Constructor"<<endl;
	Sum New=set;
	cout<<"Operator= Tests"<<endl;
	blank=set;
	cout<<"self Assignment"<<endl;
	set=set;
	cout<<"Destructor/safe copy test"<<endl;
	Sum * dest=new Sum();
	*dest=set;
	delete dest;
	set.display();
}
