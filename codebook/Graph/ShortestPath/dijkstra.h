#define N 500
#define E 10000
#define INF 2e9
vector<P> e[E]; // (to, weight) edge
int d[N];       // 記錄起點到各個點的最短路徑長度
int n, m;       // n 個點 m個邊
 
void dijkstra(int src)
{
  for (int i = 0; i < n; i++) d[i] = INF;
  // (dis, idx)
  priority_queue<P, vector<P>, greater<P> > pq;
  pq.emplace(0, src);

  while(!pq.empty())
  {
    int a = -1, b = -1, wei;

    tie(wei, a) = pq.top(); pq.pop();

    if(d[a] != INF) continue;

    d[a] = wei;
    for(auto i : e[a])
      if(d[i.first] == INF)
        pq.emplace(wei + i.second, i.first);
  }
}