#include <bits/stdc++.h>

// by SunTalk

using namespace std;

int main()
{
	#ifdef DBG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif

	int number,energy,x1,x2;
	scanf("%d %d %d %d",&number,&energy,&x1,&x2);

	int laser[number],i;
	int rec[number];
	int ans_tmp,ANS,tmp;

	memset(laser,0,sizeof(laser));
	memset(rec,0,sizeof(rec));

	rec[0]=number;
	ans_tmp=0;
	ANS=0;
	i=0;

	while(1){
		tmp=laser[i];
		rec[tmp]=rec[tmp]-1;
		ans_tmp = ans_tmp + rec[tmp] - rec[tmp+1];
		rec[tmp+1]=rec[tmp+1]+1;
		laser[i]=laser[i]+1;

		if(ans_tmp < ANS  && ans_tmp < energy)
			i=0;
		else
			i=i+1;

		ANS=ans_tmp;
		
		if(ANS==energy)
			break;
	}

	for(i=0;i<number;i=i+1){
		if(i==number-1)
			printf("%d\n",laser[i]+1 );
		else
		 printf("%d ",laser[i]+1 );
	}


	return 0;
}
