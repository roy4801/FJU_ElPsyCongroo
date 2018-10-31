/*
 * Dijkstra shortest path
 * Team: FJU_ElPsyCongroo
 */
#include <bits/stdc++.h>
using namespace std;

#define N 10000
typedef pair<int, int> P;
#define INF 2e9

// ATTENTION: 0-index

vector<P> w[N]; // (to, weight)
int d[N];       // 記錄起點到各個點的最短路徑長度
int parent[N];  // 記錄各個點在最短路徑樹上的父親是誰
int n;          // n 個點
 
void dijkstra(int src)
{
    for (int i = 0; i < n; i++) d[i] = INF;

    // (dis, idx)
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.emplace(0, src);

    parent[src] = src;

    while(!pq.empty())
    {
        int a = -1, b = -1, wei;

        // 從pq裡拿出最小的點
        tie(wei, a) = pq.top();
        pq.pop();

        // 如果拜訪過了(當過pq.top)
        if(d[a] != INF) continue;

        d[a] = wei;
        for(auto i : w[a])
        {
            if(d[i.first] == INF)
            {
                pq.emplace(wei + i.second, i.first);
                parent[i.first] = a; // set parent node
            }
        }
    }
}

void findPath(int src, int start)
{
    if(start != src)
        findPath(src, parent[start]);
    cout << start << ' ';
}