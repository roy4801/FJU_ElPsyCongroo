#include <bits/stdc++.h>

using namespace std;

// by roy4801 AC@(100)

#define TESTC ""
#define PROBLEM "A"

int factor(const int n)
{
	int64_t sum = 1;
	
	for(int i = 1; i <= n; i++)
	{
		sum *= i;

		while(sum % 10 == 0)
		{
			sum /= 10;
		}

		sum %= 100;

		// printf("%d\n", sum);
	}

	return sum;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int n;

	scanf("%d", &n);

	printf("%d\n", factor(n) % 10);

	return 0;
}