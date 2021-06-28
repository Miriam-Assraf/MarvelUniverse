#ifndef __ENSEMBLE_H
#define __ENSEMBLE_H

#include <iostream>
using namespace std;

class Hero;

class Ensemble
{
private:
	char* name;
	const Hero** members;
	int maxMembers;
	int numOfMemebers;

	// cant copy ensemble
	Ensemble(const Ensemble& other);
	const Ensemble operator=(const Ensemble& other);

public:
	Ensemble(const char* name, int maxMembers);
	~Ensemble();

	char* getName() const { return name; };
	const Hero** getAllMemebers() const { return members; };

	void addMember(Hero& member);
	void removeMember(Hero& member);

	const Hero* operator[](const char* memberName);

	friend ostream& operator<<(ostream& os, const Ensemble& ensemble);
	friend istream& operator>>(istream& is, Ensemble& ensemble);
};

#endif // !__ENSEMBLE_H



