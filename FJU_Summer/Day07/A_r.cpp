#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "A_r"

// by roy4801 AC@

uint64_t gcd(uint64_t a,uint64_t b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b , a%b);
	}
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	double in;
	uint64_t diviend = 0;

	while(scanf("%lf", &in) != EOF && in != 0.0)
	{
		uint64_t divisor = 1;
		diviend = in;

		while(in - (double)diviend > 1e-9)
		{
			// printf("%.10lf\n%lld\n\n", in, diviend);
			divisor *= 10;
			in *= 10.0;
			diviend = (uint64_t)in;
		}
		// printf("%llu %llu\n", diviend, divisor);
		uint64_t GCD = gcd(diviend, divisor);
		// printf("%llu\n", GCD);
		printf("%llu/%llu\n", diviend / GCD, divisor / GCD);

		// printf("%d\n", divisor);
	}

	return 0;
}