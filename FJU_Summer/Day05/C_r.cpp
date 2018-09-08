#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

int64_t lucky[1024] = {0}; // lucky numbers
int ar[10]; // -1 don't take, 0 = take 4, 1 = take 7

void init()
{
	memset(ar, -1, sizeof(ar));

	int now = 0;

	while(now < 1022)
	{
		ar[0] += 1;

		// addition carry of ar[]
		int i = 0;
		while(i < 10)
		{
			if(ar[i] >= 2)
			{
				ar[i] -= 2;
				// last digit
				if(i != 9)
				{
					ar[i + 1]++;
				}
			}
			i++;
		}

		// for(int i = 0; i < 10; i++)
		// 	printf("%d ", ar[i]);
		// putchar('\n');

		// Turn ar[] into int
		for(int digit = 0; digit < 10 - 1 && ar[digit] != -1; digit++)
		{
			lucky[now] += ar[digit] == 0 ? 4 : 7;
			
			if(ar[digit + 1] != -1)
				lucky[now] *= 10;
		}

		now++;
	}
}

int main()
{
	#ifdef DBG
	freopen("C_r.in", "r", stdin);
	freopen("C_r.out", "w", stdout);
	#endif
	init();

	sort(lucky, lucky + 1022);
	// for(int i = 0; i < 1022; i++)
	// {
	// 	printf("%lld\n", lucky[i]);
	// }

	int lb, rb;
	int numbers = 0;
	bool lower = false, upper = false;

	scanf("%d %d", &lb, &rb);

	for(int i = 0; i < 1024; i++)
	{
		if(lucky[i] > lb && lucky[i+1] <= lb)
			numbers += i;
		else if(lucky[i] >= rb && lucky[i+1] < rb)
		{
			numbers -= i;
			break;
		}

	}
	printf("%d\n", numbers);

	return 0;
}