#include <bits/stdc++.h>

using namespace std;
#define MAXN 10000

int table[MAXN+5];

int main()
{

	table[0] = 0;
	for(int i = 1 ; i <= MAXN ; i++ ){
		bitset<50> b(i);
		table[i] = table[i-1] + b.count();
	}

	int kase;
	scanf("%d",&kase);
	int one,two;

	while( kase-- ){
		scanf("%d %d",&one,&two);
		printf("%d\n",table[two]-table[one-1]);
	}

	return 0;
}