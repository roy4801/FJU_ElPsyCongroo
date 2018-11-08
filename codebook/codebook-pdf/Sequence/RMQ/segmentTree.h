#define MAX_S 10000

 // 【注意】 1-index

int t[4*MAX_S+5];
int in[MAX_S+5];

#define LEFT(x) ((x)<<1)
#define RIGHT(x) (((x)<<1)+1)

// Build the segment tree
// parent, inputL, inputR
void buildSeg(int p, int inL, int inR)
{
	if(inL == inR)
	{
		t[p] = in[inL];
		return;
	}
	
	int mid = (inL+inR)/2;
	buildSeg(LEFT(p), inL, mid);
	buildSeg(RIGHT(p), mid+1, inR);
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}


// Modify single point, and maintain the segment tree
// parent, left, right, idx, val
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

// Query in [quL, quR]
// parnet, left, right, queryL, queryR
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