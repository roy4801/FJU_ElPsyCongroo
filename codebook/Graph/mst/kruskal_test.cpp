/*
 * Kruskal's algorithm test
 * Team: FJU_ElPsyCongroo
 */
#include "kruskal.h"
 
#define TESTC ""
#define PROBLEM "kruskal"
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
    freopen(PROBLEM TESTC ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    #endif
    int fr, to, wei;
    while(cin >> n >> m)
    {
    	for(int i = 0; i < m && cin >> fr >> to >> wei; i++)
    		e[i].setEdge(fr, to, wei);

    	cout << kruskal() << '\n';
    }


	return 0;
}