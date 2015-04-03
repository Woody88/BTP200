// EAN.H 
// BTP200
// WOODSON DELHIA

struct Prefix;

bool isValid(const char* str);

bool isRegistered(const Prefix* p, const char* str, char area[],
	char publisher[], char title[]);
