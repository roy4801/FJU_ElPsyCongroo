#include <bits/stdc++.h>

using namespace std;

vector<array<int, 3> > l(7);

int main()
{
	#ifdef DBG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif

	for(int i = 0; i < 7 && scanf("%d %d %d", &l[i][0], &l[i][1], &l[i][2]); i++);

	for(int a = 0; a < 3; a++)
	{
		map<int, int> to;
		int times[2] = {0};
		int n[2];
		int now = 0;

		for(int i = 0; i < 7; i++)
		{
			auto it = to.find(l[i][a]);

			if(it != to.end()) // found
			{
				times[it->second]++;
			}
			else
			{
				n[now] = l[i][a];
				to[l[i][a]] = now++;
			}
		}

		// for(int i = 0; i < 2; i++)
		// 	printf("%d ", times[i]);
		// putchar('\n');
		printf(a != 2 ? "%d " : "%d\n", n[min_element(times, times+2) - times]);
		// printf("%d ", min_element(times, times+2) - times);
	}

	// for(int i = 0; i < 7; i++)
	// 	printf("%d %d %d\n", l[i][0], l[i][1], l[i][2]);

	return 0;
}