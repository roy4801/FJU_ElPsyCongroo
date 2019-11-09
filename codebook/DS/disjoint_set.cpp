// 有組大小 disjoint
#define N 100000
struct disjoint {
  int p[N+5];
  void init() {
    memset(p,-1,sizeof(p));
  }
  int find(int x) {
    return p[x]<0 ? x : (p[x]=find(p[x]));
  }
  void uni(int a, int b) {
    a = find(a), b = find(b);
    p[a] += p[b];
    p[b] = a;
  }
  bool isGroup(int a, int b) {
    return find(a) == find(b);
  }
  int siz(int x) {
    return (-p[find(x)]);
  }
};
