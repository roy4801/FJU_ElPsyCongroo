// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

// By roy4801
// 638ms 100

int main()
{
	#ifdef DBG
	freopen("B_r.in", "r", stdin);
	freopen("B_r.out", "w", stdout);
	#endif
	int book;

	scanf("%d", &book);

	int shelf[book], now = book, stable = 0;

	for(int i = 0; i < book && scanf("%d", &shelf[i]) != EOF; i++);

	for(int i = book - 1; i >= 0; i--)
	{
		if(shelf[i] == now)
		{
			stable++;
			now--;
		}
	}

	printf("%d\n", book - stable);

	return 0;
}