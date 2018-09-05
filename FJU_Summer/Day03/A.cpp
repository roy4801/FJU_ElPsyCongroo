#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif

	int height,length,times;

	scanf("%d %d",&height ,&length);
	scanf("%d ",&times);

	char m[height][length];

	
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			scanf("%c",&m[i][j]);
		}
		getchar();
	}


	while(times--)
	{
		int x1,y1,x2,y2;
		int first=0 ,second=0 ,third=0;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x1--;
		y1--;
		x2--;
		y2--;

		
		for (int i = x1; i <= x2; ++i)
		{
			for (int j = y1; j <= y2 ; ++j)
			{
				// printf("%d %d\n", i,j);
				// printf("%c\n", m[i][j]);
				if (m[i][j] == 'J')
				{
					first++;
				}
				if (m[i][j] == 'O')
				{
					second++;
				}
				if (m[i][j] == 'I')
				{
					third++;
				}
			}
		}

		printf("%d %d %d\n", first,second,third);
	}

	return 0;
}