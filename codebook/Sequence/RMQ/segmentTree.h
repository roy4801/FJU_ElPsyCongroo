#define N 10000
// 1-index
int t[4*N+5];
int in[N+5];

#define LEFT(x) ((x)<<1)
#define RIGHT(x) (((x)<<1)+1)
// parent, left, right
void buildSeg(int p, int inL, int inR)
{
	if(inL == inR) {
		t[p] = in[inL];
		return;
	}
	int mid = (inL+inR)/2;
	buildSeg(LEFT(p), inL, mid);    // build left subtree
	buildSeg(RIGHT(p), mid+1, inR); // build right subtree
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}
// treeIdx, left, right, targetIdx, tragetVal
void modify(int p, int L, int R, int i, int x)
{
	// stop point
	if(i == L && L == R) {
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
// treeIdx, left, right, queryleft, queryright
int query(int p, int L, int R, int quL, int quR)
{
	if(quL <= L && R <= quR) {
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