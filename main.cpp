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

	battleArena arena1 = battleArena();
	// arena1.oneOnOne(dudes[0], dudes[1]);

	/*
	for(int i = 0; i < 6; ++i)
	{
		calculateAverages(10);
	}
	*/
	/*
	for (int i = 1; i < 4; ++i)
	{
		std::cout << "\n";
		std::cout << dudes[i - 1].getStats() << std::endl;
		std::cout << dudes[i].getStats() << std::endl;
		arena1.oneOnOne(dudes[i - 1], dudes[i]);
	}
	*/
	RandomDude dude1 = RandomDude();
	RandomDude dude2 = RandomDude();
	arena1.oneOnOne(dude1, dude2);
}
