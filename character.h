#ifndef __CHARACTER_H
#define __CHARACTER_H

#include <iostream>
using namespace std;

class Universe;
class InfinityStone;
class Location;

const int MAX_STRENGTH = 100;
const int MIN_STRENGTH = 0;

class Character
{
public:
	static const char* speciesStr[3];
	enum eSpecies { HUMAN, GOD, ALIEN };

private:
	char* name;
	int strength;
	int wins;
	int losses;
	Universe* universe;
	const Location* origin;	// can't change origin after creation
	eSpecies species;
	const InfinityStone** infinityStones;
	int numStones;

protected:
	Character(const char* name, const Location& origin, eSpecies species);
	Character(const Character& other);
	Character(const Character&& other);
	const Character& operator=(const Character& other);

public:
	virtual ~Character();

	char* getName() const { return name; };
	eSpecies getSpecies() const { return species; };
	int  getStrength() const { return strength; };
	const Location* getOrigin() const { return origin; };
	const InfinityStone** getInfinityStones() const { return infinityStones; };
	int getNumStones() const { return numStones; };

	void setUniverse(const Universe& Universe);

	void setWins() { wins += 1; };
	void setLosses() { losses += 1; };
	bool collectInfinityStones(Character& other);
	void collectInfinityStone(const InfinityStone& infinityStone);
	bool attack(Character& other, int hit) const; 

	void operator-=(int hit) { strength -= 1; };	// lower strength when attacked
	const Character& operator>=(const Character& other) const;
	const Character& operator<=(const Character& other) const;

	friend ostream& operator<<(ostream& os, const Character& character);
	virtual void toOstream(ostream& os) const {};
	friend istream& operator>>(istream& is, Character& character);
	virtual void toIstream(istream& is) {};
};

#endif

