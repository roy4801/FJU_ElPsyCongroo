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
	USE_CPPIO();

	int times;
	string str;

	cin >> times;
	getline(cin,str);

	while(times--)
	{
		getline(cin,str);

		for (int i = 0; i < str.length(); ++i)
		{
			str[i] = tolower(str[i]);
			
		}
		// cout << str << '\n';

		int flag = 0;

		if (flag == 0)
		{
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] == 'n')
				{
					flag = 1;
					cout << "No" << '\n';
					break;
				}
			
			}
		}
		
		if (flag == 0)
		{
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] == 'a' && i < str.length() - 1)
				{
					if (str[i+1] == 'c')
					{
						flag = 2;
						cout << "Yes" << '\n'; 
						break;
					}
					
				}
			}
		}
		
		if (flag == 0)
		{
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] == 'y' && i < str.length() - 2)
				{
					if (str[i+1] == 'e' && str[i+2] == 's')
					{
						flag = 3;
						cout << "Yes" << '\n'; 
						break;
					}	
				}
			}
		}
		

		if (!flag)
		{
			cout << "Unknown" << '\n';
		}

	}
	return 0;
}