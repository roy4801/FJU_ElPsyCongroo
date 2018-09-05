#include <bits/stdc++.h>

using namespace std;

#if defined(DBG)
	#define DBGP(fmt, ...) printf(fmt, ##__VA_ARGS__);
#else
	#define DBGP(fmt, ...)
#endif

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

	DBGP("avg: %d\n", avg);

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
	freopen("E2.in", "r", stdin);
	freopen("E2.out", "w", stdout);
	#endif
	int w;

	scanf("%d", &w);

	Worm worm[w];

	for(int i = 0; i < w && scanf("%d %d", &worm[i].blow, &worm[i].recv) != EOF; i++);

	sort(worm, worm + w);

	int i = 0, j = 0;
	int sum  = 0, max = -1;

	while(j < w)
	{
		sum += worm[j++].blow;

		if(judge(worm, i, j, sum))
		{
			if(j - i + 1 > max)
				max = j - i + 1;
		}
		else
		{
			sum -= worm[i++].blow;
		}
	}

	printf("%d\n", max);

	return 0;
}