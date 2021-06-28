#include <iostream>
using namespace std;

#include "universe.h"
#include "location.h"
#include "character.h"
#include "hero.h"
#include "villain.h"
#include "superHero.h"
#include "superVillain.h"
#include "antiHero.h"
#include "ensemble.h"
#include "superPower.h"

void printState(const Character& user, const Character& opponent);
bool checkGameOver(Character& user, Character& opponent);
void turn(const Character& currentUser, Character& currentOpponent);
Character* getCharacter(const Universe& marvel, const Character* user);
void checkWin(Character& user, Character& opponent);

int main() {
	// Create stones!!!
	InfinityStone** infinityStones = new InfinityStone * [NUM_STONES];
	// Create infinity stones
	InfinityStone powerStone(InfinityStone::eStoneType::POWER, InfinityStone::eStoneColor::PURPLE);
	InfinityStone realltyStone(InfinityStone::eStoneType::REALITY, InfinityStone::eStoneColor::RED);
	InfinityStone timeStone(InfinityStone::eStoneType::TIME, InfinityStone::eStoneColor::GREEN);
	InfinityStone soulStone(InfinityStone::eStoneType::SOUL, InfinityStone::eStoneColor::ORANGE);
	InfinityStone spaceStone(InfinityStone::eStoneType::SPACE, InfinityStone::eStoneColor::BLUE);
	InfinityStone mindStone(InfinityStone::eStoneType::MIND, InfinityStone::eStoneColor::YELLOW);

	infinityStones[0] = &powerStone;
	infinityStones[1] = &realltyStone;
	infinityStones[2] = &timeStone;
	infinityStones[3] = &soulStone;
	infinityStones[4] = &spaceStone;
	infinityStones[5] = &mindStone;

	Universe* marvel = new Universe(infinityStones);

	// Create locations
	Location earth("Earth");
	Location xandar("Xandar");
	Location vormir("Vormir");
	Location asgard("Asgard");
	Location knowhere("Knowhere");

	marvel->addNewLocation(earth);
	marvel->addNewLocation(xandar);
	marvel->addNewLocation(vormir);
	marvel->addNewLocation(asgard);
	marvel->addNewLocation(knowhere);

	// Set stones locations
	marvel->getInfinityStones()[0]->setLocation(xandar);
	marvel->getInfinityStones()[1]->setLocation(knowhere);
	marvel->getInfinityStones()[2]->setLocation(earth);
	marvel->getInfinityStones()[3]->setLocation(vormir);
	marvel->getInfinityStones()[4]->setLocation(asgard);
	marvel->getInfinityStones()[5]->setLocation(earth);

	// Create characters
	Hero ironman("Iron Man", *(*marvel)["Earth"], Character::eSpecies::HUMAN, 5, 80);
	marvel->addNewCharacter(ironman);

	SuperHero hulk(Hero("Hulk", *(*marvel)["Earth"], Character::eSpecies::HUMAN, 5, 85), 2);
	hulk.addSuperPower(SuperPower(SuperPower::ePowerType::REGENERATION));
	hulk.addSuperPower(SuperPower(SuperPower::ePowerType::SUPERSTRENGTH));
	marvel->addNewCharacter(hulk);

	SuperHero thor(Hero("Thor", *(*marvel)["Asgard"], Character::eSpecies::GOD, 5, 100), 5);
	thor.addSuperPower(SuperPower(SuperPower::ePowerType::FLIGHT));
	thor.addSuperPower(SuperPower(SuperPower::ePowerType::WHEATHER_MANIPULATION));
	thor.addSuperPower(SuperPower(SuperPower::ePowerType::ELECTRICITY_MANIPULATION));
	thor.addSuperPower(SuperPower(SuperPower::ePowerType::TELEPORTATION));
	thor.addSuperPower(SuperPower(SuperPower::ePowerType::SUPERSTRENGTH));
	marvel->addNewCharacter(thor);

	SuperHero storm(Hero("Storm", *(*marvel)["Earth"], Character::eSpecies::HUMAN, 2, 80), 2);
	storm.addSuperPower(SuperPower(SuperPower::ePowerType::WHEATHER_MANIPULATION));
	storm.addSuperPower(SuperPower(SuperPower::ePowerType::SUPERSTRENGTH));
	marvel->addNewCharacter(storm);

	SuperVillain loki(Villain("Loki", *(*marvel)["Asgard"], Character::eSpecies::GOD, 85), 4);
	loki.addSuperPower(SuperPower(SuperPower::ePowerType::FLIGHT));
	loki.addSuperPower(SuperPower(SuperPower::ePowerType::TELEPORTATION));
	loki.addSuperPower(SuperPower(SuperPower::ePowerType::SUPERSTRENGTH));
	loki.collectInfinityStone(*(*marvel)[InfinityStone::eStoneType::SPACE]);
	marvel->addNewCharacter(loki);

	AntiHero deadpool(SuperHero(Hero("Deadpool", *(*marvel)["Earth"], Character::eSpecies::HUMAN, 4, 85), 5), Villain("Deadpool", *(*marvel)["Earth"], Character::eSpecies::HUMAN, 45));
	deadpool.addSuperPower(SuperPower(SuperPower::ePowerType::REGENERATION));
	deadpool.addSuperPower(SuperPower(SuperPower::ePowerType::SUPERSTRENGTH));
	marvel->addNewCharacter(deadpool);

	// Create ensembles
	Ensemble avengers("Avangers", 8);
	marvel->addNewEnsemble(avengers);
	marvel->getEnsemble("Avangers")->addMember(hulk);
	marvel->getEnsemble("Avangers")->addMember(thor);
	marvel->getEnsemble("Avangers")->addMember(ironman);
	marvel->getEnsemble("Avangers")->addMember(deadpool);

	Ensemble xmen("X-Men", 15);
	marvel->addNewEnsemble(xmen);
	marvel->getEnsemble("X-Men")->addMember(storm);
	marvel->getEnsemble("X-Men")->addMember(deadpool);

	cout << "Welcome to Marvel Universe!\nChoose a character:" << endl;
	Character* user = nullptr;
	while (user == nullptr)
		user = getCharacter((*marvel), user);
	cout << "Choose an opponent:" << endl;
	Character* opponent = nullptr;
	while (opponent == nullptr)
		opponent = getCharacter(*marvel, user);
	cout << "Press A to attack or other to exit" << endl;
	char opt;
	cin >> opt;

	while (opt == 'A' || opt == 'a')
	{
		turn(*user, *opponent);

		cout << "Opponents turn" << endl;
		turn(*opponent, *user);

		printState(*user, *opponent);

		bool gameOver = checkGameOver(*user, *opponent);
		if (gameOver)
			break;

		cout << "Press A to attack or other to exit" << endl;
		cin >> opt;
	}

	if (user->getStrength() != MIN_STRENGTH && opponent->getStrength() != MIN_STRENGTH)	// stopped before game over
		checkWin(*user, *opponent);	

	cout << "Your character:\n" << *user << endl;
	cout << "Your opponent:\n" << *opponent << endl;

	cout << *marvel;
}

