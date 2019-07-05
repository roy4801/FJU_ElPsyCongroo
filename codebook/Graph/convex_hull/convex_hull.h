struct point
{
	int x, y;
};

struct kindom
{
	vector<point> all;
	vector<point> checked;
	bool bomb = false;
};

//求兩點距離
int dist(point a, point b)
{
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

//外積
int cross(point p1, point p2, point p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

//找出最左下角的點
bool min_y(point a, point b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

//點逆時針排序
point base;
bool c_clockwise(point a, point b)
{
	int c = cross(base, a, b);
	return c > 0 || (c == 0 && dist(base, a) < dist(base, b));
}

//畫凸包
void convex_hull(kindom &kin)
{
	//最左下角點開始
	swap(kin.all[0], *min_element(kin.all.begin(), kin.all.end(), min_y));

	base = kin.all[0];
	sort(kin.all.begin() + 1, kin.all.end(), c_clockwise);
	//把原先的點在塞回做結尾判斷
	kin.all.PB(base);

	//枚舉，把外積負的人淘汰
	int m = 0;
	for (int i = 0; i < kin.all.size(); i++)
	{
		//stack的上面兩個與該點做嘗試
		while (m >= 2 && cross(kin.checked[m - 2], kin.checked[m - 1], kin.all[i]) <= 0)
		{
			kin.checked.pop_back();
			m--;
		}
		kin.checked.PB(kin.all[i]);
		m++;
	}
}

//確認點是否在凸包內
bool isinside(point bullet, kindom kin)
{
	for (int i = 1; i < kin.checked.size(); i++)
	{
		if (cross(kin.checked[i - 1], kin.checked[i], bullet) < 0)
			return false;
	}
	return true;
}

//計算面積
double area(kindom kin)
{
	double a = 0;
	for (int i = 1; i < kin.checked.size(); i++)
		a += (kin.checked[i-1].x * kin.checked[i].y) - (kin.checked[i].x * kin.checked[i-1].y);

	a += (kin.checked[kin.checked.size()-1].x * kin.checked[0].y) - (kin.checked[0].x * kin.checked[kin.checked.size()-1].y);

	return a/2;
}