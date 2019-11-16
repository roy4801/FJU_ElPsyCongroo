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

#define MAXN 1000

int S[MAXN+10];

int main()
{

	int num;
	string str;

	while( ~scanf("%d",&num) ){

		cin >> str;
		memset(S,0,sizeof(S));
		for(int i = 0 ; i < str.size() ; i++ )
			S[i] = str[i]-'a'+1;

		bool act = true;
		int N = str.size();
		while( act ){
			act = false;
			for(int i = N-1 ; i > 0 ; i-- ){
				while( S[i-1]+num <= 26 && S[i] > 0 ){
					S[i-1] += num;
					S[i]--;
					act = true;
				}
			}
		}

		for(int i = 0 ; i < N ; i++ ){

			if( S[i] == 0 )
				break;
			printf("%c" , 'a'+S[i]-1 );

		}
		printf("\n");


	}

	return 0;
}