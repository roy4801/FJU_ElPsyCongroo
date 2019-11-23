// EdmondsKarp  n=點數 N=上限
// ek.init(n);
// 1--2 10容 無向
ek.add_edge(1, 2, 10, false);
ek.maxflow(); // -> 回傳最大流
struct EK
{
  struct Edge {
    int fr,to,cap,flow;
    Edge(int u,int v,int c,int f):fr(u),to(v),cap(c),flow(f){}
  };
  int n,m;
  vector<Edge> E; // 边数的两倍
  vector<int> G[N+5]; // 邻接表，G[i][j]表示结点i的第j条边在E数组中的序号
  int bnk[N+5];   // s 到 i 的瓶頸
  int p[N+5];     // p[v] = 路徑上的邊 (u, v) 的在 E 的 index
  void init(int n)
  {
    for(int i = 0; i < n; i++) G[i].clear();
    E.clear();
    memset(p, 0, sizeof(p));
  }
  void add_edge(int fr, int to, int cap, bool dir=true)
  {
    E.push_back(Edge(fr, to, cap, 0));
    E.push_back(Edge(to, fr, dir ? 0 : cap, 0)); // 反向弧
    m = E.size();
    G[fr].push_back(m-2);
    G[to].push_back(m-1);
  }
  int bfs()
  {
    memset(bnk, 0, sizeof(bnk));
    queue<int> q;
    q.push(s);
    bnk[s] = INF;
    while(!q.empty())
    {
      int cur = q.front(); q.pop();
      for(auto &i : G[cur])
      {
        Edge &e = E[i];
        if(!bnk[e.to] && e.cap > e.flow)
        {
          p[e.to] = i;
          bnk[e.to] = min(bnk[cur], e.cap - e.flow);
          q.push(e.to);
        }
      }
      if(bnk[t]) break;
    }
    if(!bnk[t]) return 0;
    for(int u = t; u != s; u = E[p[u]].fr) // 增廣路
    {
      E[p[u]].flow += bnk[t];
      E[p[u]^1].flow -= bnk[t];
    }
    return bnk[t];
  }
  int maxflow(int s,int t)
  {
    int flow=0, m;
    while((m = bfs()))
      flow += m;
    return flow;
  }
};