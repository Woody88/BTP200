class Sum {
	int* array;
	int k, sum, size;
public:
	Sum();
	Sum(int);
	Sum(const int*, int);
	void display() const;
	Sum& operator+=(int);

};
