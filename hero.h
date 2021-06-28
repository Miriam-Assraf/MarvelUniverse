#ifndef __HERO_H
#define __HERO_H

#include <iostream>
using namespace std;

#include "character.h"

class Ensemble;
class Location;

const int MAX_INTEGRITY = 100;
const int MIN_INTEGRITY = 50;

class Hero : virtual public Character
{
protected:
	int integrity;
	int numEnsembles;
	int maxEnsembles;
	const Ensemble** ensembles;

	Hero(const Hero& other);
	Hero(const Hero&& other);
	const Hero operator=(const Hero& other);

public:
	Hero(const char* name, const Location& origin, Character::eSpecies species, int maxEnsembles, int integrity);
	virtual ~Hero();

	void addToEnsamble(const Ensemble& ensemble);
	void removeFromEnsemble(const Ensemble& ensemble);

	int  getIntegrity() const { return integrity; };
	const Ensemble** getEnsembles() const { return ensembles; };

	const Hero& operator++();
	const Ensemble* operator[](const char* ensembleName);

	virtual void toOstream(ostream& os) const override { os << "Integrity: " << integrity << "\n"; };
	virtual void toIstream(istream& is) override { is >> integrity; };
};

#endif

