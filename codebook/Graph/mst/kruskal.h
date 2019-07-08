// Need disjoint set
#define V 50000
#define E 200000

struct edge
{
  int fr, to, wei;
  void setEdge(int f, int t, int w)
  { fr = f; to = t; wei = w;}
  friend bool operator<(edge &lhs, edge &rhs)
  { return lhs.wei < rhs.wei; }
}e[E+5];
int n, m;  // n vertice, m edges
int kruskal()
{
  init(); // disjoint
  sort(e, e+m);
  // i -> cur vectex, j -> cur edge
  int total = 0, i, j;
  for(i = 0, j = 0; i < n-1 && j < m; i++, j++)
  {
    while(find(e[j].fr) == find(e[j].to))
      j++;
    uni(e[j].fr, e[j].to);
    total += e[j].wei;
  }
  return i == n-1 ? total : -1;
}