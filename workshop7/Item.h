class Item {
private:
int itemNumber;
double itemPrice;

public:
Item();	
void operator=(int n);
void operator=(double p); 									//- resets the item's price to p
bool empty() const; 											//- returns false if the current object contains valid data; true if it is in a safe empty state
void display(std::ostream& os) const; 						//- inserts into os the item number left-justified in a field width of 8 followed by the item's price right-justified in a field of 10 to 2 decimal places

};

std::istream& operator>>(std::istream& is, Item& i); 		//- extracts data from is and stores it in i if the data is valid
std::ostream& operator<<(std::ostream& os, const Item& i); 	//- inserts into os the data in i in the format described above