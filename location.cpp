#pragma warning(disable: 4996)

#include "location.h"

Location::Location(const char* name): destroyed(false)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Location::~Location()
{
	delete[]name;
}

void Location::setDestroyed()
{
	if (!destroyed)
	{
		destroyed = true;
	}
}

ostream& operator<<(ostream& os, const Location& location)
{
	os << "Location: " << location.name << "\tDestroyed = " << location.destroyed << "\n";
	return os;
}

istream& operator>>(istream& is, Location& location)
{
	is >> location.name;

	return is;
}