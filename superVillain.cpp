#include "superVillain.h"
#include "villain.h"
#include "character.h"
#include "superPower.h"

SuperVillain::SuperVillain(const Villain& villain, int maxSuperPowers): Character(villain), Villain(villain), maxSuperPowers(maxSuperPowers), numSuperPowers(0)
{
	superPowers = new SuperPower * [maxSuperPowers];
}

SuperVillain::SuperVillain(const SuperVillain& other): Character(other), Villain(other), maxSuperPowers(other.maxSuperPowers), numSuperPowers(0)
{
	superPowers = new SuperPower * [maxSuperPowers];
}

SuperVillain::~SuperVillain()
{
	for (int i = 0; i < numSuperPowers; i++)
		delete superPowers[i];

	delete[]superPowers;
}

void SuperVillain::addSuperPower(const SuperPower& superPower)
{
	if (numSuperPowers < maxSuperPowers)
	{
		superPowers[numSuperPowers] = new SuperPower(superPower);
		numSuperPowers++;
	}
}

void SuperVillain::toOstream(ostream& os) const 
{
	os << "Super Powers:\n";
	for (int i = 0; i < numSuperPowers; i++)
		os << (i + 1) << ")" << *(superPowers[i]) << "\n";
}

void SuperVillain::toIstream(istream& is)
{
	is >> maxSuperPowers;
}