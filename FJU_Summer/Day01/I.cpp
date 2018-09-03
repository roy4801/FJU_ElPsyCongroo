#include <bits/stdc++.h>

using namespace std;

// By roy4801

enum
{
	C_WANT,
	C_DONT
};

int main()
{
	#ifdef DBG
	freopen("I.in", "r", stdin);
	freopen("I.out", "w", stdout);
	#endif
	int num, want, dont;

	scanf("%d", &num);

	bool q[num][2][20];
	int total[20];
	bool choose[20];
	int hope = 0;

	memset(q, false, sizeof(q));
	memset(total, 0, sizeof(total));
	memset(choose, false, sizeof(choose));

	for(int i = 0; i < num && scanf("%d %d ", &want, &dont) != EOF; i++)
	{
		char tmp;

		for(int a = 0; a < want; a++)
		{
			tmp = getchar();
			q[i][C_WANT][tmp - 'A'] = true;
		}
		getchar();
		for(int a = 0; a < dont; a++)
		{
			tmp = getchar();
			q[i][C_DONT][tmp - 'A'] = true;
		}
	}

	for(int i = 0; i < num; i++)
	{
		for(int b = 0; b < 20; b++)
		{
			if(q[i][0][b])
			{
				total[b]++;
			}
		}

		for(int b = 0; b < 20; b++)
		{
			if(q[i][1][b])
			{
				total[b]--;
			}
		}
	}

	// choose the best
	bool fufill = false; // can fufill at one wish per person
	for(int i = 0; i < 20; i++)
	{
		if(total[i] > 0)
		{
			fufill = choose[i] = true;
		}
	}
	
	if(fufill)
	{
		for(int i = 0; i < num; i++)
		{
			for(int ch = 0; ch < 20; ch++)
			{
				if(choose[ch])
				{
					if(q[i][0][ch])
						hope++;
				}
				else
				{
					if(q[i][1][ch])
						hope++;
				}
			}
		}
		printf("%d\n", hope);
	}
	else
		printf("-1\n");

	return 0;
}