#include "segmentTree.h"
#include <cmath>

using namespace std;

#define TESTC ""
#define PROBLEM "segmentTree"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int pow(int n)
{
	if(n == 0)
		return 1;
	else if(n == 1)
		return 2;

	int half = pow(n/2);

	if(n % 2 != 0)
		return half * half * 2;
	else
		return half * half;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM "1" ".out", "w", stdout);
	#endif
	int size;

	scanf("%d", &size);

	for(int i = 1; i <= size && scanf("%d", &in[i]) != EOF; i++);

	// cout << size << '\n';
	// Build the segment tree
	buildSeg(1, 1, size);

	// for(int i = 1; i < pow(ceil(log2((double)size))+2); i++)
		// printf("%d ", t[i]);
	// puts("");
	// for(int i = 0; i < size*4; i++)
	// 	printf("%d ", segTree[i]);

	// Query
	int l, r;
	while(scanf("%d %d", &l, &r) != EOF && (l && r))
	{
		printf("%d\n", query(1, 1, size, l, r));
	}

	return 0;
}