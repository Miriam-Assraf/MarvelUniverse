#pragma warning(disable: 4996)

#include "character.h"
#include "location.h"
#include "universe.h"


const char* Character::speciesStr[3] = { "Human", "God", "Alien" };

Character::Character(const char* name, const Location& origin, eSpecies species): universe(nullptr), strength(MAX_STRENGTH), wins(0), losses(0), numStones(0)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->origin = &origin;
	this->species = species;
	infinityStones = new const InfinityStone*[NUM_STONES];
}

Character::Character(const Character& other) : universe(nullptr), strength(MAX_STRENGTH), wins(0), losses(0), numStones(0)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	origin = other.origin;
	species = other.species;
	infinityStones = new const InfinityStone * [NUM_STONES];
}

Character::~Character()
{
	delete[]name;
	delete[]infinityStones;
}

void Character::setUniverse(const Universe& Universe)
{
	universe = universe;
}

bool Character::collectInfinityStones(Character& other) 
{
	if (other.getNumStones() > 0)
	{
		this->infinityStones = other.infinityStones;
		this->numStones = other.numStones;

		other.infinityStones = nullptr;
		other.numStones = 0;

		return true;
	}

	return false;
}

void Character::collectInfinityStone(const InfinityStone& infinityStone)
{
	this->infinityStones[numStones] = &infinityStone;
	numStones += 1;
}

bool Character::attack(Character& other, int hit) const
{
	int rand = std::rand() % 2;
	if (rand == 0)
		return false;

	if (other.getStrength() >= hit)
		other.strength -= hit;
	else
		other.strength = MIN_STRENGTH;

	return true;
}

const Character& Character::operator>=(const Character& other) const
{
	if (this->strength >= other.getStrength())
	{
		return *this;
	}

	return other;
}

const Character& Character::operator<=(const Character& other) const
{
	if (this->strength <= other.getStrength())
	{
		return *this;
	}

	return other;
}

ostream& operator<<(ostream& os, const Character& character)
{
	os << "Name: " << character.name << "\n" << "Strength: " << character.strength << "\tWins: " << character.wins << "\tLosses: " << character.losses << "\nSpecies: " << Character::speciesStr[(int)character.species] << "\nOrigin: "<< *(character.origin) << "\nOwns " << character.numStones << " stones\n";
	if (character.numStones > 0)
	{
		for (int i = 0; i < character.numStones; i++)
		{
			os << (i + 1) << ")" << *(character.getInfinityStones()[i]);
		}
	}
	character.toOstream(os);
	return os;
}

istream& operator>>(istream& is, Character& character)
{
	char* locationName = new char[10];
	int species;

	is >> character.name;
	is >> locationName;
	is >> species;

	character.species = (Character::eSpecies)species;
	Location* location = (*character.universe)[locationName];

	if (location == nullptr)
	{
		Location newLocation(locationName);
		character.universe->addNewLocation(newLocation);
		location = &newLocation;
	}

	character.origin = location;

	return is;
}