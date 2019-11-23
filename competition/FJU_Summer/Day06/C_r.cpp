#include <bits/stdc++.h>

// By roy4801 AC

using namespace std;

#define TESTC ""
#define PROBLEM "C"

int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int p;

	scanf("%d", &p);

	int brick[p], tmp;

	memset(brick, 0, sizeof(brick));

	for(int i = 0; i < p && scanf("%d", &tmp) != EOF; i++)
		brick[i] += tmp;
	for(int i = 0; i < p && scanf("%d", &tmp) != EOF; i++)
		brick[i] -= tmp;

	int have[100], to[100];
	int numH = 0, numTo = 0;
	int move = 0;
	for(int i = 0; i < p; i++)
	{
		if(brick[i] < 0)
		{
			move += -brick[i];

			to[numTo++] = i;
		}
		else if(brick[i] > 0)
			have[numH++] = i;
	}

	printf("%d\n", move);

	// for(int i = 0; i < p; i++)
	// 	printf("%d ", brick[i]);
	// putchar('\n');

	for(int i = 0; i < numH; i++)
	{
		for(int j = 0; j < numTo; j++)
		{
			while(brick[have[i]] > 0 && brick[to[j]] < 0)
			{
				brick[have[i]]--;
				brick[to[j]]++;
				printf("%d %d\n", have[i]+1, to[j]+1);
			}
		}
	}


	return 0;
}