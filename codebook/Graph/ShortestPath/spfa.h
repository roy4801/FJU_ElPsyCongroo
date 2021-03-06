#define N 505
#define E 20005
#define INF 2e9
vector<P> e[E]; // (to, weight) 邊
int d[N];       // 距離
int parent[N];  // parent idx pf a node
bool inq[N];    // inqueue
int cnt[N];     // path updating counter
bool del[N];    // 被刪掉的node，用於判斷
int n, m;       // vertice, edges

void dfs(int src)
{
  int to, wei;

  del[src] = true;
  for(auto i : e[src])
  {
    tie(to, wei) = i;
    // 如果沒刪除的話
    if(!del[to])
      dfs(to);
  }
}

void spfa(int src)
{
  for(int i = 0; i < n; i++) d[i]=  INF;
  d[src] = 0;
  parent[src] = src;
  cnt[src] = 0;
  queue<int> q;
  q.push(src);
  
  while(!q.empty())
  {
    int cur = q.front(), to, wei;
    q.pop();
    inq[cur] = false;
    
    for(auto i : e[cur])
    {
      tie(to, wei) = i;
      if(!del[to] && d[cur] + wei < d[to])
      {
        d[to] = d[cur] + wei;
        parent[to] = cur;

        if(!inq[to])
        {
          cnt[to]++;

          if(cnt[to] >= n)
          {
            dfs(to);
            continue;
          }

          q.push(to);
          inq[to] = true;
        }
      }
    }
  }
  // 無限小
  for(int i = 0; i < n; i++)
    if(del[i])
      d[i] = -INF;
}

void findPath(int src, int end)
{
  if(src != end)
    findPath(src, parent[end]);
  cout << end << ' ';
}