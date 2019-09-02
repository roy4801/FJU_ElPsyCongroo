#include <bits/stdc++.h>

using namespace std;
#define MAXN 100

long long nCr[MAXN+5][MAXN+5];

void build_nCr(){ //nCr[i][j] = C n 取 r
	for(int i = 1 ; i < MAXN+5 ; i++ ){
		for(int j = 1 ; j < MAXN+5 ; j++ ){
			if( i == j )
				nCr[i][j] = 1;
			else if( i > j )
				nCr[i][j] = nCr[i-1][j]*i/(i-j);
		}
	}
}
