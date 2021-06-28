#include "infinityStone.h"
#include "location.h"

const char* InfinityStone::typesStr[6] = { "Power", "Reality", "Time", "Space", "Mind", "Soul" };
const char* InfinityStone::colorsStr[6] = { "Purple", "Blue", "Red", "Green", "Yellow", "Orange" };

InfinityStone::InfinityStone(const eStoneType type, const eStoneColor color): type(type), color(color), location(nullptr){}

void InfinityStone::setLocation(Location& location)
{
	this->location = &location;
}

ostream& operator<<(ostream& os, const InfinityStone& stone)
{
	os << "Infinity Stone: " << InfinityStone::typesStr[(int)stone.type] << "\tColor: " << InfinityStone::colorsStr[(int)stone.color] << "\tCurrent location: " << *(stone.location) << "\n";
	return os;
}
