/*WA fucking by halloworld*/
#include <iostream>
#include <queue>

using namespace std;

#define PROBLEM "C"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define POPB pop_back
#define LL long long

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	

	scanf("%d\n",&times);
	while(times--)
	{
		deque <int> que;
		char num[100];
		char aa;
		int k = 0;
		int stop = 0;

		while(scanf("%c",&aa))
		{
			if (aa == '\n')
				break;
			else
			{
				num[k] = aa;
				k++;
			}
			
		}
		
		for (int i = 1; i < k-1; ++i)
		{
			if (num[i-1] <= num[i])
			{
				for (int j = i-1; j >= 0; ++j)
				{
					if (num[j] > num[i])
					{
						num[j] += '1';
						for (int s = j+1; s < k; ++s)
						{
							num[s] = '0';
						}
						break;
					}
				}
			}
		}

		for (int i = 0; i < k; ++i)
		{
			printf("%c",num[i] );
		}
		printf("\n");


		
		
	}
	return 0;
}