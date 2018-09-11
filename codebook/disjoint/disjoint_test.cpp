/*
 * Struct disjoint set Test
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include "epk_disjoint.h"

using namespace std;

void printWholeSet(const Disjoint<int> &d)
{
	for(int i = 0; i < Disjoint<int>::MAX; i++)
		printf(i != Disjoint<int>::MAX-1 ? "%d " : "%d\n", d.p[i]);
	for(int i = 0; i < Disjoint<int>::MAX; i++)
		printf(i != Disjoint<int>::MAX-1 ? "%d " : "%d\n", d.data[i]);
}

int main()
{
	Disjoint<int> d;

	d[1] = 999;
	d[2] = 123;
	d[3] = 7583;
	d[7] = 124;
	d[10] = 113;
	printf("1\n");
	printWholeSet(d);

	printf("\n2\n");
	d.uni(1, 2);
	d.uni(2, 3);
	printWholeSet(d);

	printf("\n3\n");
	d.uni(7, 2);
	printWholeSet(d);

	printf("\n4\n");
	d.uni(1, 10);
	printWholeSet(d);


	// Find all group members are the same group
	int target  = 1;
	for(int i = 1; i <= Disjoint<int>::MAX; i++)
	{
		if(d.equ(target, i))
			printf("%d %d\n", i, d[i]);
	}
	
	return 0;
}