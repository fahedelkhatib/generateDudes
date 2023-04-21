#include <iostream>



class battleArena
{
	public:
		bool oneOnOne(RandomDude cont1, RandomDude cont2)
		{
			std::cout << "AT THE " + this->chooseName() + " ARENA, PRESENTING:\n";
			std::cout << cont1.getFirstName() + " " + cont1.getLastName()
				+ " VS " + cont2.getFirstName() + " " + cont2.getLastName() + "!\n\t";

			int attack1 = cont1.getAttack();
			int attack2 = cont2.getAttack();
			if(attack1 > attack2)
			{
				std::cout << cont1.getFirstName() + " "
					+ cont1.getLastName() + " wins!\n";
				return true;
			}
			else
			{
				std::cout << cont2.getFirstName() + " "
					+ cont2.getLastName() + " wins!\n";
				return false;
			}
		}
	private:
		int result;

		std::string chooseName();
		
};

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
		"RANCID ONIONS"
	};

	int choice = generateNumber((sizeof(names)/sizeof(names[0])) - 1);
	return names[choice];
}
