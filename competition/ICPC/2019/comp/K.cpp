#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define PB push_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MAXN
#define N
int kase, n, tmp;
int main()
{
    cin >> kase;
    while(kase-- && cin >> n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n && cin >> tmp; i++)
            pq.push(tmp);
        int ans = 0;
        while(pq.size() >= 2)
        {
            int tmp = 0;
            tmp += pq.top(); pq.pop();
            tmp += pq.top(); pq.pop();
            ans += tmp;
            //printf(">> %d\n", tmp);
            pq.push(tmp);
        }
        printf("%d\n", ans);
    }
}
