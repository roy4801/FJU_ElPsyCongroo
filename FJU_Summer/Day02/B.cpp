
#include <bits/stdc++.h>

using namespace std;

int game[9];
int final[9];
int check=0;

void fuck(int k,int number){
	int i;

	if(k==9){
		int ans=game[0]+game[1]+game[2];
		if(ans==game[3]+game[4]+game[5] && ans==game[6]+game[7]+game[8] && ans==game[0]+game[3]+game[6] && ans==game[1]+game[4]+game[7] && ans==game[2]+game[5]+game[8] && ans==game[0]+game[4]+game[8] && ans==game[2]+game[4]+game[6] ){
			for(i=0;i<9;i=i+1){
				final[i]=game[i];
				check=1;
			}
		}
		return;
	}

	for(int i=1;i<=number;i=i+1){
		if(game[k]==0){
			game[k]=i;
			fuck(k+1,number);
			if(check==1)
				return;
			game[k]=0;
		}
		else{
			fuck(k+1,number);
			if(check==1)
				return;
		}

	}
}

void clear(){
	memset(game,0,sizeof(game));
	memset(final,0,sizeof(final));
	check=0;
}

int main()
{
	#ifdef DBG
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif

	int times,i;
	int number,j,k;
	scanf("%d",&times);

	for(i=0;i<times;i=i+1){
		scanf("%d",&number);
		for(j=0;j<9;j=j+1){
			scanf("%d",&game[j]);
		}
		fuck(0,number);
		if(final[0]==0){
			printf("No\n");
		}
		else{
			printf("Yes\n");
			for(j=0;j<9;j=j+1){
				if(j==2 || j==5 || j==8){
					printf("%d\n",final[j] );
				}
				else{
					printf("%d ",final[j] );
				}
			}
		}
		clear();
	}

	return 0;
}