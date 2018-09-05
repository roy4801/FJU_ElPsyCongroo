#include <bits/stdc++.h>

using namespace std;

// By roy4801 TLE

struct Worm
{
	int blow, recv;

	Worm()
	{
		blow = recv = 0;
	}
	Worm(const Worm &other)
	{
		blow = other.blow;
		recv = other.recv;
	}

	bool operator<(const Worm &other)
	{
		return blow < other.blow;
	}
};

bool judge(const Worm worm[], const int i, const int j, const int sum)
{
	int avg = sum / (j - i + 1);
	bool ret = true;

	for(int a = i; a < j; a++)
	{
		if(worm[a].recv < avg)
		{
			ret = false;
			break;
		}
	}

	return ret;
}

int main()
{
	#ifdef DBG
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
	#endif
	int w;

	scanf("%d", &w);

	Worm worm[w];

	for(int i = 0; i < w && scanf("%d %d", &worm[i].blow, &worm[i].recv) != EOF; i++);

	sort(worm, worm + w);

	#if defined(DBP) && 1
	for(int i = 0; i < w && (~printf("%d %d\n", worm[i].blow, worm[i].recv)); i++);
	putchar('\n');
	#endif

	int max = -1;

	for(int i = 0; i < w; i++)
	{
		int sum[w] = {0};

		sum[i] = worm[i].blow;

		// printf("sum[i]: %d\n", sum[i]);

		for(int j = i + 1; j < w; j++)
		{
			sum[j] += worm[j].blow + sum[j - 1];

			if(!judge(worm, i, j, sum[j]))
			{
				#if defined(DBP) && 0
				printf("OUT\n");
				#endif
				break;
			}

			#if defined(DBP) && 1
			for(int A = 0; A < w && (~printf("%d ", sum[A])); A++);
			putchar('\n');
			#endif

			if(j - i + 1 > max)
				max = j - i + 1;
		}
	}

	printf("%d\n", max);

	return 0;
}