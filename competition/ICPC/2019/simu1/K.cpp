#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "K"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
typedef long long LL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 100
int n;
LL d, a[N+5];
struct E
{
	int a, b;
	LL wei;
	friend bool operator<(const E &lhs, const E &rhs)
	{
		return lhs.wei < rhs.wei;
	}
};
vector<E> e;
int p[N+5];
void init()
{
	for(int i = 0; i <= N; i++) p[i] = i;
}
int find(int x)
{
	return x == p[x] ? x : (p[x] = find(p[x]));
}
void uni(int a, int b)
{
	p[find(a)] = find(b);
}
bool isSame(int a, int b)
{
	return find(a) == find(b);
}
//
LL kru()
{
	sort(e.begin(), e.end());
	LL ans = 0;
	for(auto &i : e)
	{
		if(!isSame(i.a, i.b))
		{
			ans += i.wei;
			uni(i.a, i.b);
		}
	}
	return ans;
}

int main()
{
	while(cin >> n >> d)
	{
		e.clear();
		init();
		for(int i = 1; i <= n && cin >> a[i]; i++);

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= i; j++)
			{
				if(i != j)
				{
					e.PB({i, j, abs(i-j)*d+a[i]+a[j]});
				}
			}

		printf("%lld\n", kru());
		//

	}
	return 0;
}