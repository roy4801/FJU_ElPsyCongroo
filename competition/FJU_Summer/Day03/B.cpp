#include <bits/stdc++.h>

using namespace std;

struct Game
{
	int p, c;

	Game()
	{
		p = c = 0;
	}
	Game(const Game& other)
	{
		p = other.p;
		c = other.c;
	}
};

int main()
{
	#ifdef DBG
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif
	int n, k;

	scanf("%d %d", &n, &k);

	Game gal[n];
	int total[n];

	memset(total, 0, sizeof(total));

	for(int i = 0; i < n && scanf("%d %d", &gal[i].p, &gal[i].c) != EOF; i++)
	{
		total[(gal[i].c - 1)] = gal[i].p;
	}

	sort(gal, gal + n, [&](const Game& lhs, const Game& rhs)
	{
		return lhs.p == rhs.p ? lhs.c > rhs.c : lhs.p > rhs.p;
	});

	for(int i = 0; i < n && (~printf("%d %d\n", gal[i].p, gal[i].c)); i++);
	putchar('\n');

	sort(gal, gal + n, [&](const Game& lhs, const Game& rhs)
	{
		return lhs.c > rhs.c;
	});

	for(int i = 0; i < n && (~printf("%d %d\n", gal[i].p, gal[i].c)); i++);

	return 0;
}