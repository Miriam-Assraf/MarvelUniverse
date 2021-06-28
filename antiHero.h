#ifndef __ANTIHERO_H
#define __ANTIHERO_H

#include "hero.h"
#include "villain.h"
#include "superHero.h"

class AntiHero : public SuperHero, public Villain
{
private:
	AntiHero(const AntiHero& other);
	const AntiHero operator=(const AntiHero& other);

public:
	AntiHero(const Hero& hero, const Villain& villain);
	AntiHero(const SuperHero& superHero, const Villain& villain);

	virtual void toOstream(ostream& os) const override { SuperHero::toOstream(os); Villain::toOstream(os); };
	virtual void toIstream(istream& is) override { SuperHero::toIstream(is); Villain::toIstream(is); };
};

#endif // !__ANTIHERO_H


