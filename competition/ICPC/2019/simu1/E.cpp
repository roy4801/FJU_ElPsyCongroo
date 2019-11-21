#include <bits/stdc++.h>
using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 100000
int n, m;
LL val[N+5];
int a, b;
//
struct dijoint
{
	int p[N+5];
	bool cycle[N+5];
	void init()
	{
		memset(p, -1, sizeof(p));
		memset(cycle, 0, sizeof(cycle));
	}
	int find(int x)
	{
		return p[x]<0 ? x : (p[x] = find(p[x]));
	}
	void uni(int a, int b)
	{
		a = find(a), b = find(b);
		p[a] += p[b];
		p[b] = a;
		if(cycle[a] || cycle[b])
		{
			cycle[a] = true;
			cycle[b] = false;
		}
	}
	bool isSame(int a, int b)
	{
		return find(a) == find(b);
	}
	int size(int x)
	{
		return -p[find(x)];
	}
	bool cyc(int x)
	{
		return cycle[find(x)];
	}
	void setCycle(int x)
	{
		cycle[find(x)] = true;
	}
}dis;
//
int main()
{
	while(cin >> n >> m)
	{
		dis.init();
		//
		for(int i = 1; i <= n && cin >> val[i]; i++);
		for(int i = 1; i <= m && cin >> a >> b; i++)
		{
			if(!dis.isSame(a, b))
				dis.uni(a, b);
			else
				dis.setCycle(a);
		}
		//
		vector<P> v;
		for(int i = 1; i <= n; i++)
			v.PB(MP(dis.find(i), i));
		sort(v.begin(), v.end());

		LL ans = 0;
		for(int i = 0; i < n;)
		{
			int siz = dis.size(v[i].F), oldi = i;
			bool cyc = dis.cyc(v[i].F);
			if(cyc)
			{
				for(int j = oldi; j < oldi+siz; j++, i++)
					ans += val[v[j].S];
			}
			else
			{
				vector<LL> tmp;
				for(int j = oldi; j < oldi+siz; j++, i++)
					tmp.PB(val[v[j].S]);
				sort(tmp.begin(), tmp.end());
				for(int i = 1; i < tmp.size(); i++)
					ans += tmp[i];
			}
		}
		printf("%lld\n", ans);
	}
}