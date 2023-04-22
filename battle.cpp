#include <iostream>

class battleArena
{
public:
	std::string oneOnOne(RandomDude cont1, RandomDude cont2);
	bool attack(RandomDude cont1, RandomDude cont2);
	bool checkIfAlive(RandomDude cont);
	void proclaimWinner(RandomDude cont);

private:
	int result;

	std::string chooseName();
};

std::string battleArena::oneOnOne(RandomDude cont1, RandomDude cont2)
{
	std::string winner = "LOOP EXITED"; //debug line
	while(cont1.isAlive() && cont2.isAlive())
	{
		this->attack(cont1, cont2);
		if(!cont2.isAlive())
		{
			return cont2.getFullName();
		}

		this->attack(cont2, cont1);
		if(!cont1.isAlive())
		{
			return cont1.getFullName();
		}
	}
	return winner;
}

bool battleArena::attack(RandomDude cont1, RandomDude cont2)
{
	//CONT1 ATTACKING CONT2
	std::cout << "AT THE " + this->chooseName() + " ARENA, PRESENTING:\n";
	std::cout << cont1.getFirstName() + " " + cont1.getLastName() + " VS " + cont2.getFirstName() + " " + cont2.getLastName() + "!\n\t";

	// check if attack hits, return false if doesn't hit
	int agilityDiff = cont1.getAgility() - cont2.getAgility();
	int avoidChance = 100;
	if (agilityDiff > 0)
	{
		avoidChance = avoidChance - agilityDiff;
	}
	
	else
	{
		avoidChance = avoidChance;
	}

	if(avoidChance < generateNumber(100)){
		return false; //false means the attack missed
	}

	// calculate damage based on attack - defense
	
	int damage = 50;
	int attackMinusDefense = cont1.getAttack() - cont1.getDefense();
	
	int finalDamage = damage - (attackMinusDefense / 100);

	// apply damage multipliers (might forego this)
	// subtract damage from HP, handle death
	cont2.setDamage(finalDamage);
	return true; //true means the attack landed
}

bool battleArena::checkIfAlive(RandomDude cont)
{
	if(cont.isAlive())
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
