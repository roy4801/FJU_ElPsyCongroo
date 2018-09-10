#include <bits/stdc++.h>

using namespace std;

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

#define PDISJ(x) for(int i = 0; i < (x) && (~printf("%d ", p[i])); i++); putchar('\n')

int main()
{
	init();
	
	uni(1, 2);
	uni(2, 3);
	
	PDISJ();

	return 0;
}
