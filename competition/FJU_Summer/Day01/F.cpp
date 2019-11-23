#include <bits/stdc++.h>

using namespace std;

// By SunTalk

int main()
{
	#ifdef DBG
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	#endif

	long long x,y;
	long long ans;

	scanf("%lld %lld",&x,&y);

	ans=x*y;

	if(x==1 || y==1){
		ans=ans-1;
		ans=ans*2;
		printf("%lld",ans );
		printf(".00"\n);
	}
	else if(ans%2 != 0){
		printf("%lld",ans );
		printf(".41\n");
	}
	else{
		printf("%lld",ans );
		printf(".00\n");
	}

	return 0;
}
