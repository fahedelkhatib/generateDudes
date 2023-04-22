#include <iostream>
#include <cstdlib>

// returns "random" integer from 1 to limit inclusive
int generateNumber(int limit)
{
	int number = rand();
	while (number > limit)
	{
		number = number * 0.1;
	}
	return number;
}

bool randomBool()
{
	return generateNumber(111) % 2;
}

std::string intToString(int num)
{
	// append each digit in char form, backwards
	std::string oStr = "";
	int buffer = num;
	while (buffer > 0)
	{
		oStr += (buffer % 10) + 48;
		buffer = buffer / 10;
	}
	// reverse char order in string and return
	std::string oStrFr = "";
	for (int i = 0; i < oStr.length(); ++i)
	{
		oStrFr += oStr.at(oStr.length() - i - 1);
	}

	return oStrFr;
}

// depends on generateNumber()
std::string generateFirstName()
{
	std::string names[] = {
		"PLACEHOLDER",
		"Sam",
		"Gary",
		"Mobin",
		"Kyle",
		"Edward",
		"Jerald",
		"Juan",
		"Mark",
		"Andre",
		"Freddy",
		"John",
		"Chris",
		"Christopher",
		"Geralt",
		"Gerald",
		"Tyler",
		"Tyson",
		"Mario",
		"Maham",
		"Nathan",
		"Junichi"};

	int choice = generateNumber((sizeof(names) / sizeof(names[0]) - 1));
	return names[choice];
}

// depends on generateNumber()
std::string generateLastName()
{
	std::string names[] = {
		"PLACEHOLDER",
		"Coleman",
		"Fortnite",
		"Kennedy",
		"Faering",
		"Selch",
		"Moonbright",
		"Maxwell",
		"Ackerman",
		"Bashkir",
		"Busch",
		"Samuel",
		"Gropius",
		"Galactus",
		"Briskorn",
		"Nichols",
		"Takeuchi",
		"Wayward",
		"Sugimori",
		"Masuda",
		"Mobin",
		"Kassir",
		"Yama"};

	int choice = generateNumber((sizeof(names) / sizeof(names[0]) - 1));
	return names[choice];
}


class RandomDude
{
public:
	RandomDude();
	
	//getters
	std::string getFirstName() { return this->first_name; }
	std::string getLastName() { return this->last_name; }
	int getAge() { return this->age; }
	bool getGender() { return this->gender; }
	int getAttack() { return this->attack; }
	int getDefense() { return this->defense; }
	int getAgility() { return this->agility; }
	int getHealth() { return this->health; }
	std::string getFullName();
	bool isAlive() { return this->alive; }
	
	//setters
	void die() 
	{ 	
		if(this->health < 1) 
		{
			this->alive = false;
		}
		std::cout << this->getFullName() + " has perished." << std::endl;	
	}
	void setHealth(int newHealth)
	{
		this->health = newHealth;
	}
	void setDamage(int damage)
	{
		this->setHealth(this->getHealth() - damage);
		this->die();
	}

	//string outputs (for demos)
	std::string getStats()
	{
		return "***" + this->getFirstName() + " " + this->getLastName() + "***\n\tATTACK: " + intToString(this->getAttack()) + "\tDEFENSE: " + intToString(this->getDefense()) + "\tAGILITY: " + intToString(this->getAgility()) + "\n";
	}

	std::string greetingMessage()
	{
		return "I am " + this->getFullName() + ", " + intToString(this->getAge()) + ".";
	}

private:
	std::string first_name, last_name;
	// from 0 to 99
	int age;
	// male=true, female=false
	bool gender; // do we want genders? not yet.
	int attack, defense, agility, health;
	bool alive;
};

std::string RandomDude::getFullName()
{
	return this->getFirstName() + " " + this->getLastName();
}

RandomDude::RandomDude()
{
	this->age = generateNumber(100);
	this->first_name = generateFirstName();
	this->last_name = generateLastName();
	this->gender = randomBool();
	this->health = 100;
	this->attack = generateNumber(500);
	this->defense = generateNumber(500);
	this->agility = generateNumber(500);
	this->alive = true;
}
