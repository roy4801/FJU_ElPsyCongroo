#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "B"
#define LEN 100
	
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)



int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string str1;
	string str2;
	int times;
	cin >> times;
	while(times--)
	{
		cin >> str1;
		cin >> str2;
		int cnt = 0;
		int big = 0;
		int k = 0;
		
		if (str1.length() < str2.length())
		{
			swap(str1,str2);
		}

		for (int i = 0; i < str1.length(); ++i)
		{
			if (cnt > big)
			{
				big = cnt;
			}
			cnt = 0;
			
			if (i + str2.length() - 1 >= str1.length())
			{
				k++;
			}

			for (int j = 0; j < str2.length() - k; ++j)
			{
				if (str1[i+j] == str2[j])
				{
					cnt++;
				}
			}
		}
		printf("%d\n", big);
	}

	return 0;

}