/*
 * Author: SunTalk
 * WA WTF
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define PROBLEM "A"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	int one,two,three;

	while( times-- ){

		scanf("%d %d %d",&one,&two,&three);
		int x,y,tmp;
		bool ans =  false;

		x = (one+two)/2;
		y = max(one,two);
		y = y - x;
		tmp = round(0.01*x*y);

		if( three == tmp && (one + two)%2 == 0 )
			ans = true;

		y = min(one,two);
		y = y - x;
		tmp = round(0.01*x*y);

		if( three == tmp && (one + two)%2 == 0 )
			ans = true;

		x = (one+three)/2;
		y = max(one,three);
		y = y - x;
		tmp = round(0.01*x*y);

		if( two == tmp && (one + three)%2 == 0 )
			ans = true;

		y = min(one,three);
		y = y - x;
		tmp = round(0.01*x*y);

		if( two == tmp && (one + three)%2 == 0 )
			ans = true;

		x = (three+two)/2;
		y = max(three,two);
		y = y - x;
		tmp = round(0.01*x*y);

		if( one == tmp && (three + two)%2 == 0 )
			ans = true;

		y = min(three,two);
		y = y - x;
		tmp = round(0.01*x*y);

		if( one == tmp && (three + two)%2 == 0 )
			ans = true;

		if( ans )
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}