#include <bits/stdc++.h>

using namespace std;

struct Interval
{
	int f, e;

	Interval()
	{
		f = e = 0;
	}
	Interval(const int front, const int end)
	{
		f = front;
		e = end;
	}
	Interval(const Interval& other)
	{
		f = other.f;
		e = other.e;
	}

	friend bool operator==(const Interval &lhs, const Interval &rhs)
	{
		return lhs.f == rhs.f && lhs.e == rhs.e;
	}

	bool operator<(const Interval &other)
	{
		return f < other.f;
	}
};

vector<Interval> l;

bool inner(const Interval &l, const Interval &r)
{
	return l.f <= r.f && l.e >= r.e; 
}

bool judge(Interval &lhs, const Interval &r)
{
	bool ret = true;

	// printf("%d %d - %d %d\n", lhs.f, lhs.e, r.f, r.e);
	// r overlapped lhs on right side
	if(r.f <= lhs.e && lhs.f <= r.f)
	{
		lhs.e = r.e;
		// printf("Overlapped Right\n");
		ret = false;
	}
	// lhs overlapped r on left side
	else if(lhs.f <= r.e && r.e <= lhs.e)
	{
		lhs.f = r.f;
		// printf("Overlapped Left\n");
		ret = false;
	}
	else if(inner(lhs, r))
	{
		lhs.e = r.e;
		lhs.f = r.f;

		ret = false;
	}

	return ret;
}

int main()
{
	#ifdef DBG
	freopen("C2.in", "r", stdin);
	freopen("C2.out", "w", stdout);
	#endif
	int n, tmpF, tmpE;
	

	l.reserve(50000);

	scanf("%d", &n);

	for(int i = 0; i < n && scanf("%d %d", &tmpF, &tmpE) != EOF; i++)
	{
		Interval tmp(tmpF, tmpE);

		if(l.size() == 0)
		{
			l.push_back(tmp);
		}
		else
		{
			int diff = 0;
			for(int i = 0; i < l.size(); i++)
			{
				if(judge(l[i], tmp))
				{
					diff++;
				}
			}

			if(diff == l.size())
			{
				l.push_back(tmp);
			}
		}
	}

	for(int i = 0; i < l.size(); i++)
	{
		for(int j = i+1; j < l.size(); j++)
		{
			if(inner(l[i], l[j]))
			{
				l.erase(l.begin() + j);
			}
		}
	}

	sort(l.begin(), l.end());

	for(const auto &i : l)
	{
		printf("%d %d\n", i.f, i.e);
	}

	return 0;
}