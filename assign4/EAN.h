class Prefix;

 class EAN {
	
	char ean[17];
	char area[6], publisher[8], title[7];
	char strStyle[2];
 	bool registered; 
		
	public: 
	EAN();
  	EAN(const char* str, const Prefix& list);
	bool isRegistered(const Prefix& list);
	bool empty() const;
	bool isRegistered() const;
	void style(char);
	void toStr(char* str) const;
	void toStrWithStyle(char* str) const;
	void display(std::ostream& os) const;
	bool read(std::istream& is, const Prefix& list);
};

bool isValid(const char* str);
bool operator==(const EAN& left, const EAN& right);
std::ostream& operator<<(std::ostream& os, const EAN& ean);
