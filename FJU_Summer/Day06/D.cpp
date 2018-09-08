#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "D"

// queue<int> que;
#define N 100000

// template<typename T>
struct Queue
{
	static const int MAX = N;
	int d[MAX+1];
	int fr = 0, ba = 0;

	int front()
	{
		return d[fr];
	}
	void pop()
	{
		fr++;
		fr %= Queue::MAX;
	}
	void push(const int n)
	{
		d[ba++] = n;
		ba %= Queue::MAX;
	}
	bool empty()
	{
		return fr == ba;
	}
	void print()
	{
		for(int i = fr; i < ba; i++)
			printf("%d ", d[i]);
		putchar('\n');
	}
}que;

void bfs(const int size, void *mm, int root)
{
	// bug for g++
	bool (*m)[size+1] = static_cast<bool (*)[size+1]>(mm);
	bool tra[size+1];

	memset(tra, false, sizeof(tra));

	que.push(root);
	// tra[root] = true;

	while(!que.empty())
	{
		int from = que.front();

		if(!tra[from])
			printf("%c ", 'A' + from-1);
		tra[from] = true;

		// putchar('\n');
		// que.print();
		

		for(int to = 1; to <= size; to++)
		{
			// printf("%c ", tra[to] ? 'T' : 'F');
			// printf("%d %d\n", from, to);
			if(!tra[to] && m[from][to])
			{
				// printf("	can go to %c\n", 'A' + to-1);
				// printf("IN %d %d\n", from, to);
				que.push(to);
			}
		}
		// putchar('\n');
		que.pop();
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int n, r;

	scanf("%d %d", &n, &r);

	// 1-index
	int time[n+1];
	bool m[n+1][n+1];

	// init
	memset(time, 0, sizeof(time));
	memset(m, false, sizeof(m));

	for(int i = 1; i <= n; i++)
		scanf("%d", &time[i]);

	// Build the graph
	int from, to;
	for(int i = 0; i < r && scanf("%d %d", &from, &to) != EOF; i++)
	{
		// printf("%d %d\n", from, to);
		m[from][to] = true;
	}
	// printf("%s\n", m[4][6] ? "YES" : "NO");

	bfs(n, m, 1);

	return 0;
}