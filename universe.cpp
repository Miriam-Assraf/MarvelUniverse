#include "universe.h"
#include  "infinityStone.h"
#include "location.h"
#include "ensemble.h"
#include "character.h"


int Universe::numLocations = 0;
int Universe::numCharacters = 0;
int Universe::numEnsembles = 0;

Universe::Universe(InfinityStone* const* allStones): allStones(allStones)
{
	allCharacters = new Character*[maxInstances];
	allLocations = new Location*[maxInstances];
	allEnsembles = new Ensemble*[maxInstances];
}

Universe::~Universe()
{
	for (int i = 0; i < numLocations; i++)
		delete allLocations[i];

	delete[]allLocations;

	for (int i = 0; i < NUM_STONES; i++)
		delete allStones[i];

	delete[]allStones;

	for (int i = 0; i < numEnsembles; i++)
		delete allEnsembles[i];

	delete[]allEnsembles;

	for (int i = 0; i < numCharacters; i++)
		delete allCharacters[i];

	delete[]allCharacters;
}

void Universe::addNewCharacter(Character& character)
{
	this->allCharacters[numCharacters] = &character;
	numCharacters += 1;
	character.setUniverse(*this);
}

void Universe::addNewEnsemble(Ensemble& ensemble)
{
	this->allEnsembles[numEnsembles] = &ensemble;
	numEnsembles += 1;
}

void Universe::addNewLocation(Location& location)
{
	this->allLocations[numLocations] = &location;
	numLocations += 1;
}

const InfinityStone* Universe::operator[](InfinityStone::eStoneType stoneType)
{
	for (int i = 0; i < NUM_STONES; i++)
	{
		if (allStones[i]->getType() == stoneType)
		{
			return allStones[i];
		}
	}
	return nullptr;
}

Ensemble* Universe::getEnsemble(const char* ensembleName)
{
	for (int i = 0; i < numEnsembles; i++)
	{
		if (strcmp(allEnsembles[i]->getName(), ensembleName) == 0)
		{
			return allEnsembles[i];
		}
	}
	return nullptr;
}

Character* Universe::getCharacter(const char* characterName)
{
	for (int i = 0; i < numCharacters; i++)
	{
		if (strcmp(allCharacters[i]->getName(), characterName) == 0)
		{
			return allCharacters[i];
		}
	}
	return nullptr;
}

Location* Universe::operator[](const char* locationName)
{
	for (int i = 0; i < numLocations; i++)
	{
		if (strcmp(allLocations[i]->getName(), locationName) == 0)
		{
			return allLocations[i];
		}
	}
	return nullptr;
}

ostream& operator<<(ostream& os, const Universe& universe)
{
	os << universe.name << "\n";
	os << "All characters: \n";
	for (int i = 0; i < universe.getNumCharacters(); i++)
	{
		os << (i+1) << ")" << *(universe.allCharacters[i]) << "\n";
	}
	os << "All ensembles: \n";
	for (int i = 0; i < universe.getNumEnsembles(); i++)
	{
		os << (i + 1) << ")" << *(universe.allEnsembles[i]) << "\n";
	}
	os << "All locations: \n";
	for (int i = 0; i < universe.getNumLocations(); i++)
	{
		os << (i + 1) << ")" << *(universe.allLocations[i]) << "\n";
	}
	os << "All infinity stones: \n";
	for (int i = 0; i < NUM_STONES; i++)
	{
		os << (i + 1) << ")" << *(universe.allStones[i]) << "\n";
	}

	return os;
}