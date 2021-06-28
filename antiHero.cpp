#include "antiHero.h"
#include "character.h"
#include "hero.h"
#include "villain.h"
#include "superHero.h"

AntiHero::AntiHero(const Hero& hero, const Villain& villain): Character(hero), SuperHero(hero, 0), Villain(villain) {}

AntiHero::AntiHero(const SuperHero& superHero, const Villain& villain): Character(superHero), SuperHero(superHero), Villain(villain) {}