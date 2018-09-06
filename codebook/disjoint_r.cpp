#include <bits/stdc++.h>

using namespace std;


/* 
 * Disjoint set impl
 * 
 */
#define SIZE 1000005
int p[SIZE];

/*
 * void init()
 * @參數: 空
 */
void init()
{
	for(int i = 0; i < SIZE; i++)
		p[i] = i;
}

/*
 * int find(const int x)
 * @參數: 
 */
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

#define PDISJ(x) for(int i = 1; i < (x) && (~printf("%d ", p[i])); i++); putchar('\n')

int main()
{
	// 初始化(必須)
	init();
	
	// 將1, 2變成同組
	uni(1, 2);
	// 將2, 3變成同組
	uni(2, 3);

	// 列出前10個的組別
	for(int i = 1; i <= 10; i++)
		printf("%d's group is %d\n", i, find(i));
	
	PDISJ(10);

	return 0;
}