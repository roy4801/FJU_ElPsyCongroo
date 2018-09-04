#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif

	int n,times,k;

	scanf("%d %d %d",&n ,&times ,&k);

	int guess;
	int first;
	bool flag = 0;

	for (int i = 0; i < times; ++i)
	{
		scanf("%d",&guess);

		if (!flag)
		{
			first = abs(guess-k);
			// printf("%d\n", first);
			flag = 1;
		}
		else
		{
			// printf("%d\n", abs(guess-k));
			if (first > abs(guess-k))
			{
				printf("Hotter\n");
				
			}
			else if (first == abs(guess-k))
			{
				printf("Same\n");
			}
			else if (first < abs(guess-k))
			{
				printf("Colder\n");
			}
			first = abs(guess-k);
		}
		
			
	}
	return 0;
}