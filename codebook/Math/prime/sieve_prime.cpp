/*
 * Sieve of Eratosthenes Test
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 */
#include "sieve.h"

using namespace std;

int main()
{
	buildPrimeTable();

	// Primes below 1000
	for(int i = 1; i <= 100000; i++)
	{
		if(prime[i])
			printf("%d\n", i);
	}

	return 0;
}
