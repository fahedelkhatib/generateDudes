#include <iostream>

class battleArena
{
public:
	std::string oneOnOne(RandomDude *cont1, RandomDude *cont2);
	bool attack(RandomDude *cont1, RandomDude *cont2);
	bool checkIfAlive(RandomDude cont);
	void proclaimWinner(RandomDude *cont);
	int calculateDamage(RandomDude *cont1, RandomDude *cont2);
	int calculateHitChance(RandomDude *cont1, RandomDude *cont2);

private:
	int result;

	std::string chooseName();
};

void battleArena::proclaimWinner(RandomDude *cont)
{
	std::cout << cont->getFullName() << " wins!! They had " << cont->getHealth() << " HP left." << std::endl;
}

std::string battleArena::oneOnOne(RandomDude *cont1, RandomDude *cont2)
{
	std::cout << "AT THE " + this->chooseName() + " ARENA, PRESENTING:\n";
	std::cout << cont1->getFullName() + " VS " + cont2->getFullName() + "!\n";

	std::string winner = "LOOP EXITED"; // debug line
	while (cont1->isAlive() == true && cont2->isAlive() == true)
	{

		this->attack(cont1, cont2);

		if (!(cont2->isAlive()))
		{
			winner = cont1->getFullName();
			this->proclaimWinner(cont1);
			return winner;
		}

		this->attack(cont2, cont1);

		if (!(cont1->isAlive()))
		{
			winner = cont2->getFullName();
			this->proclaimWinner(cont2);
			return winner;
		}

		/*
			std::cout << "cont1 is " << cont1->isAlive() << std::endl
				<< "cont2 is " << cont2->isAlive() << std::endl;
		*/
	}
	return winner;
}

bool battleArena::attack(RandomDude *cont1, RandomDude *cont2)
{
	// check if attack hits, return false if doesn't hit
	int avoidChance = this->calculateHitChance(cont1, cont2);
	// avoidChance = 50;

	if (avoidChance < generateNumber(100))
	{
		std::cout << cont1->getFullName() << " attacks. \n\tThey missed." << std::endl;
		return false; // false means the attack missed
	}
	else
	{
		int finalDamage = this->calculateDamage(cont1, cont2);
		// apply damage multipliers (might forego this)
		// subtract damage from HP, handle death
		std::cout << cont1->getFullName() << " attacks for\n\t" << finalDamage << " damage." << std::endl;
		cont2->setDamage(finalDamage);
		return true; // true means the attack landed
	}
	return false;
}

int battleArena::calculateHitChance(RandomDude *cont1, RandomDude *cont2)
{
	int agilityDiff = cont1->getAgility() - cont2->getAgility();
	int avoidChance = 100;
	if (agilityDiff > 0)
	{
		avoidChance = avoidChance - (agilityDiff / 100);
	}
	else
	{
		avoidChance = avoidChance - generateNumber(50);
	}

	std::cout << "CHANCE TO HIT: " << avoidChance << std::endl;
	return avoidChance;
}

int battleArena::calculateDamage(RandomDude *cont1, RandomDude *cont2)
{
	int damage = generateNumber(50);
	int attackMinusDefense = cont1->getAttack() - cont2->getDefense();
	int ageDifferenceModifier = cont2->getAge() - cont1->getAge();

	int finalDamage = damage + (ageDifferenceModifier / 3) - (attackMinusDefense / 100);
	if (finalDamage < 1)
	{
		finalDamage = 1;
	}
	return finalDamage;
}

bool battleArena::checkIfAlive(RandomDude cont)
{
	if (cont.isAlive())
	{
		return true;
	}
	return false;
}

std::string battleArena::chooseName()
{
	std::string names[] = {
		"DEEZ NUTS",
		"FARTNITE",
		"FAREWELL",
		"STUDIO",
		"THREE STOOGES",
		"MILLENIUM",
		"PEGASUS",
		"PHARAOH'S",
		"NIGHTS",
		"RANCID ONIONS"};

	int choice = generateNumber((sizeof(names) / sizeof(names[0])) - 1);
	return names[choice];
}
