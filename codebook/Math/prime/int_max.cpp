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

bool is_prime(size_t x)
{
	if (x < 50000 && !prime[x])
		return false;
	if (x < 50000 && prime[x])
		return true;
	size_t sqr = sqrt(x);

	if (x % 6 == 0 || x % 6 == 2 || x % 6 == 3 || x % 6 == 4)
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

int main()
{
	sie();
	int L,R;

	while(cin >> L >> R)
	{
		int cnt = 0;
		for (unsigned int i = L; i <= R; ++i)
		{
			if (is_prime(i))
			{
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}