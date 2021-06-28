#include "character.h"
#include "villain.h"
#include "location.h"

Villain::Villain(const char* name, const Location& origin, Character::eSpecies species, int vicious): Character(name, origin, species) 
{
	if (this->vicious < MIN_VICIOUS)
		this->vicious = vicious;
	else if (this->vicious > MAX_VICIOUS)
		this->vicious = MAX_VICIOUS;
	else
		this->vicious = vicious;
}

Villain::Villain(const Villain& other) : Character(other)
{
	if (other.vicious < MIN_VICIOUS)
		vicious = vicious;
	else if (other.vicious > MAX_VICIOUS)
		vicious = MAX_VICIOUS;
	else
		vicious = other.vicious;
}

bool Villain::destroy(Location& location)
{
	if (location.getDestoyed())
		return false;

	location.setDestroyed();
	return true;
}

const Villain& Villain::operator++()
{
	if (vicious + 5 <= MAX_VICIOUS)
		vicious += 5;
	else
		vicious = MAX_VICIOUS;

	return *this;
}

const Villain& Villain::operator--()
{
	if (vicious - 5 >= MIN_VICIOUS)
		vicious -= 5;
	else
		vicious = MIN_VICIOUS;

	return *this;
}
