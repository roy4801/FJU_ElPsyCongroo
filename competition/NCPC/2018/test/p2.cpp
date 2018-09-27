#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "p2"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	USE_CPPIO();

	int times;
	string s;

	cin >> times;
	
	while(times--)
	{
		cin >> s;

		cout << fixed << setprecision(6) << 1.f / stof(s) << '\n';		
	}


	return 0;
}