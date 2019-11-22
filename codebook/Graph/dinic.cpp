template <typename T>
struct Dinic
{
  int n, s, t, level[M], now[M];
  struct Edge
  {
    int v;
    T rf; // rf: residual flow
    int re;
  };
  vector<Edge> e[M];
  void init(int _n, int _s, int _t)
  {
    n = _n;
    s = _s;
    t = _t;
    for (int i = 0; i <= n; i++)
    {
      e[i].clear();
    }
  }
  void add_edge(int u, int v, T f)
  {
    e[u].push_back({v, f, (int)e[v].size()});
    e[v].push_back({u, f, (int)e[u].size() - 1});
  }
  bool bfs()
  {
    fill(level, level + n + 1, -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (auto it : e[u])
      {
        if (it.rf > 0 && level[it.v] == -1)
        {
          level[it.v] = level[u] + 1;
          q.push(it.v);
        }
      }
    }
    return level[t] != -1;
  }
  T dfs(int u, T limit)
  {
    if (u == t)
      return limit;
    int res = 0;
    while (now[u] < (int)e[u].size())
    {
      Edge &it = e[u][now[u]];
      if (it.rf > 0 && level[it.v] == level[u] + 1)
      {
        T f = dfs(it.v, min(limit, it.rf));
        res += f;
        limit -= f;
        it.rf -= f;
        e[it.v][it.re].rf += f;
        if (limit == 0)
        {
          return res;
        }
      }
      else
      {
        ++now[u];
      }
    }
    if (!res)
    {
      level[u] = -1;
    }
    return res;
  }
  T flow(T res = 0)
  {
    while (bfs())
    {
      T tmp;
      memset(now, 0, sizeof(now));
      do{
        tmp = dfs(s, INF);
        res += tmp;
      }while(tmp);
    }
    return res;
  }
};

Dinic<int> dinic; // declare, flow type is int
dinic.init(n, s, t); // initialize, n vertexs, start from s to t
dinic.add_edge(x, y, z); // add edge from x to y, weight is z
dinic.flow() // calculate max flow