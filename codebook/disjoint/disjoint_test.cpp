/*
 * Struct disjoint set Test
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include "epk_disjoint.h"

using namespace std;

void printWholeSet(const Disjoint &d)
{
	for(int i = 0; i < Disjoint::MAX; i++)
	{
		printf(i != Disjoint::MAX-1 ? "%d " : "%d\n", d.p[i]);
	}
}

int main()
{
	Disjoint d;

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

	
	return 0;
}