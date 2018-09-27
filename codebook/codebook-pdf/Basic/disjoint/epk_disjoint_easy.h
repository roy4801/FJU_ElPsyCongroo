/*
 * Easy disjoint set implmentation
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#define SIZE 1000005
int p[SIZE];

/*
 * void init()
 * Description: Initialize the disjoint set
 */
void init()
{
	for(int i = 0; i < SIZE; i++)
		p[i] = i;
}
/*
 * int find(const int x)
 * Description: Find the team leader of idx x
 */
int find(const int x)
{
	return x==p[x] ? x : find(p[x]);
}
/*
 * void uni(const int a, const int b)
 * Description: Make a and b same group
 */
void uni(const int a, const int b)
{
	p[find(a)] = p[find(b)];
}
/*
 * bool equ(const int a, const int b)
 * Description: If a and b are in the same group
 */
bool equ(const int a, const int b)
{
	return find(a) == find(b);
}