#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "A"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	int n,m;
	int arr[105];
	stack <int> stk;
	while(times--)
	{
		memset(arr,0,sizeof(arr));
		while(!stk.empty())
		{
			stk.pop();
		}
		scanf("%d %d",&n,&m);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d ",&arr[i]);
		}

		int tower = 0;
		int j = m-1;
		int num = arr[j];
		
		stk.push(arr[j]);
		j--;
		while( stk.top() > arr[j] &&  j >= 1)
		{ 
			stk.push(arr[j]);
			j--;
		}

		while(arr[j-1] > arr[j] && arr[j-1] > num &&  j >= 1)
		{
			stk.push(arr[j-1]);
			j--;
		}


		printf("%d\n",stk.size());

	}
	return 0;
}