/*
 * Dijkstra shortest path test
 * Team: FJU_ElPsyCongroo
 */
#include "dijkstra.h"

int main()
{
	freopen("dijkstra_test.in", "r", stdin);
	freopen("dijkstra_test.out", "w", stdout);

	int m;
	int from, to, wei;
	while(cin >> n >> m)
	{
		for(int i = 0; i < m && cin >> from >> to >> wei; i++)
		{
			from--, to--;
			w[from].emplace_back(to, wei);
		}

		dijkstra(0);
		cout << d[n-1] << '\n';
		findPath(0, n-1);
	}

	return 0;
}