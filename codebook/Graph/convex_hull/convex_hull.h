struct point
{
	int x, y;

	int dist(point b)
	{
		return (b.x - x) * (b.x - x) + (b.y - y) * (b.y - y);
	}

	int cross(point p2, point p3)
	{
		return (p2.x - x) * (p3.y - y) - (p2.y - y) * (p3.x - x);
	}

}base;


//K[N] 第N個凸包
//all:全部的點
//checked:真正凸包上的點
struct polygon
{
	vector<point> all;
	vector<point> checked;
}K[MAXN];

//找出最左下角的點
bool min_y(point a, point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

//點逆時針排序
bool c_clockwise(point a, point b)
{
	int c = base.cross(a, b);
	return c > 0 || (c == 0 && base.dist(a) < base.dist(b));
}

//畫凸包
//base左下角的點
void convex_hull(int num)
{
	//最左下角點開始
	swap(K[num].all[0], *min_element(K[num].all.begin(), K[num].all.end(), min_y));
	base = K[num].all[0];
	sort(K[num].all.begin()+1, K[num].all.end(), c_clockwise);
	K[num].all.PB(base);

	//枚舉，把外積負的人淘汰
	int m = 0;
	for (int i = 0; i < K[num].all.size(); i++)
	{
		//stack的上面兩個與該點做嘗試
		while (m >= 2 && K[num].checked[m-2].cross(K[num].checked[m - 1], K[num].all[i]) <= 0)
		{
			K[num].checked.pop_back();
			m--;
		}
		K[num].checked.PB(K[num].all[i]);
		m++;
	}
}

//確認點是否在凸包內
bool isinside(point pnt, int num)
{
	for (int i = 1; i < K[num].checked.size(); i++)
	{
		if (K[num].checked[i-1].cross(K[num].checked[i], pnt) < 0)
			return false;
	}
	return true;
}

//計算面積
double area(int num)
{
	double a = 0;
	for (int i = 1; i < K[num].checked.size(); i++)
		a += (K[num].checked[i-1].x * K[num].checked[i].y) - (K[num].checked[i].x * K[num].checked[i-1].y);

	a += (K[num].checked[K[num].checked.size()-1].x * K[num].checked[0].y) - (K[num].checked[0].x * K[num].checked[K[num].checked.size()-1].y);

	return a/2;
}