#ifndef __SUPERPOWER_H
#define __SUPERPOWER_H

#include <iostream>
using namespace std;

const int MAX_LEVEL = 10;
const int MIN_LEVEL = 1;

class SuperPower
{
public:
	static const char* powersStr[10];
	enum ePowerType { FLIGHT, WHEATHER_MANIPULATION, ELECTRICITY_MANIPULATION, TELEPORTATION, SUPERSTRENGTH, TRANSFORM, TELEPATHY, SUPERSPEED, TELEKINESIS, REGENERATION };

private:
	int level;
	ePowerType type;

public:
	SuperPower(ePowerType type);

	ePowerType getType() const { return type; }
	int getLevel() const { return level; }

	SuperPower& operator++();
	const SuperPower& operator>=(const SuperPower& other);
	const SuperPower& operator<=(const SuperPower& other);

	friend ostream& operator<<(ostream& os, const SuperPower& superPower);
	friend istream& operator>>(istream& is, SuperPower& superPower);
};

#endif

