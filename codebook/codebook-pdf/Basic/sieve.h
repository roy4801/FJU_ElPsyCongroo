/*
 * Sieve of Eratosthenes Implementation
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 */
#include <iostream>

/*
 * Sieve of Eratosthenes
 * 
 * from 2 to n , begining at 2 and delete all of its multiples and do it over and over again
 * until all multiples are deleted in [2, n]
 */

#define TABLE_SIZE 100000

bool prime[TABLE_SIZE];

void buildPrimeTable()
{
	prime[0] = prime[1] = false;
	for(int i = 2; i < TABLE_SIZE; i++)
		prime[i] = true;

	for(int i = 2; i < TABLE_SIZE; i++)
	{
		if(prime[i])
			for(size_t a = i*i; a < TABLE_SIZE; a += i)
				prime[a] = false;
	}
}