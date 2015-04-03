// GS1Prefix.h 
// BTP200 - Assignment 1
// WOODSON DELHIA
const int MAX = 700;

/////////////////////////////////////////////////////
// Prefix object that will contain prefixRanges.txt  //  
///////////////////////////////////////////////////
struct Prefix {

	int  no;             // number of entries
	int  area[MAX];      // area elements
	char pubLow[MAX][8]; // low end of publisher range
	char pubHgh[MAX][8]; // high end of publisher range
	int  pubLen[MAX];    // no of chars in publisher string

};

bool isRegistered(const Prefix* p, int area);
int minNoDigits(const Prefix* p, int area);
bool isRegistered(const Prefix* p, int area, const char* publisher);
bool load(const char*, Prefix*);
