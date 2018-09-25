#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "segmentTree"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

void buildSegTree(int segTree[], int val[], int p, const int L, const int R)
{
	// If it touches leafs
	if(L == R)
		segTree[p] = val[L];
	else
	{
		int mid = (L+R) / 2, lCh = p*2, rCh = lCh+1;

		buildSegTree(segTree, val, lCh, L, mid);    // Build left subtree [L, mid]
		buildSegTree(segTree, val, rCh, mid+1, R);  // Build right subtree [mid+1, R]

		segTree[p] = max(segTree[lCh], segTree[rCh]);
	}
}
void createSegTree(int segTree[], const int size, int val[])
{
	memset(segTree, -1, 4 * size * sizeof(int)); // clean
	buildSegTree(segTree, val, 1, 0, size-1);
}
int querySegTree(int segTree[], int p, int L, int R, int quL, int quR)
{
	int mid = (L+R)/2, ans = INT_MIN;

	if(L >= quL && R <= quR) // L, R are wrapped by quL, qyR
		return segTree[p];
	
	if(quL <= mid) // Left subtree
	{
		int tmp = querySegTree(segTree, 2*p, L, mid, quL, quR);
		ans = max(ans, tmp);
	}

	if(quR > mid) // Right subtree
	{
		int tmp = querySegTree(segTree, 2*p+1, mid+1, R, quL, quR);
		ans = max(ans, tmp);
	}

	return ans;
}


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