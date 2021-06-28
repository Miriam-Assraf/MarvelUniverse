#include "superPower.h"

const char* SuperPower::powersStr[10] = { "Flight", "Weather manipulation", "Electricity manipulation", "Teleporatation", "Super strength", "Transformation", "Telepathy", "Superspeed", "Telekinesis", "Regeneration" };

SuperPower::SuperPower(ePowerType type): type(type), level(MIN_LEVEL) {}

SuperPower& SuperPower::operator++()
{
	if (level < MAX_LEVEL)
	{
		level++;
	}

	return *this;
}

const SuperPower& SuperPower::operator>=(const SuperPower& other)
{
	if (this->level >= other.level)
		return *this;

	return other;
}

const SuperPower& SuperPower::operator<=(const SuperPower& other)
{
	if (this->level <= other.level)
		return *this;

	return other;
}

ostream& operator<<(ostream& os, const SuperPower& superPower)
{
	os << "Super Power: " << SuperPower::powersStr[(int)superPower.type] << "\tLevel: " << superPower.level << "\n";
	return os;
}

istream& operator>>(istream& is, SuperPower& superPower)
{
	int type;

	is >> type;
	superPower.type = (SuperPower::ePowerType)type;

	return is;
}