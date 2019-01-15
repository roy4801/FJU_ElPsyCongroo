#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "D"
#define TESTC ""

// WTF by roy4801

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
typedef unsigned long long ULL;
typedef long long LL;
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 18
typedef unordered_map<string, bool> hash_map;
char d[N+5];
int now = 0;
hash_map h;
int count()
{
	int cnt = 0;
	string tmp;
	for(int l = 1; l <= now; l++) // len
	{
		for(int i = 0; i < now - l + 1; i++)
		{
			for(int j = 0; j < l; j++)
			{
				tmp += d[i + j];
			}
			cout << tmp << '\n';
			if(!h.count(tmp))
			{
				cnt++;
				h.insert(MP(tmp, true));
			}
			tmp = "";
		}
	}
	return cnt;
}
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	char c;
	bool end = false;
	while((c = getchar()))
	{
		if(c == '\n' || c == EOF)
		{
			if(end && c == EOF)
				break;
			cout << count() << '\n';
			//
			h.clear();
			now = 0;
			end = true;
			continue;
		}
		d[now++] = c;
	}

	return 0;
}
