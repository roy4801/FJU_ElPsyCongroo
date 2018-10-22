#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "B"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


bool m[105][105];
int  p, e;
int go(int from)
{
	if(from != -1)
	{
		for(int i = 1; i <= p; i++)
			if(m[from][i])
				return i;
	}
	return -1; // end
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases;
	int from, to;

	cin >> cases;
	while(cases--)
	{
		bool found = false;
		cin >> p >> e;

		memset(m, false, sizeof(m));

		for(int i = 0; i < e && cin >> from >> to; i++)
			m[from][to] = true;

		for(int i = 1; i <= p; i++)
		{
			int tur = go(i), rab = go(go(i));

			while((tur = go(tur)) != (rab = go(go(rab))));

			if(tur != -1 && rab != -1)
			{
				printf("Yes\n");
				found = true;
				break;
			}
		}

		if(!found)
			printf("NO\n");
	}

	return 0;
}