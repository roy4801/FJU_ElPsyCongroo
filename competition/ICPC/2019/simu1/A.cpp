#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "A"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif


	int n,k;
	vector<int> vec;

	while(cin >> n >> k)
	{
		vec.clear();
		for(int i = 0, tmp; i < n; i++)
		{
			cin >> tmp;
			vec.push_back(tmp);
		}

		sort(vec.begin(),vec.end());


		int tmp2 = k;
		int idx = n-1;
		int ans = 0;
		while(tmp2 > 0 && idx >= 0)
		{
			tmp2 -= vec[idx];
			ans++;
			idx--;
			// printf("%d %d\n",idx,tmp2 );
		}

		
		if(idx == -1 && tmp2 > 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}