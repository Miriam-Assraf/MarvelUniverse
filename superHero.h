#ifndef __SUPERHERO_H
#define __SUPERHERO_H

#include "hero.h"

class SuperPower;

class SuperHero : public Hero
{
protected:
	SuperPower** superPowers;
	int maxSuperPowers;
	int numSuperPowers;

	SuperHero(const SuperHero& other);
	const SuperHero operator=(const SuperHero& other);

public:
	SuperHero(const Hero& hero, int maxSuperPowers);
	virtual ~SuperHero();

	SuperPower** getSuperPowers() const { return superPowers; };
	void addSuperPower(const SuperPower& superPower);

	virtual void toOstream(ostream& os) const override;
	virtual void toIstream(istream& is) override;
};

#endif // !__SUPERHERO_H


