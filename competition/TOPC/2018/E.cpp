#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "E"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

inline int calcOR(const vector<int> &l)
{
	if(l.size() == 0)
		return 0;

	int ret = l[0];
	for(int i = 1; i < l.size(); i++)
	{
		ret |= l[i];
	}

	return ret;
}

inline int calcAND(const vector<int> &l)
{
	if(l.size() == 0)
		return 0;

	int ret = l[0];
	for(int i = 1; i < l.size(); i++)
	{
		ret &= l[i];
	}

	return ret;
}

inline int calcXOR(const vector<int> &l)
{
	if(l.size() == 0)
		return 0;

	int ret = l[0];
	for(int i = 1; i < l.size(); i++)
	{
		ret ^= l[i];
	}

	return ret;
}

int dis(int a, int b)
{
	int tmp = a ^ b, cnt = 0;

	while(tmp > 0)
	{
		if(tmp & 1)
			cnt++;
		tmp >>= 1;
	}
	return cnt;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int num;

	scanf("%d", &num);

	vector<int> l(num);
	bool valid[num];

	memset(valid, true, sizeof(valid));

	for(int i = 0; i < num && scanf("%d", &l[i]); i++);
	vector<int> arr[3];

	// Find XOR
	int max = INT_MIN, max_i, max_j;
	for(int i = 0; i < num; i++)
	{
		for(int j = i+1; j < num; j++)
		{
			int dist = dis(l[i], l[j]);
			// printf("%d %d: %d\n", i, j, dist);
			if(max < dist)
			{
				max = dist;
				max_i = i;
				max_j = j;
			}
		}
	}
	// printf("%d %d\n", max_i, max_j);
	arr[0].push_back(l[max_i]);
	arr[0].push_back(l[max_j]);
	valid[max_i] = valid[max_j] = false;
	//
	// Find AND
	int MAX = INT_MIN, MAX_i;
	
	for(int i = 0; i < num; i++)
	{
		if(valid[i] && MAX < l[i])
		{
			MAX = l[i];
			MAX_i = i;
		}
	}

	// printf("%d %d\n", MAX, MAX_i);

	valid[MAX_i] = false;
	arr[2].push_back(MAX);
	//
	// Find OR
	for(int i = 0; i < num; i++)
	{
		if(valid[i])
		{
			arr[1].push_back(l[i]);
		}
	}
	//
	printf("%d\n", calcXOR(arr[0]) + calcOR(arr[1]) + calcAND(arr[2]));

	for(int i = 0; i < 3; i++)
	{
		printf("%d", arr[i].size());
		for(int j = 0; j < arr[i].size(); j++)
		{
			printf(" %d", arr[i][j]);
		}
		putchar('\n');
	}

	return 0;
}