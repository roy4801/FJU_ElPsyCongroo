/*
 * Kruskal's algorithm implementation
 * Team: FJU_ElPsyCongroo
 */
#include <bits/stdc++.h>
using namespace std;

#define V 50000
#define E 200000

// disjoint set
int ds[V];
void init() { for(int i = 0; i < V; i++) ds[i] = i; }
int find(int i) { return ds[i] == i ? i : (ds[i] = find(ds[i])); }
void uni(int a, int b) { ds[find(a)] = find(b); }

struct edge
{
	int fr, to, wei;
	void setEdge(int f, int t, int w) { fr = f; to = t; wei = w;}
	friend bool operator<(edge &lhs, edge &rhs) { return lhs.wei < rhs.wei; }
}e[E];

int n, m;  // n vertice, m edges

int kruskal()
{
	init();

	sort(e, e+m);

	int total = 0, i, j; // i -> cur vectex, j -> cur edge
	for(i = 0, j = 0; i < n-1 && j < m; i++, j++)
	{
		// if it's in the same group, skipping it.
		while(find(e[j].fr) == find(e[j].to))
			j++;

		uni(e[j].fr, e[j].to);

		total += e[j].wei;
	}

	return i == n-1 ? total : -1;
}