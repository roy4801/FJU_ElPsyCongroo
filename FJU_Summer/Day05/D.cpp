#include <bits/stdc++.h>

using namespace std;

// By roy4801 賽後

#define M 3000000

int main()
{
	#ifdef DBG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif
	int phone, people;

	scanf("%d %d", &phone, &people);

	bool k[M + 1];
	bool p[phone+1];
	int total = 0, tmp;

	memset(k, false, sizeof(k));
	memset(p, false, sizeof(p));

	for(int i = 0; i < people && scanf("%d", &tmp) != EOF; i++)
	{
		// printf("%d\n", tmp);
		k[tmp] ^= 1; // if calc
	}

	for(int i = 1; i <= M; i++)
	{
		if(k[i])
		{
			// Judge multiples
			for(int j = i; j <= phone; j += i)
			{
				p[j] ^= 1;

				total += p[j] ? 1 : -1;
			}
		}
	}

	printf("%d\n", total);
	for(int i = 1; i <= phone; i++)
	{
		if(p[i])
			printf("%d\n", i);
	}


	return 0;
}