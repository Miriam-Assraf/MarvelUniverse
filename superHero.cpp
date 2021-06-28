#include "superHero.h"
#include "hero.h"
#include "character.h"
#include "superPower.h"

SuperHero::SuperHero(const Hero& hero, int maxSuperPowers): Character(hero), Hero(hero), maxSuperPowers(maxSuperPowers), numSuperPowers(0)
{
	superPowers = new SuperPower*[maxSuperPowers];
}

SuperHero::SuperHero(const SuperHero& other): Character(other), Hero(other), maxSuperPowers(other.maxSuperPowers), numSuperPowers(0)
{
	superPowers = new SuperPower * [maxSuperPowers];
}

SuperHero::~SuperHero()
{
	for (int i = 0; i < numSuperPowers; i++)
		delete superPowers[i];

	delete[]superPowers;
}

void SuperHero::addSuperPower(const SuperPower& superPower)
{
	if (numSuperPowers < maxSuperPowers)
	{
		superPowers[numSuperPowers] = new SuperPower(superPower);
		numSuperPowers += 1;
	}
}

void SuperHero::toOstream(ostream& os) const
{
	os << "Super Powers:\n";
	for (int i=0; i<numSuperPowers; i++)
		os << (i+1) << ")" << *(superPowers[i]) << "\n";
}

void SuperHero::toIstream(istream& is)
{
	is >> maxSuperPowers;
}