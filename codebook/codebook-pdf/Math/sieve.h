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