#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "E"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

enum POS
{
	POS_I,
	POS_J
};

#define PGO(x) x = x != 'F' ? '@' : 'F'

#define N 105

char mm[N][N];
int fire[10][2];
int n, m;
int f, e;

queue<pair<int, int> > que;



// grow fire
int fireLen = 1;
void grow()
{
	for(int i = 0; i < f; i++)
	{
		// UP
		if(fire[i][POS_I] >= s)
			mm[fire[i][POS_I] - s][fire[i][POS_J]] = 'F';
		// DOWN
		if(fire[i][POS_I] <= n-1 - s)
			mm[fire[i][POS_I] + s][fire[i][POS_J]] = 'F';
		// LEFT
		if(fire[i][POS_J] >= s)
			mm[fire[i][POS_I]][fire[i][POS_J] - s] = 'F';
		// RIGHT
		if(fire[i][POS_J] <= n-1 - s)
			mm[fire[i][POS_I]][fire[i][POS_J] + s] = 'F';
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int x, y;

	while(cin >> n >> m >> x >> y >> f >> e)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				mm[i][j] = '.';
		
		for(int i = 0; i < f; i++)
		{
			cin >> fire[i][0] >> fire[i][1];
			mm[fire[i][0]][fire[i][1]] = 'F';
		}

		int e1, e2;
		for(int i = 0; i < e; i++)
		{
			cin >> e1 >> e2;
			mm[e1][e2] = 'E';
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				putchar(mm[i][j]);
			}
			putchar('\n');
		}
	}

	return 0;
}