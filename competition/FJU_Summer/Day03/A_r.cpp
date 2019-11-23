#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

#define TESTC ""
#define PROBLEM "A_r"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int m, n;
	int query;

	// Get input
	scanf("%d %d %d ", &m, &n, &query);

	char map[m+1][n+1];
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
			scanf("%c", &map[i][j]);
		getchar();
	}

	// for(int i = 1; i <= m; i++)
	// {
	// 	for(int j = 1; j <= n; j++)
	// 	{
	// 		printf("%c ", map[i][j]);
	// 	}
	// 	putchar('\n');
	// }

	// Build table for query (dp)
	int type[3][m+1][n+1];
	const char biome[] = {'J', 'O', 'I'};

	memset(type, 0, sizeof(type));

	for(int t = 0; t < 3; t++)
	{
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <=n; j++)
			{
				type[t][i][j] = type[t][i-1][j] + type[t][i][j-1] - type[t][i-1][j-1] + (map[i][j] == biome[t] ? 1 : 0);
			}
		}
	}

	// Query
	int aR, aC, bR, bC;
	for(int i = 0; i < query && scanf("%d %d %d %d", &aR, &aC, &bR, &bC) != EOF; i++)
	{
		for(int t = 0; t < 3; t++)
		{
			printf(t == 2 ? "%d\n" : "%d ", type[t][bR][bC] - type[t][aR-1][bC] - type[t][bR][aC-1] + type[t][aR-1][aC-1]);
		}
	}
	// for(int t = 0; t < 3; t++)
	// {
	// 	for(int i = 1; i <= m; i++)
	// 	{
	// 		for(int j = 1; j <= n; j++)
	// 			printf("%d ", type[t][i][j]);
	// 		putchar('\n');
	// 	}
	// 	putchar('\n');
	// }
	return 0;
}