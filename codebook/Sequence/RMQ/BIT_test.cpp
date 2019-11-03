#include <bits/stdc++.h>
using namespace std;
int n;
#include "BIT.h"
int prefix_query(int l, int r)
{
    return query(r)-query(l-1);
}
int main()
{
	freopen("BIT_test.in", "r", stdin);
	freopen("BIT.out", "w", stdout);
	//
	int cases, tmp, a, b;
	cin >> cases;
	while(cases-- && cin >> n)
	{
		for(int i = 1; i <= n && cin >> tmp; i++)
			update(i, tmp);

		while(cin >> a >> b && (a || b))
			cout << prefix_query(a, b) << '\n';
	}
	return 0;
}
