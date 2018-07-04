#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int getMax(int s[], const int l, int &pos)
{
	int maxN = 0;
	for(int i = 0; i < l; i++)
	{
		if(maxN < s[i])
		{
			maxN = s[i];
			pos = i;  // ref
		}
	}
	return maxN;
}

int main()
{
	#ifdef DBG
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
	#endif
	int row, col;
	int enemy;

	while(scanf("%d %d %d", &row, &col, &enemy) != EOF && row && col && enemy)
	{
		int shotRow[row], shotCol[col];

		for(int i = 0; i < row; i++)
			shotRow[i] = 0;
		for(int i = 0; i < col; i++)
			shotCol[i] = 0;

		pair<int, int> en[enemy];
		for(int i = 0; i < enemy; i++)
		{
			scanf("%d %d", &en[i].first, &en[i].second);
		}

		for(int i = 0; i < enemy; i++)
		{
			shotRow[en[i].first - 1]++;
			shotCol[en[i].second - 1]++;
		}

		vector<pair<char, int> >canon;
		int alive = enemy;
		while(alive > 0)
		{
			int posR, posC;
			int r = getMax(shotRow, row, posR);
			int c = getMax(shotCol, col, posC);

			if(r >= c)
			{
				// printf("%c\n", 'r');
				// for(int i = 0; i < col; i++)
				// {
				// 	printf("%d ", shotCol[i]);
				// }
				// putchar('\n');

				shotRow[posR] = 0;
				for(int i = 0; i < enemy; i++)
				{
					if(en[i].first == posR+1)
					{
						shotCol[ en[i].second-1 ]--;
					}
				}

				// for(int i = 0; i < col; i++)
				// {
				// 	printf("%d ", shotCol[i]);
				// }
				// putchar('\n');
				// putchar('\n');

				canon.push_back(pair<char, int>('r', posR+1));
				alive -= r;
			}
			else if(r < c)
			{
				// printf("%c\n", 'c');
				// for(int i = 0; i < row; i++)
				// {
				// 	printf("%d ", shotRow[i]);
				// }
				// putchar('\n');

				shotCol[posC] = 0;
				for(int i = 0; i < enemy; i++)
				{
					if(en[i].second == posC+1)
					{
						shotRow[ en[i].first-1 ]--;
					}
				}

				// for(int i = 0; i < row; i++)
				// {
				// 	printf("%d ", shotRow[i]);
				// }
				// putchar('\n');
				// putchar('\n');

				canon.push_back(pair<char, int>('c', posC+1));
				alive -= c;
			}
		}
		printf("%d", canon.size());

		vector<pair<char, int> >::iterator it = canon.begin();;
		for(; it != canon.end(); it++)
		{
			printf(" %c%d", it->first, it->second);
		}
		putchar('\n');

	}
	
	return 0;
}