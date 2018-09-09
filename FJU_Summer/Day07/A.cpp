#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "A"

// by helloworld

long long gcd(long long a,long long b)
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

	double num;
	uint64_t mother = 1,child = 0;
	bool flag = false;

	while(scanf("%lf",&num) != EOF && num)
	{
		printf("%.10f\n", num);
		child = num;

		// printf("%lld\n", child);
		num -= (double)child;
		child *= 10;
		printf("%.10lf\n", num);


		while(num - 0.0 > 1e-9)
		{
			child += num * 10.0;
			printf("child: %d\n", child);
			num *= 10.0;
			num -= (double)((int64_t)num);
			printf("%.10lf\n", num);
			child *= 10;
			mother *= 10;
		}
		child /= 10;
		printf("%lld/%lld\n", child,mother);

		while(gcd(mother,child) >= 2)
		{
			long long tmp = gcd(mother,child);
			mother /= tmp;
			child /= tmp;
		}
		printf("%lld/%lld\n", child,mother);
	}

	return 0;
}