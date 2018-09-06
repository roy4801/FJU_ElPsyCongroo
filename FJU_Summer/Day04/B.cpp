#include <bits/stdc++.h>

using namespace std;

int64_t p[25] = {1, 2};

int64_t pow2(int64_t n)
{
	if(n < 21 && p[n])
	{
		return p[n];
	}

	if(n == 0 || n == 1)
		return p[n];
	else if(n % 2 != 0) // odd
	{
		int64_t xx = pow2(n/2);

		if(n < 21)
			return (p[n] = xx * xx * 2);
		else
			return (xx % 2076030) * (xx % 2076030) * 2 % 2076030;
	}
	else // even
	{
		int64_t xx = pow2(n/2);

		if(n < 21)
			return (p[n] = xx * xx);
		else
			return (xx % 2076030) * (xx % 2076030) % 2076030;
	}
}

int main()
{
	#ifdef DBG
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif
	int n;

	scanf("%d", &n);

	printf("%d\n", pow2(n));

	return 0;
}