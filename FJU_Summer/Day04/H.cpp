#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("H.in", "r", stdin);
	freopen("H.out", "w", stdout);
	#endif

	int times;
	int arr[100005];
	scanf("%d",&times);

	for (int i = 0; i < times; ++i)
	{
		scanf("%d",&arr[i]);
	}

	sort(arr,arr+times);
	int sum;
	sum = arr[times-3] + arr[times-2] + arr[times-1];
	printf("%d\n", sum);
	return 0;
}