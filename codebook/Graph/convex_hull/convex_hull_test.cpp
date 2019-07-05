#include <bits/stdc++.h>
#include "convex_hull.h>"
#define PB push_back
#define MAXN 1000

int main()
{
	int p;
	kindom K[MAXN];
	int idx = 0;

	while(scanf("%d",&p) && p >= 0)
	{
		int x,y;
		for(int i = 0; i < p; i++)
		{
			scanf("%d %d\n", &x, &y);
			K[idx].all.PB({x,y});
		}
		idx++;
	}

	//製作凸包
	for(int i = 0; i < idx; i++)
		convex_hull(K[i]);

	//確認點在凸包內
	point bullet;
	double ans = 0;
	bool flag = 0;
	while(~scanf("%d %d\n",&bullet.x, &bullet.y))
	{
		for (int i = 0; i < idx; i++)
		{
			if (attacked(bullet, K[i]))
			{
				cout << "Yes" << '\n';
				flag = 1;
				break;
			}
		}
	}
	if(!flag)
		cout << "No" << '\n';
	return 0;
}