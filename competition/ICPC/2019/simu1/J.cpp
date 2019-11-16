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

#define MOD (1000000007)
// #define MOD (4294967296)

long long POWMOD(int N){

	if( N == 0  )
		return 1;

	long long k = POWMOD(N/2)%MOD;
	k = (k*k)%MOD;

	if( N&1 )
		return (k*4)%MOD;
	else
		return k;

}


int main()
{

	int kase;
	scanf("%d",&kase);
	int num;
	long long AN,BN,CN;
	int N;

	while( kase-- ){

		scanf("%d",&num);

		if( num&1 ){
			N = (num+1)/2-1;
			BN = POWMOD(N)-1;
			while( BN%3 ) BN += MOD;
			// cout << BN << endl;
			BN = (BN/3)*2;
			BN %= MOD;

			AN = BN + num/2 +1;
			AN %= MOD;
			CN = BN - num/2;
			CN += MOD;
			CN %= MOD;
		}
		else{
			N = num/2-1;
			BN = POWMOD(N)-1;
			while( BN%3 ) BN += MOD;
			// cout << BN << endl;
			BN = (BN/3)*4+1;
			BN %= MOD;

			AN = BN + num/2;
			AN %= MOD;
			CN = BN - num/2;
			CN += MOD;
			CN %= MOD;
		}

		cout << AN << " " << BN << " " << CN << endl;

	}


	return 0;
}