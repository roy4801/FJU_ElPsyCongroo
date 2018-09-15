#include <bits/stdc++.h>

using namespace std;

#define TESTC "1"
#define PROBLEM "B"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int cases, poti;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &poti) != EOF)
	{
		int abli[3];

		for(int i = 0; i < 3; i++)
			scanf("%d", &abli[i]);

		sort(abli, abli + 3);
		int now = 0;

		// Add until all of the elements are same
		if( poti > 0 && abli[1] > abli[0] ){
			int add = abli[1] - abli[0];
			if(poti > add){
				abli[0]+=add;
				poti-=add;
			}
			else{
				abli[0]+=poti;
				poti=0;
			}

		}

		if(poti > 0 && abli[2] > abli[1] ){
			int add = abli[2] - abli[1];
			if(poti/2 > add){
				poti = poti - 2 * add;
				abli[0]+=add;
				abli[1]+=add;
			}
			else{
				abli[0]+=poti/2;
				abli[1]+=poti/2;
				poti=poti%2;
			}
		}


		// printf("%d %d %d\n", abli[0], abli[1], abli[2]);
		// printf("%d\n", poti);

		if(poti > 0)
		{
			int add = poti / 3, mod = poti % 3;

			for(int i = 0; i < 3; i++)
			{
				abli[i] += add;
			}

			if(mod == 2)
			{
				abli[0]++;
				abli[1]++;
			}
			else if(mod == 1)
			{
				abli[0]++;
			}
		}

		// printf("%d %d %d\n", abli[0], abli[1], abli[2]);
		printf("%llu\n", (uint64_t)abli[0] * (uint64_t)abli[1] * (uint64_t)abli[2]);
		// putchar('\n');
	}

	return 0;
}