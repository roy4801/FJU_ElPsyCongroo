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

int main()
{
	
	int N,S,T;

	while( ~scanf("%d %d %d",&N,&S,&T) ){

		int k = -1;
		if( S <= T && T < (1<<N) ){
			k = 0;
			while( S < T ){
				if( T&1 ) T = (T-1)/2;
				else T /= 2;
				k++;
			}
			if( S != T ) k = -1;
		}

		printf("%d\n",k );

	}





	return 0;
}