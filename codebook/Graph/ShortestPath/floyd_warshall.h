#define INF 0x3f3f3f3f
#define N 100

int d[N][N]; // 0-index
int p[N][N]; // path
int n;       // n vertice

void floyd_warshall()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      p[i][j] = (d[i][j] == INF
        || d[i][j] == 0 ? -1 : i);

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(d[i][j] > d[i][k] + d[k][j])
        {
          d[i][j] = d[i][k] + d[k][j];
          p[i][j] = p[k][j];
        }
}

void findPath(int src, int end)
{
  if(p[src][end] != -1)
    findPath(src, p[src][end]);
  cout << end << ' ';
}