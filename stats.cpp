#include <iostream>
#include <cstdlib>
#include <cmath>

void calculateAverages(const int sampleSize)
{
	long long int avgAt = 0, avgDe = 0, avgAg = 0,
				  varAt = 0, varDe = 0, varAg = 0;
	RandomDude dudes[sampleSize];
	for (int i = 0; i < sampleSize; ++i)
	{
		dudes[i] = RandomDude();

		avgAt += dudes[i].getAttack();
		avgDe += dudes[i].getDefense();
		avgAg += dudes[i].getAgility();
	}

	avgAt = avgAt / sampleSize;
	avgDe = avgDe / sampleSize;
	avgAg = avgAg / sampleSize;

	for (int i = 0; i < sampleSize; ++i)
	{
		varAt = (dudes[i].getAttack() - avgAt) * (dudes[i].getAttack() - avgAt);
		varDe = (dudes[i].getDefense() - avgDe) * (dudes[i].getDefense() - avgDe);
		varAg = (dudes[i].getAgility() - avgAg) * (dudes[i].getAgility() - avgAg);
	}

	varAt = varAt / avgAt;
	varDe = varDe / avgDe;
	varAg = varAg / avgAg;

	std::cout << "Sample Size: " << sampleSize
			  << "\nAvg Attack: " << avgAt
			  //<< "\n\tvariance: " << varAt
			  << "\n\tstd dev: " << (int)sqrt(varAt)

			  << "\nAvg Defence: " << avgDe
			  //<< "\n\tvariance: " << varDe
			  << "\n\tstd dev: " << (int)sqrt(varDe)

			  << "\nAvg Agility: " << avgAg
			  //<< "\n\tvariance: " << varAg
			  << "\n\tstd dev: " << (int)sqrt(varAg) << "\n\n";
}
