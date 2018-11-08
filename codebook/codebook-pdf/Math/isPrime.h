// O(sqrt(n))
bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}
///////////////////////////////////////////////////////
// fast
bool prime[50000];
vector <size_t> vec;

// 篩法
void sie()
{
	fill(prime, prime+50000, true);

	for (int i = 2; i < 50000; ++i)
		if (prime[i])
		{
			vec.push_back(i);
			for (int j = i + i; j < 50000; j += i)
				prime[j] = false;
		}
}

bool isPrime(size_t x)
{
	if (x < 50000 && !prime[x])
		return false;
	if (x < 50000 && prime[x])
		return true;
	size_t sqr = sqrt(x);

	if (x % 6 == 0 || x % 6 == 2
	 || x % 6 == 3 || x % 6 == 4)
	{
		return false;
	}
	for (size_t i : vec)
	{
		if (x % i == 0)
			return false;
		if (sqr <= i)
			break;
	}
	return true;
}