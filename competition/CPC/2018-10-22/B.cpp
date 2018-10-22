#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "B"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

void go()
{
	
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases, p, e;
	int from, to;

	cin >> cases;
	while(cases--)
	{
		cin >> p >> e;

		bool m[p][p];

		memset(m, false, sizeof(m));

		for(int i = 0; i < e && cin >> from >> to; i++)
			m[from][to] = true;


	}

	return 0;
}