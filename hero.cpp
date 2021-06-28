#include "character.h"
#include "hero.h"
#include "ensemble.h"

Hero::Hero(const char* name, const Location& origin, Character::eSpecies species, int maxEnsembles, int integrity): Character(name, origin, species), maxEnsembles(maxEnsembles), numEnsembles(0)
{
	ensembles = new const Ensemble*[maxEnsembles];
	if (this->integrity < MIN_INTEGRITY)
		this->integrity = MIN_INTEGRITY;
	else if (this->integrity > MAX_INTEGRITY)
		this->integrity = MAX_INTEGRITY;
	else
		this->integrity = integrity;
}

Hero::Hero(const Hero& other): Character(other), maxEnsembles(other.maxEnsembles), numEnsembles(0)
{
	ensembles = new const Ensemble * [maxEnsembles];
	if (other.integrity < MIN_INTEGRITY)
		integrity = MIN_INTEGRITY;
	else if (other.integrity > MAX_INTEGRITY)
		integrity = MAX_INTEGRITY;
	else
		integrity = other.integrity;
}

Hero::~Hero()
{
	delete[]ensembles;
}

void Hero::addToEnsamble(const Ensemble& ensemble)
{
	this->ensembles[numEnsembles] = &ensemble;
	numEnsembles += 1;
}

void Hero::removeFromEnsemble(const Ensemble& ensemble)
{
	int ensemble_idx = -1;

	for (int i = 0; i < numEnsembles; i++)
	{
		if (ensembles[i] == &ensemble)
		{
			ensemble_idx = i;
		}
	}

	if (ensemble_idx >= 0)
	{
		numEnsembles -= 1;

		for (int i = ensemble_idx; i < numEnsembles; i++)
		{
			ensembles[i] = ensembles[i + 1];
		}
		ensembles[numEnsembles] = nullptr;
	}
}

const Hero& Hero::operator++() 
{ 
	if (integrity < MAX_INTEGRITY)
		integrity += 5;

	return *this;
}

const Ensemble* Hero::operator[](const char* ensembleName)
{
	for (int i = 0; i < numEnsembles; i++)
	{
		if (strcmp(ensembleName, ensembles[i]->getName()) == 0)
		{
			return ensembles[i];
		}
	}

	return nullptr;
}
