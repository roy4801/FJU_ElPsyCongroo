#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif

	int line,column,times;
	scanf("%d %d",&line,&column);
	scanf("%d",&times);
	int home[times][2],i;
	int max_x=0,max_y=0;
	int tiny_x=1000000000,tiny_y=1000000000;


	for(i=0;i<times;i=i+1){
		scanf("%d %d",&home[i][0],&home[i][1]);
		if(home[i][0]>max_x)
			max_x=home[i][0];
		if(home[i][0]<tiny_x)
			tiny_x=home[i][0];
		if(home[i][1]>max_y)
			max_y=home[i][1];
		if(home[i][1]<tiny_y)
			tiny_y=home[i][1];
	}

	int ans[2][2]={0};
	int mid_x,mid_y;

	mid_x=(max_x+tiny_x)/2;
	mid_y=(max_y+tiny_y)/2;
	int lengh[4];
	int f_lengh[4]={0};

	for(i=0;i<times;i=i+1){
		ans[0][0]=ans[0][0]+abs(home[i][0]-mid_x);
		ans[0][1]=ans[0][1]+abs(home[i][0]-(mid_x+1));

		ans[1][0]=ans[1][0]+abs(home[i][1]-mid_y);
		ans[1][1]=ans[1][1]+abs(home[i][1]-(mid_y+1));

		lengh[0]=abs(home[i][0]-mid_x)+abs(home[i][1]-mid_y);//00 10
		if(f_lengh[0]<lengh[0])
			f_lengh[0]=lengh[0];
		lengh[1]=abs(home[i][0]-(mid_x+1))+abs(home[i][1]-mid_y);//01 10
		if(f_lengh[1]<lengh[1])
			f_lengh[1]=lengh[1];
		lengh[2]=abs(home[i][0]-mid_x)+abs(home[i][1]-(mid_y+1));//00 11
		if(f_lengh[2]<lengh[2])
			f_lengh[2]=lengh[2];
		lengh[3]=abs(home[i][0]-(mid_x+1))+abs(home[i][1]-(mid_y+1));//01 11
		if(f_lengh[3]<lengh[3])
			f_lengh[3]=lengh[3];
	}

	int final_x,final_y,total=0;
	int check=0;

	if(ans[0][0]>ans[0][1]){
		total=ans[0][1];
		final_x=mid_x+1;
		check=1;
	}
	else{
		total=ans[0][0];
		final_x=mid_x;
	}

	if(ans[1][0]>ans[1][1]){
		total=total+ans[1][1];
		final_y=mid_y+1;
		if(check==0)
			total=total*2-f_lengh[2];
		else
			total=total*2-f_lengh[3];
	}
	else{
		total=total+ans[1][0];
		final_y=mid_y;
		if(check==0)
			total=total*2-f_lengh[0];
		else
			total=total*2-f_lengh[1];
	}

	printf("%d\n",total );
	printf("%d %d\n", final_x,final_y);

	return 0;
}