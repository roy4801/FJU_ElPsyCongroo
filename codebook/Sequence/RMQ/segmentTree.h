// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MAX_S 10000

int t[4*MAX_S+5]; // 1-index
int in[MAX_S+5];  // 1-index

#define LEFT(x) ((x)<<1)
#define RIGHT(x) (((x)<<1)+1)

/**
 * Build the segment tree
 * - p   Index of the parent node
 * - inL Left border of the input array
 * - inR Right border of the input array
 */
void buildSeg(int p, int inL, int inR)
{
	if(inL == inR)
	{
		t[p] = in[inL];
		return;
	}
	
	int mid = (inL+inR)/2;
	buildSeg(LEFT(p), inL, mid);    // build left subtree
	buildSeg(RIGHT(p), mid+1, inR); // build right subtree
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}

/**
 * Modify single point, and maintain the segment tree
 * - p Index of the parent node
 * - L Current left border
 * - R Current right border
 * - i Target index
 * - x Target value
 */
void modify(int p, int L, int R, int i, int x)
{
	// stop point
	if(i == L && L == R)
	{
		t[p] = x;
		return;
	}

	int mid = (L+R) / 2;
	if(i <= mid)
		modify(LEFT(p), L, mid, i, x);
	else
		modify(RIGHT(p), mid+1, R, i, x);
	// update this node
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}

/**
 * Query in [quL, quR]
 * - p      Index of the parent node
 * - L      Current left border
 * - R      Current right border
 * - quL    Query left border
 * - quR    Query right border
 * @return  max value
 */
int query(int p, int L, int R, int quL, int quR)
{
	// stop point
	if(quL <= L && R <= quR)
	{
		return t[p];
	}
	
	int mid = (L+R) / 2;

	if(quR <= mid) // left
		return query(LEFT(p), L, mid, quL, quR);
	else if(mid < quL) // right
		return query(RIGHT(p), mid+1, R, quL, quR);
	else // middle
		return max(query(LEFT(p), L, mid, quL, quR),
				   query(RIGHT(p), mid+1, R, quL, quR));
}