#define N 10000
int bit[N+5];
#define lowbit(x) ((x)&-(x))
void add(int x, int v)
{
	while(x <= n)
	{
		bit[x] += v;
		x += lowbit(x);
	}
}

int sum(int ri)
{
	int sum = 0;
	while(ri > 0)
	{
		sum += bit[ri];
		ri -= lowbit(ri);
	}
	return sum;
}

int query(int left, int right)
{
	return sum(right) - sum(left-1);
}