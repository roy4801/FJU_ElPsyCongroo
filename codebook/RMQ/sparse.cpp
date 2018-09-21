#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "sparse"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int value[14];
	for(int i = 0; i < 14; i++)
		scanf("%d", &value[i]);

	// Sparse Table
	int N = 14, logN = __lg(N), spI = logN+1;
	int sp[spI][N] = {0};

	// printf("%d %d %d\n", N, logN, spI);

	// Build the Sparse Table
	for(int i = 0; i < N; i++) // first row (only one in a group)
		sp[0][i] = value[i];
	for(int i = 1; i < spI; i++) // number of elements in a group = 2^i
	{
		for(int j = 0; j < N - ((1 << i) - 1); j++) // j < N - (2^i - 1)
		{
			// Current row overlapped two upper groups in (i-1) row 
			// Such as i = 1
			// sp[i-1][j] -> covers j
			// sp[i-1][j + (1 << (i-1))] = sp[i-1][j + 1] -> covers j + 1
			// Total covered [j ~ j+1] => 2 = 2^i = current covered
			// (1 << (i-1)) => 2 ^ (i-1)
			sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1 << (i-1))]);
		}
	}

	// Query
	int l, r;
	while(scanf("%d %d", &l, &r) != EOF && (l && r))
	{
		l--, r--;

		int distance = r - l + 1;
		int targetIdx = l != r ? __lg(distance)-1 : 0;

		printf("%d\n", max(sp[targetIdx][l], sp[targetIdx][r - (1<<targetIdx - 1)]));
	}

	// for(int i = 0; i < spI; i++)
	// {
	// 	for(int j = 0; j < N - ((1 << i) - 1); j++)
	// 	{
	// 		printf("%2d ", sp[i][j]);
	// 	}
	// 	putchar('\n');
	// }


	return 0;
}