#include <bits/stdc++.h>

using namespace std;
#define MAXN 100

int main()
{

	int table[15];
	table[1] = 1;
	for(int i = 2 ; i < 15 ; i++ )
		table[i] = table[i-1]*i;

	int kase;
	scanf("%d",&kase);
	int num;

	while( kase-- ){

		scanf("%d",&num);
		for(int i = 1 ; i < 15 ; i++ ){
			if( table[i]%num == 0 ){
				printf("%d\n",i);
				break;
			}
		}

	}

	return 0;
}