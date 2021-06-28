#ifndef __UNIVERSE_H
#define __UNIVERSE_H

#include <iostream>
using namespace std;

#include "infinityStone.h"
#include "character.h"

class Ensemble;
class Location;

const int NUM_STONES = 6;

class Universe
{
private:
	static int numLocations;
	static int numCharacters;
	static int numEnsembles;

	const char* name = "Marvel Universe";
	const int maxInstances = 10;
	Location** allLocations;
	Character** allCharacters;
	InfinityStone *const* allStones;	// can't change pointers
	Ensemble** allEnsembles;
	Universe(const Universe& other);	// we can't copy universe
	void operator=(const Universe& other);

public:
	Universe(InfinityStone* const* allStones);
	~Universe();

	int getNumLocations() const { return numLocations; };
	int getNumCharacters() const { return numCharacters; };
	int getNumEnsembles() const { return numEnsembles; };

	Location** getLocations() const { return allLocations; };
	Character** getCharacters() const { return allCharacters; };
	InfinityStone * const* getInfinityStones() const { return allStones; };
	Ensemble** getEnsembles() const { return allEnsembles; };

	friend void Character::setUniverse(const Universe& universe);

	void addNewCharacter(Character& character);
	void addNewEnsemble(Ensemble& ensemble);
	void addNewLocation(Location& location);

	Ensemble* getEnsemble(const char* ensembleName);
	Character* getCharacter(const char* characterName);

	Location* operator[](const char* locationName);
	const InfinityStone* operator[](InfinityStone::eStoneType stoneType);

	friend ostream& operator<<(ostream& os, const Universe& universe);
};

#endif // !__UNIVERSE_H
