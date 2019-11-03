// build O(nlogn) query O(logn)
#define N 10000
int BIT[N+5];
int n, arr[N+5];
#define lowbit(x) ((x)&(-x))
inline void update(int x, int v)
{
  for(; x <= N; x += lowbit(x))
    BIT[x] += v;
}
inline void build()
{
  memset(BIT, 0, sizeof(BIT));
  for(int i = 1; i < n; i++)
    update(i, arr[i]);
}
inline int query(int x)
{// return [1, x]
  int ans = 0;
  for(; x; x -= lowbit(x))
    ans += BIT[x];
  return ans;
}
