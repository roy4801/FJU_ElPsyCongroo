#include <bits/stdc++.h>

using namespace std;

// By roy4801 50

#define SIZE 1000005

int p[SIZE];

void init()
{
	for(int i = 0; i < SIZE; i++)
		p[i] = i;
}

int find(const int x)
{
	return x==p[x] ? x : find(p[x]);
}

void uni(const int a, const int b)
{
	p[find(a)] = p[find(b)];
}

bool equ(const int a, const int b)
{
	return find(a) == find(b);
}

#define PRINT(x) for(int i = 0; i < (x) && (~printf("%d ", p[i])); i++); putchar('\n')

int main()
{
	#ifdef DBG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif
	init();
	int num, inL, inR, maxIn = -1;

	scanf("%d", &num);

	while(num-- && scanf("%d %d", &inL, &inR) != EOF)
	{
		maxIn = max(maxIn, inR);
		// printf("m %d\n", maxIn);

		for(int i = inL; i <= inR - 1; i++)
			uni(i, i+1);
	}


	int st = 1, end;
	while(st <= maxIn)
	{
		end = find(st);
		
		printf("%d %d\n", st, find(st));

		st = end+1;
	}


	// int st = 1, end = st;

	// while(end <= maxIn + 1)
	// {
	// 	if(!equ(st, end))
	// 	{
	// 		printf("%d %d\n", st, end-1);
	// 		st = end;

	// 		// printf("%d\n", st);
	// 	}

	// 	end++;
	// }

	return 0;
}