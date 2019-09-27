// 有組大小 disjoint
#define N 100000
struct disjoint {
  int p[N+5], siz[N+5];
  void init() {
    for(int i = 0; i <= N; i++) {
        p[i] = i;
        siz[i] = 1;
    }
  }
  int find(int x) {
    return p[x]==x ? x : (p[x]=find(p[x]));
  }
  void uni(int a, int b) {
    a = find(a), b = find(b);
    if(siz[a] > siz[b]) {
        p[b] = p[a];
        siz[a] += siz[b];
        siz[b] = 0;
    }
    else {
        p[a] = p[b];
        siz[b] += siz[a];
        siz[a] = 0;
    }
  }
  bool isGroup(int a, int b) {
    return find(a) == find(b);
  }
  int size(int x) {
    return siz[find(x)];
  }
};