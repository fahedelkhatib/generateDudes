#include <iostream>
#include <cstdlib>
#include <cmath>
#include "dude.cpp"
#include "battle.cpp"
#include "stats.cpp"

int main()
{
	srand(time(0));

	RandomDude dudes[100];
	for (int i = 0; i < 2; ++i)
	{
		dudes[i] = RandomDude();
	}
	int avgAtt, avgDef, avgAgi = 0;
	for (int i = 0; i < 2; ++i)
	{
		// std::cout << dudes[i].greetingMessage() << std::endl;
		// std::cout << dudes[i].getStats() << std::endl;
	}

	battleArena *arena1 = new battleArena;
	
	RandomDude *dude1 = new RandomDude;
	RandomDude *dude2 = new RandomDude;
	RandomDude *dude3 = new RandomDude;
	std::cout << dude1->getStats() << std::endl;
	std::cout << dude2->getStats() << std::endl;
	std::cout << arena1->oneOnOne(dude1, dude2) << std::endl;
}
