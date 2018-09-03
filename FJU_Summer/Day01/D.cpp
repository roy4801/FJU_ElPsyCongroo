#include <bits/stdc++.h>

#ifndef DBG
	#include "interactive/23.h"
#endif

using namespace std;

// By roy4801

// int gcd(int a, int b)
// {
// 	if(b == 0)
// 		return a;
// 	else
// 		return gcd(b, a % b);
// }

int gcd(int a, int b)
{
	int m = a > b ? a : b, n = a < b ? a : b;

	while(n != 0)
	{
		int tmp = m % n;
		m = n;
		n = tmp;
	}

	return m;
}

#ifdef DBG
	int GetN(int &n)
	{
		scanf("%d", &n);
	}

	void Get(int &n)
	{
		scanf("%d", &n);
	}

	void Report(const int &n)
	{
		printf("%d\n", n);
	}
	void Bye()
	{

	}
#endif

int main()
{
	#ifdef DBG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif
	int n, numGcd = 0, tmp;
    GetN(n);

    Get(tmp);
    numGcd = gcd(numGcd, tmp);
    
    for(int i = 1; i < n; i++)
    {
        Get(tmp);
    	numGcd = gcd(numGcd, tmp);
        Report(numGcd);
    }
    Bye();

	// printf("%d\n", gcd(1, 6));
	return 0;
}