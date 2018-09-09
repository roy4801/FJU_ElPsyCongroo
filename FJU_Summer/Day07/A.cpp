#include <bits/stdc++.h>

using namespace std;
//by helloworld AC@

#define TESTC ""
#define PROBLEM "A_r"

long long gcd(long long a , long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
		return gcd(b , a%b);
}




int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	double num = 0;
	long long mother = 1, child = 0;

	while(scanf("%lf",&num) && num != 0.0)
	{
		child = (long long)num;

		while(num - child)
		{
			mother *= 10;
			num *= 10.0;
			child = (long long)num;
		}

		long long tmp = gcd(mother,child);

		printf("%lld/%lld\n", child/tmp, mother/tmp);
		mother = 1;
	}
	return 0;
}
