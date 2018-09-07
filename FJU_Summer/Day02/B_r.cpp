// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int findLineSum(int m[3][3])
{
	int s = -1;

	for(int i = 0; i < 3; i++)
	{
		if(m[i][0] != 0 && m[i][1] != 0 && m[i][2] != 0)
		{
			s = m[i][0] + m[i][1] + m[i][2];
			goto exit;
		}

		if(m[0][i] != 0 && m[1][i] != 0 && m[2][i] != 0)
		{
			s = m[0][i] + m[1][i] + m[2][i];
			goto exit;
		}
	}

	if(!m[0][0] && !m[1][1] && !m[2][2])
	{
		s = m[0][0] + m[1][1] + m[2][2];
	}
	else if(!m[0][2] && !m[1][1] && !m[2][0])
	{
		s = m[0][2] + m[1][1] + m[2][0];
	}

exit:
	return s;
}

#define HEAD 0
#define MID 1
#define END 2

void fill(int m[3][3], const int i, const int j, const int line)
{
	if(i == MID || j == MID)
	{
		
	}
}

int main()
{
	#ifdef DBG
	freopen("B_r.in", "r", stdin);
	freopen("B_r.out", "w", stdout);
	#endif
	int cases, n;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &n) != EOF)
	{
		int m[3][3] = {0};

		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				scanf("%d", &m[i][j]);

 		printf("%d\n", findLineSum(m));


	}

	return 0;
}