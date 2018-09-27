#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "p3"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int cases, len;

	scanf("%d", &cases);

	while(cases-- && scanf("%d ", &len) != EOF)
	{
		bool b[len] = {false};
		char s[10];

		while(getchar() != '\n');

		for(int i = 0; i < len && (~printf("READ %d\n", i)) && scanf("%s", s) != EOF; i++)
		{
			b[i] = (s[0] == 'f' ? false : true);

			if(i && b[i-1] && !b[i])
			{
				printf("OUTPUT %d\n", i-1);
				break;
			}
		}
	}

	return 0;
}