#include <bits/stdc++.h>

using namespace std;

#define PROBLEM ""
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int table[50][5];

int main()
{

	memset(table,0,sizeof(table));

	int N = 1;
	for(int i = 1 ; i <= 30 ; i++,N=N<<1 ){

		// table[i][0] = N/3;
		// table[i][1] = N/3;
		// table[i][2] = N/3;

		table[i][0] = table[i-1][0] + N/3;
		table[i][1] = table[i-1][1] + N/3;
		table[i][2] = table[i-1][2] + N/3;

		if( N%3 == 2 ) table[i][0]++,table[i][1]++;
		if( N%3 == 1 ) table[i][0]++;

	}

	// for(int i = 1 ; i <= 30 ; i++ ){
	// 	printf("%d %d %d\n",table[i][0],table[i][1],table[i][2] );
	// }

	int kase;
	scanf("%d",&kase);
	int num;
	while( kase-- ){
		scanf("%d",&num);
		printf("%d %d %d\n",table[num][0],table[num][1],table[num][2] );
	}


	return 0;
}