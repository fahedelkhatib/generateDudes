#include <iostream>

class battleArena
{
public:
	std::string oneOnOne(RandomDude* cont1, RandomDude* cont2);
	bool attack(RandomDude* cont1, RandomDude* cont2);
	bool checkIfAlive(RandomDude cont);
	void proclaimWinner(RandomDude* cont);

private:
	int result;

	std::string chooseName();
};

void battleArena::proclaimWinner(RandomDude* cont)
{
	std::cout << cont->getFullName() << " wins!!" << std::endl;
}

std::string battleArena::oneOnOne(RandomDude* cont1, RandomDude* cont2)
{
	std::cout << "AT THE " + this->chooseName() + " ARENA, PRESENTING:\n";
	std::cout << cont1->getFullName() + " VS " + cont2->getFullName() + "!\n";

	std::string winner = "LOOP EXITED"; //debug line
	while(cont1->isAlive() == true && cont2->isAlive() == true)
	{
		std::cout << "attack 1" << std::endl;
		this->attack(cont1, cont2);

		if(!(cont2->isAlive()))
		{
			winner = cont1->getFullName();
			this->proclaimWinner(cont1);
			return winner;
		}

		std::cout << "attack 2" << std::endl;
		this->attack(cont2, cont1);

		if(!(cont1->isAlive()))
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

bool battleArena::attack(RandomDude* cont1, RandomDude* cont2)
{
	// check if attack hits, return false if doesn't hit
	int agilityDiff = cont1->getAgility() - cont2->getAgility();
	int avoidChance = 100;
	if (agilityDiff > 0)
	{
		avoidChance = avoidChance - agilityDiff;
	}
	else
	{
		avoidChance = avoidChance;
	}

	if(avoidChance < generateNumber(100))
	{
		return false; //false means the attack missed
	}
	else
	{
		// calculate damage based on attack - defense	
		int damage = 50;
		int attackMinusDefense = cont1->getAttack() - cont1->getDefense();
		
		int finalDamage = damage - (attackMinusDefense / 100);
	
		// apply damage multipliers (might forego this)
		// subtract damage from HP, handle death
		cont2->setDamage(finalDamage);
		return true; //true means the attack landed
	}
	return false;
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
