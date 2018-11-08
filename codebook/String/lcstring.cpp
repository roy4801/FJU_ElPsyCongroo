#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str1,str2;
	while(cin >> str1 >> str2)
	{
		string rec;
		int arr[100][100];

		memset(arr,0,sizeof(arr));

		int maxx = 0;
		int position = 0;

		for (int i = 1; i <= str1.length() ; ++i)
		{
			for (int j = 1; j <= str2.length() ; ++j)
			{
				if (str1[i-1] == str2[j-1])
				{
					arr[i][j] = arr[i-1][j-1] + 1;

					if (maxx < arr[i][j])
					{
						position = i;
						maxx = arr[i][j];
					}
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}

		for (int k = position - maxx; k < position; ++k)
		{
			rec += str1[k];
		}

		cout << rec << endl;
	}
	return 0;
}