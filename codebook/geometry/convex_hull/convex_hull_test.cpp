#include <bits/stdc++.h>
#include "convex_hull.h>"
#define PB push_back
#define MAXN 1000

int main()
{
	int p;
	int idx=0;

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

	for(int i = 0; i < idx; i++)
		convex_hull(i);

	//原點是否在凸包中
	point pnt;
	pnt.x = 0, pnt.y = 0;
	for (int i = 0; i < idx; i++)
	{
		if(isinside(pnt, i))
			printf("Yes\n");
		else
			printf("No\n");
	}

	//計算1號凸包面積
	printf("%.lf\n", area(1));

	return 0;
}