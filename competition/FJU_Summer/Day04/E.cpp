#include <bits/stdc++.h>

using namespace std;

// By SunTalk and helloworld

int main()
{
	#ifdef DBG
	freopen("E.in", "r", stdin);
	freopen("E.out", "w", stdout);
	#endif

	long long number[100001];
	number[1]=2;
	number[2]=4;
	number[3]=7;

	for(int i=4;i<100001;i=i+1)
	{
		number[i] = number[i-1] + number[i-2] + number[i-3];
		
		if(number[i] > 10000019)
			number[i] = number[i] % 10000019;
	}
	long long num;
	
	scanf("%lld",&num);
	printf("%lld\n",number[num] );

	return 0;
}