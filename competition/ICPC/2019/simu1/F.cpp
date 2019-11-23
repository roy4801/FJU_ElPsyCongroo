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
#define N 100
int n, m, a;
LL x;
int pa, pb;
string cmd;
//
vector<int> G[N+5];
void add(int a, int b)
{
	G[a].PB(b);
	G[b].PB(a);
}
string bin;
void tobin(LL x)
{
	bin = "";
	for(int i = 0; i < 60; i++)
	{
		bin += (x & 1 ? '1' : '0');
		x >>= 1;
	}
}
int main()
{
	cin >> cmd;
	if(cmd == "encode" && cin >> n >> m)
	{
		for(int i = 0; i < m && cin >> pa >> pb; i++)
			add(pa, pb);
		cin >> x;
		tobin(x);
		//
		vector<int> rc, cc; // root cancidate, connect cancidate
		int now = bin[0]-'0', root;
		for(int i = 1; i <= n; i++)
		{
			int tmp = n-G[i].size();
			if(tmp >= 4)
				rc.PB(i);
			if(tmp >= 1)
				cc.PB(i);
		}
	}
	else if(cmd == "decode" && cin >> n >> a)
	{
		printf("%d\n", a);
	}
}