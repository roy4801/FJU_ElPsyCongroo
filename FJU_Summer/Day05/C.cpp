#include <bits/stdc++.h>

using namespace std;

int binary(int k){
	int ans;
	int check=0;
	while(k>0){
		if(k%10==7){
			ans=ans+pow(2,check);	
		}
		check=check+1;
		k=k/10;
	}
	return ans;
}

int main()
{
	#ifdef DBG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif

	int start,end;
	scanf("%d %d",&start,&end);
	int ans,i;

	for(i=start;i<end;i=i+1){
		int tmp=i;
		bool check=0;
		while(tmp>0){
			if(tmp%10 != 4 && tmp%10 != 7){
				check=1;
				break;
			}
		}
		if(check==0)
			break;
	}

	ans=binary(i);

	for(i=end;i>start;i=i-1){
		int tmp=i;
		bool check=0;
		while(tmp>0){
			if(tmp%10 != 4 && tmp%10 != 7){
				check=1;
				break;
			}
		}
		if(check==0)
			break;

	}

	ans=binary(i)-ans+1;

	return 0;
}