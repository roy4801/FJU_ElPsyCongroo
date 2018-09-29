#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "D"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times,i;
	scanf("%d",&times);

	long long a,r,p;
	long long ans,j;

	for( i=0;i<times;i++ ){

		scanf("%lld %lld %lld ",&a,&r,&p);

		ans = p+r;

		while( ans%a != 0 ){
			printf("ans:%lld\n",ans );
			ans=ans+p;
		}
		printf("ans:%lld\n",ans );
		printf("%lld\n",ans/a );

	}

	return 0;
}