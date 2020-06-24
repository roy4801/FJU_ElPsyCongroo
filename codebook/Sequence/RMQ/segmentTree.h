#define N 100000
#define LEFT(x) ((x)<<1)
#define RIGHT(x) (((x)<<1)+1)
// 1-idx
int t[4*N+5];
int in[N+5];
// parent, left, right
void build(int p, int L, int R)
{
	if(L == R)
	{
		t[p] = in[L];
		return;
	}
	int mid = (L+R)/2;
	build(LEFT(p), L, mid);
	build(RIGHT(p), mid+1, R);
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}
// treeIdx, left, right, targetIdx, tragetVal
void modify(int p, int L, int R, int i, int x)
{
	if(i == L && L == R)
	{
		t[p] = x;
		return;
	}
	int mid = (L+R) / 2;
	// modify left subtree
	if(i <= mid)
		modify(LEFT(p), L, mid, i, x);
	else
		modify(RIGHT(p), mid+1, R, i, x);
	// merge
	t[p] = max(t[LEFT(p)], t[RIGHT(p)]);
}
// treeIdx, left, right, queryleft, queryright
int query(int p, int L, int R, int quL, int quR)
{
	if(quL <= L && R <= quR)
		return t[p];
	int mid = (L+R)/2;
	if(quR <= mid) // left
		return query(LEFT(p), L, mid, quL, quR);
	else if(mid < quL) // right
		return query(RIGHT(p), mid+1, R, quL, quR);
	else // mid
		return max(query(LEFT(p), L, mid, quL, quR), query(RIGHT(p), mid+1, R, quL, quR));
}
