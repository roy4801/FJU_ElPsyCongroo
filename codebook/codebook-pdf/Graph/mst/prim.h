#define INF 0x3f3f3f3f
#define F first
#define S second

#define V 50000
#define E 200000

typedef pair<int, int> P;
vector<P> e[E]; // e[from] => (to, weight)

// 無向圖
void addEdge(int from, int to, int weight)
{
    e[from].emplace_back(to, weight);
    e[to].emplace_back(from, weight);
}

int d[V];
int nt[V];

// n個點, m個邊
int n, m;

int prim(int src)
{
    for(int i = 0; i < V; i++) d[i] = INF;
    // 放點的暫時權重 (weight, idx)
    priority_queue<P, vector<P>, greater<P> > pq;
    int total = 0, v = 0, pre = -1; // 總和, 找到的點
    // 加入起點
    pq.emplace(0, src);

    int to, wei;
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        // 如果點cur已經當過top(不是第一次)
        if(d[cur.S] != INF)
            continue;
        // 更新該點的d[]，代表選了該點
        d[cur.S] = 0;
        nt[pre] = cur.S;
        pre = cur.S;
        total += cur.F;
        v++;
        // 遍歷所有跟點cur相連的邊
        for(auto i : e[cur.S])
        {
            tie(to, wei) = i;
            // 如果點to沒有選到過
            if(d[to] == INF)
            {   // 看有沒有更小的權重
                if(wei < d[to])
                {
                    pq.emplace(wei, to);
                }
                else
                    pq.emplace(d[to], to);
            }
        }
    }
    // 如果生成樹有n個點(全部找到)則輸出，否則輸出-1
    return v == n ? total : -1;
}

void findPath(int src)
{
    for(int i = 0; i < n; i++)
        if(nt[i]+1 != src+1)
            cout << i+1 << ' ' << nt[i]+1 << '\n';
}