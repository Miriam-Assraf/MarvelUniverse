#ifndef __INFINITYSTONE_H
#define __INFINITYSTONE_H

#include <iostream>
using namespace std;

class Location;

class InfinityStone
{
public:
	static const char* typesStr[6];
	static const char* colorsStr[6];
	enum eStoneType { POWER, REALITY, TIME, SPACE, MIND, SOUL };
	enum eStoneColor { PURPLE, BLUE, RED, GREEN, YELLOW, ORANGE };

private:
	// can't change type or color after creation
	const eStoneType type;
	const eStoneColor color;
	Location* location;

	InfinityStone(const InfinityStone& other);
	const InfinityStone& operator=(const InfinityStone& other);

public:
	InfinityStone(const eStoneType type, const eStoneColor color);

	eStoneType getType() const { return type; };
	eStoneColor getColor() const { return color; };
	Location* getLocation() const { return location; };

	void setLocation(Location& location);

	friend ostream& operator<<(ostream& os, const InfinityStone& stone);
};

#endif // !__INFINITYSTONE_H


