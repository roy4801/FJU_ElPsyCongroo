vector <int> G[N];
bitset <N> vis;

void dfs(int s)
{
	vis.reset();
	vis[s] = 1;
	for(int i : G[s])
	{
		if(!vis[i])
			dfs(i);
	}
}

void bfs(int s)
{
	queue <int> que;
	que.push(s);
	vis[s] = 1;

	while(!que.empty())
	{
		int tmp = que.front();
		que.pop();

		for(int i : G[s])
		{
			if(!vis[i])
			{
				que.push(i);
				vis[i] = 1;
			}
		}
	}
}


