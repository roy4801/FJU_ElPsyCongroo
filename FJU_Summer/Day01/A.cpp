#include <bits/stdc++.h>

using namespace std;

// By roy4801

int main()
{
	#ifdef DBG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif
	int toast;
	int times = 0;

	scanf("%d", &toast);

	while(toast > 0)
	{
		if(toast % 5 == 0)
		{
			times += toast / 5;
			toast = 0;
			break;
		}
		else if(toast == 3)
		{
			times++;
			break;
		}

		toast -= 3;
		times++;
	}

	if(toast % 3 == 0)
		printf("%d\n", times);
	else
	{
		printf("This is Kongming's Trap!!!\n");
	}

	return 0;
}