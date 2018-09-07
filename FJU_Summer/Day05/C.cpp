#include <bits/stdc++.h>
//賽後AC
using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int lucky[1030];
	int digit[10];
	int i,j,k=1;
	memset(digit,-1,sizeof(digit));
	memset(lucky,0,sizeof(lucky));

	while(k<1030){
		i=0;
		digit[i]=digit[i]+1;

		while(digit[i]==2){
			digit[i]=0;
			i=i+1;
			digit[i]=digit[i]+1;
		}

		j=8;
		while(digit[j]<0){
			j--;
		}
		while( j>=0 ){
			lucky[k]=lucky[k]*10;
			if(digit[j]==1)
				lucky[k]=lucky[k]+7;
			else if(digit[j]==0)
				lucky[k]=lucky[k]+4;
			j=j-1;
		}

		k=k+1;
	}
	lucky[1023]=1000000001;
	// for(i=1;i<1025;i=i+1){
	// 	printf("%d\n",lucky[i] );
	// }

	int start,end;
	scanf("%d %d",&start,&end);
	int num_s,num_e,ans;

	for(i=0;i<1030;i=i+1){

		if( start>lucky[i] && start<=lucky[i+1] ){
			num_s=i;
		}

		if( end >= lucky[i] && end < lucky[i+1] ){
			num_e=i;
			ans=num_e-num_s;
			break;
		}
	}

	printf("%d\n", ans );


	return 0;
}
