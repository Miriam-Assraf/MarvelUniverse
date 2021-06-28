#ifndef __VILLAIN_H
#define __VILLAIN_H

#include <iostream>
using namespace std;

#include "character.h"

class Location;

const int MAX_VICIOUS = 100;
const int MIN_VICIOUS = 40;

class Villain : virtual public Character
{
protected:

	int vicious;

	Villain(const Villain& other);
	Villain(const Villain&& other);
	const Villain operator=(const Villain& other);

public:
	Villain(const char* name, const Location& origin, Character::eSpecies species, int vicious);

	bool destroy(Location& location);

	int getVicious() const { return vicious; };
	const Villain& operator++();
	const Villain& operator--();

	virtual void toOstream(ostream& os) const override { os << "Vicious: " << vicious << "\n"; };
	virtual void toIstream(istream& is) override { is >> vicious; };
};

#endif // !__VILLAIN_H

