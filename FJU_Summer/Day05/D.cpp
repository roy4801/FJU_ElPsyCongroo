#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif
	int phone, people;

	scanf("%d %d", &phone, &people);

	int k[people];
	bool p[phone+1] = {false};
	int total = 0;

	for(int i = 0; i < people && scanf("%d", &k[i]) != EOF; i++);

	for(int i = 0; i < people; i++)
	{
		for(int a = k[i]; a <= phone; a += k[i])
		{
			p[a] = !p[a];

			total += p[a] ? 1 : -1;
		}
	}

	printf("%d\n", total);
	for(int i = 1; i <= phone; i++)
	{
		if(p[i])
			printf("%d\n", i);
	}


	return 0;
}