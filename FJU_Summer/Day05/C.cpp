#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif

	int start,end,ans=0,check,tmp;
	scanf("%d %d",&start,&end);

	int arr[10],i;
	for(i=0;i<10;i=i+1){
		arr[i]=pow(2,i);
	}

	int times=0;
	tmp=end;
	for(i=end;i>start;i=i-1){
		while(tmp>0){
			times=times+1;
			tmp/10;
		}
	}
	


	return 0;
}