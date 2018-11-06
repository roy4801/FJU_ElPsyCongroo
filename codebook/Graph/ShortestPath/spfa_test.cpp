/*
 * SPFA (negative edge & negative cycle) test
 * Team: FJU_ElPsyCongroo
 */
#include "spfa.h"

int main()
{
	freopen("spfa_test.in", "r", stdin);
	int from, to, wei;

	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 0; i < m && scanf("%d %d %d", &from, &to, &wei) != EOF; i++)
			e[from].emplace_back(to, wei);

		spfa(0);

		for(int i = 0; i < n; i++)
		{
			if(abs(d[i]) == INF)
				cout << "Unreachable" << '\n';
			else
				cout << d[i] << '\n';
		}
	}
	return 0;
}