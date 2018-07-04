#include <iostream>

using namespace std;

int n;

int *x, **Xor;

void init()
{
	x = new int[n];
	Xor = new int*[n];
	for(int i = 0; i < n; i++)
	{
		Xor[i] = new int[n];
	}

	for(int i = 0; i < n; i++)
	{
		x[i] = -1;
		for(int j = 0; j < n; j++)
		{
			Xor[i][j] = -1;
		}
	}
}

// void tell(int x[], int Xor[][n], const int p, const int v)
// {
// 	x[p] = v;
// }

// void tell(int x[], int Xor[][n], const int p, const int q, const int v)
// {
// 	Xor[p][q] = v;
// 	Xor[q][p] = v;
// }

// int query(int x[], int Xor[][n], int k)
// {
// 	int tmp, rt;

// 	if(k == 1)
// 	{
// 		if(x[k])
// 	}
// 	else if(k == 2)
// 	{

// 	}
// 	else
// 	{
// 		for(int i = 0; i < k; i++)
// 		{

// 		}
// 	}
// }

int main()
{
	#ifdef DBG
	// freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif
	int qu;
	char input[30];

	while(scanf("%d %d ", &n, &qu) != EOF && (n && qu))
	{
		// int x[n];
		// int Xor[n][n];

		init();

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d ", Xor[i][j]);
			}
			putchar('\n');
		}

		// while(qu--)
		// {
		// 	char opt = getchar();
		// 	gets(input); // get numbers

		// 	switch(opt)
		// 	{
		// 		case 'I':
		// 		{
		// 			int p, q, v;
		// 			int rt = sscanf(input, "%d %d %d", &p, &q, &v);

		// 			if(rt == 2)
		// 			{
		// 				// tell(x, Xor, p, q);
		// 			}
		// 			else if(rt == 3)
		// 			{
		// 				// tell(x, Xor, p, q, v);
		// 			}
		// 		}
		// 		break;

		// 		case 'Q':
		// 		{
		// 			int k;
		// 			scanf("%d ", &k);
		// 			// query(x, Xor, k);
		// 		}
		// 		break;
		// 	}
		// }
	}

	return 0;
}
