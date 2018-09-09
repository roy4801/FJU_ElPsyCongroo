#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "G"

// By SunTalk TLE ~~(AC?)~~

int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int number,i;
	scanf("%d",&number);

	for(i=0;i<number;i=i+1){
		int times,j;
		scanf("%d",&times);
		int circle[times];
		memset(circle,0,sizeof(circle));
		int max=0;
		int check=0,small=0,tmp=0;
		int negative= INT_MIN;

		for(j=0;j<times;j=j+1){
			scanf("%d ",&circle[j]);
			max=max+circle[j];

			if(circle[j]<0){
				if(negative<circle[j])
					negative=circle[j];
				tmp=tmp+circle[j];
				if(tmp<small)
					small=tmp;
			}
			else{
				check=1;
				tmp=0;
			}
		}

		if(check==0){
			printf("%d\n",negative );
			continue;
		}


		if(tmp!=0){
			for(j=0;j<times;j=j+1){
				if(circle[j]<0){
					tmp=tmp+circle[j];
					if(tmp<small)
						small=tmp;
				}
				else
					break;
			}
		}

		// printf("%d %d\n",max,small );
		printf("%d\n", max-small );

	}

	return 0;
}