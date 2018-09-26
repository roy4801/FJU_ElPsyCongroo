#include "segmentTree.h"

using namespace std;

#define TESTC ""
#define PROBLEM "segmentTree"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int size;

	scanf("%d", &size);

	int val[size];
	for(int i = 0; i < size && scanf("%d", &val[i]) != EOF; i++);

	// Build the segment tree
	int segTree[size * 4];
	createSegTree(segTree, size, val);

	// for(int i = 0; i < size*4; i++)
	// 	printf("%d ", segTree[i]);

	// Query
	int l, r;
	while(scanf("%d %d", &l, &r) != EOF && (l && r))
	{
		l--, r--;
		printf("%d\n", querySegTree(segTree, 1, 0, size-1, l, r));
	}

	return 0;
}