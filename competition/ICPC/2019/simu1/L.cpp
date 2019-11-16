#include <bits/stdc++.h>

using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define V 200000

vector<P> e[V+5];

void add(int fr, int to, int wei)
{
	// printf("%d %d %d\n", fr, to, wei);
	e[fr].PB(MP(to, wei));
	e[to].PB(MP(fr, wei));
}
int d[V+5];
int n, m;
int prim(int src)
{
	for(int i = 0; i <= V; i++) d[i] = INF;
	priority_queue<P, vector<P>, greater<P>> pq;
	int total = 0;
	pq.emplace(0, src);

	int to, wei;
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		if(d[cur.S] != INF)
			continue;
		d[cur.S] = 0;
		total += cur.F;

		for(auto &i : e[cur.S])
		{
			tie(to, wei) = i;
			if(d[to] == INF)
			{
				if(wei < d[to])
					pq.emplace(wei, to);
				else
					pq.emplace(d[to], to);
			}
		}
	}
	return total;
}
void init()
{
	for(int i = 0; i <= V; i++)
		e[i].clear();
	memset(d, 0, sizeof(d));
}
int D;
int a[V+5];
int main()
{
	while(cin >> n >> D)
	{
		// printf(">> %d\n", D);
		init();
		//
		for(int i = 1; i <= n && cin >> a[i]; i++);
		//
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= i; j++)
				if(i != j)
				{
					add(i, j, abs(i-j)*D+a[i]+a[j]);
				}

		printf("%d\n", prim(1));
	}
	return 0;
}