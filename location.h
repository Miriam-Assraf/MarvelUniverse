#ifndef __LOCATION_H
#define __LOCATION_H

#include <iostream>
using namespace std;

class Location
{
private:
	char* name;
	bool destroyed;

public:
	Location(const char* name);
	~Location();

	void setDestroyed();	// can destroy only once, can't undestroy

	char* getName() const { return name; };
	bool getDestoyed() const { return destroyed; };

	friend ostream& operator<<(ostream& os, const Location& location);
	friend istream& operator>>(istream& is, Location& location);
};

#endif // !__LOCATION_


