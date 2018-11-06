/*
 * Floyd warshall algorithm test
 * Team: FJU_ElPsyCongroo
 */
#include "floyd_warshall.h"

#define TESTC ""
#define PROBLEM "floyd"
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    #ifdef DBG
    freopen(PROBLEM TESTC ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    #endif
    int in;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n && cin >> in; j++)
                d[i][j] = in == 0 && i != j ? INF : in;

        floyd_warshall();

        int min_dis = INT_MAX;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    min_dis = min(min_dis, d[i][j] + d[j][i]);
                }
            }
        cout << (min_dis >= INF ? -1 : min_dis) << '\n';

        findPath(0, 1);
        cout << '\n';
    }

    return 0;
}