class Molecule {
	char symbol[10];
	char description[30];
	double weight;

	public:
		void display() const;
		Molecule(); 
		Molecule(char*, char*, double);
};

