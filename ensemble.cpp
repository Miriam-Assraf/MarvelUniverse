#pragma warning(disable: 4996)

#include "ensemble.h"
#include "character.h"
#include "hero.h"

Ensemble::Ensemble(const char* name, int maxMembers): maxMembers(maxMembers)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	members = new const Hero*[maxMembers];
}

Ensemble::~Ensemble()
{
	delete[]name;
	delete[]members;
}

void Ensemble::addMember(Hero& member)
{
	this->members[numOfMemebers] = &member;
	numOfMemebers += 1;

	member.addToEnsamble(*this);
}

void Ensemble::removeMember(Hero& member)
{
	int member_idx = -1;

	for (int i = 0; i < numOfMemebers; i++)
	{
		if (this->members[i] == &member)
		{
			member_idx = i;
		}
	}

	if (member_idx >= 0)
	{
		numOfMemebers -= 1;

		for (int i = member_idx; i < numOfMemebers; i++)
		{
			members[i] = members[i + 1];
		}
		members[numOfMemebers] = nullptr;

		member.removeFromEnsemble(*this);
	}
}

const Hero* Ensemble::operator[](const char* memberName)
{
	for (int i = 0; i < numOfMemebers; i++)
	{
		if (strcmp(memberName, members[i]->getName()) == 0)
		{
			return members[i];
		}
	}
	return nullptr;
}

ostream& operator<<(ostream& os, const Ensemble& ensemble)
{
	os << "Ensemble: " << ensemble.name << " \tTotal members: " << ensemble.numOfMemebers << "\n";
	for (int i = 0; i < ensemble.numOfMemebers; i++)
	{
		os << (i + 1) << ")" << *ensemble.members[i] << "\n";
	}

	return os;
}

istream& operator>>(istream& is, Ensemble& ensemble)
{
	is >> ensemble.name;
	is >> ensemble.maxMembers;

	return is;
}