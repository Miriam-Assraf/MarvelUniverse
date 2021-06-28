#ifndef __SUPERVILLAIN_H
#define __SUPERVILLAIN_H

#include "villain.h"

class SuperPower;

class SuperVillain : public Villain
{
protected:
	SuperPower** superPowers;
	int maxSuperPowers;
	int numSuperPowers;

	SuperVillain(const SuperVillain& other);
	const SuperVillain operator=(const SuperVillain& other);

public:
	SuperVillain(const Villain& villain, int maxSuperPowers);
	virtual ~SuperVillain();

	SuperPower** getSuperPowers() const { return superPowers; };
	void addSuperPower(const SuperPower& superPower);

	virtual void toOstream(ostream& os) const override;
	virtual void toIstream(istream& is) override;
};

#endif

