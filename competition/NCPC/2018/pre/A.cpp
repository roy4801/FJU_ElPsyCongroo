#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "A"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define PX 0
#define PY 1

#define POINT(n) p[PX][n], p[PY][n]

int dist(int x1, int y1, int x2, int y2)
{
	int l = abs(x1-x2), r = abs(y1-y2);
	return l * l + r * r;
}

priority_queue<int> pq;

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int cases, v;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &v) != EOF)
	{
		int p[2][v]; // [x, y][idx]

		for(int i = 0; i < v && scanf("%d %d", &p[PX][i], &p[PY][i]) != EOF; i++);

		// calc max and 2nd
		bool chk[2][1005];
		memset(chk, false, sizeof(chk));

		for(int i = 0; i < 2; i++) // x or y
		{
			int nowCord = (i+1)%2;
			// printf("i:%d nowCode:%d\n", i, nowCord);

			for(int a = 0; a < v; a++) // cur
			{
				for(int b = a+1; a < v; a++) // next
				{
					// if(p[i][a] == p[i][b])
					{
						// printf("%d %d %d %d\n", POINT(a), POINT(b));
						int mi = min(p[nowCord][a], p[nowCord][b]);
						int mx = max(p[nowCord][a], p[nowCord][b]);

						for(int c = mi; c <= mx; c++)
							chk[nowCord][c] = true;
					}
				}
			}
		}

		// for(int i = 0; i < 2; i++)
		// {
		// 	for(int a = 0; a < 10; a++)
		// 		printf("%d ", !!chk[i][a]);
		// 	putchar('\n');
		// }

		int area = 1;
		for(int i = 0; i < 2; i++)
		{
			int sum = 0;
			bool conti = false;

			for(int j = 0; j < 1001; j++)
			{
				if(conti && !chk[i][j])
				{
					conti = false;
					break;
				}
				else if(conti && chk[i][j])
				{
					sum++;
				}

				// First
				if(!conti && chk[i][j])
				{
					conti = true;
					// sum++;
				}
			}

			area *= sum;
			// printf("%d ", sum);
		}

		printf("%d\n", area);
	}

	return 0;
}