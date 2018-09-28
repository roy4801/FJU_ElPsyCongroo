#include <bits/stdc++.h>

using namespace std;

// by roy4801 - AC

#define TESTC ""
#define PROBLEM "C"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 10000

int mapt[N];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int n, from, to;
	
	scanf("%d", &n);

	memset(mapt, -1, sizeof(mapt));
	for(int i = 0; i < n && scanf("%d %d", &from, &to) != EOF; i++)
		mapt[from] = to;

	int r;
	scanf("%d", &r);

	int sNode[r];

	for(int i = 0; i < r; i++)
		scanf("%d", &sNode[i]);

	for(int i = 0; i < r; i++)
	{
		bool check[N] = {false};
		int cur = sNode[i];

		check[cur] = true;
		// printf("%d ", cur);

		while((cur = mapt[cur]))
		{
			// printf("%d ", cur);
			if(check[cur])
			{
				int tmp = cur;
				printf("%d", tmp);
				while(cur != (tmp = mapt[tmp]))
					printf(" %d", tmp);
				break;
			}
			else
				check[cur] = true;
		}

		putchar('\n');
	}


	return 0;
}