void printState(const Character& user, const Character& opponent)
{
	cout << "Your character strength:\n" << user.getStrength() << endl;
	cout << "Your opponent strength:\n" << opponent.getStrength() << endl;
}

void checkWin(Character& user, Character& opponent)
{
	if (user.getStrength() > opponent.getStrength())
	{
		cout << "You win" << endl;
		user.setWins();
		opponent.setLosses();

		user.collectInfinityStones(opponent);
	}

	else if (user.getStrength() > opponent.getStrength())
	{
		cout << "You loose" << endl;
		user.setLosses();
		opponent.setWins();

		opponent.collectInfinityStones(user);
	}

	else // tie
	{
		cout << "It's a tie!" << endl;
	}
}

bool checkGameOver(Character& user, Character& opponent)
{
	if (user.getStrength() == MIN_STRENGTH)
	{
		cout << "You loose" << endl;
		user.setLosses();
		opponent.setWins();
		
		opponent.collectInfinityStones(user);

		return true;
	}

	if (opponent.getStrength() == MIN_STRENGTH)
	{
		cout << "You win" << endl;
		user.setWins();
		opponent.setLosses();

		user.collectInfinityStones(opponent);

		return true;
	}

	return false;
}

void turn(const Character& currentUser, Character& currentOpponent)
{
	int hit = rand() % currentOpponent.getStrength() + 1; // range 1-opponents strenght
	cout << "Hit value: " << hit << endl;

	bool succeed = currentUser.attack(currentOpponent, hit);
	if (succeed)
	{
		cout << "Succesfull hit\n";
	}

	else 
	{
		cout << "Missed\n";
	}
}

Character* getCharacter(const Universe& marvel, const Character* user)
{
	Character** allCharacters = marvel.getCharacters();

	int chosen = -1;
	int counter = 1;

	for (int i = 0; i < marvel.getNumCharacters(); i++)
	{
		if (user != nullptr && user == allCharacters[i])
		{
			chosen = i;
			continue;
		}
		cout << counter << ") " << allCharacters[i]->getName() << endl;
		counter++;
	}
	
	cout << "Enter your choice: ";
	int opt;
	cin >> opt;

	if (opt > marvel.getNumCharacters() || opt <= 0)
	{
		cout << "Invalid option, try again...\n";
		return nullptr;
	}

	if (chosen != -1)
		if (opt > chosen)	// if character after chosen
		{
			// it's original index is one ahead (because we skipped chosen)
			cout << "Chosen: " << *allCharacters[opt] << "\n\n";
			return allCharacters[opt];
		}

	cout << "Chosen: " << *allCharacters[opt - 1] << "\n\n";
	return allCharacters[opt - 1];
}
