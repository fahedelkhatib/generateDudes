#include <iostream>

class battleArena
{
public:
	bool oneOnOne(RandomDude cont1, RandomDude cont2);

private:
	int result;

	std::string chooseName();
};

bool battleArena::oneOnOne(RandomDude cont1, RandomDude cont2)
{
	std::cout << "AT THE " + this->chooseName() + " ARENA, PRESENTING:\n";
	std::cout << cont1.getFirstName() + " " + cont1.getLastName() + " VS " + cont2.getFirstName() + " " + cont2.getLastName() + "!\n\t";

	// check if attack hits
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
	// calculate damage based on attack - defense
	// apply damage multipliers
	// subtract damage from HP
	// handle death
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
