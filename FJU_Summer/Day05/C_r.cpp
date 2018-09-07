// #include <bits/stdc++.h>

#include <iostream> // local

using namespace std;

int64_t lucky[1030]; // 1024 lucky numbers
int ar[10]; // -1 don't take, 0 = take 4, 1 = take 7

void init()
{
	memset(ar, -1, sizeof(ar));

	int now = 0;

	while(now < 1024)
	{
		ar[0] += 1;

		// addition carry of ar[]
		int i = 0;
		while(i < 10)
		{
			if(ar[i] >= 2)
			{
				ar[i] -= 2;
				ar[i + 1]++;
			}

			i++;
		}

		// print ar
		for(int i = 0; i < 10; i++)
			printf("%d ", ar[i]);
		putchar('\n');

		// Turn ar[] into int
		for(int digit = 0; digit < 10; digit++)
		{
			lucky[now] += ar[digit] == 0 ? 4 : 7;
			
			if(ar[digit] != -1)
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

	for(int i = 0; i < 1024; i++)
	{
		printf("%lld\n", lucky[i]);
	}

	// int lb, rb;
	// int numbers = 0;

	// scanf("%d %d", &lb, &rb);

	// for(int i = 0; i < 1024; i++)
	// {
	// 	if(lucky[i] > lb)
	// 	{
	// 		numbers += i;
	// 	}
	// 	if(lucky[i] > rb)
	// 	{
	// 		numbers -= i;
	// 	}
	// }
	// printf("%d\n", numbers);


	return 0;
}