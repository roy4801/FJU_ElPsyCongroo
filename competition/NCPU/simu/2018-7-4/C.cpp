#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	#ifdef DBG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif
	
	double Xa,Ya,Xb,Xc,Yb,Yc;
	double AB,BC,CA,tmpX,tmpY;
	double Ans,test;
	int ans;
	int times,i;
	scanf("%d",&times);

	for(i=0;i<times;i=i+1){
		scanf("%lf %lf %lf %lf %lf %lf",&Xa,&Ya,&Xb,&Yb,&Xc,&Yc);
		tmpX=(Xa*Yb)+(Xb*Yc)+(Xc*Ya);
		tmpY=(Xb*Ya)+(Xc*Yb)+(Xa*Yc);
		if(tmpX>tmpY){
			Ans=tmpX-tmpY;
		}
		else{
			Ans=tmpY-tmpX;
		}

		Ans=Ans/14;

		printf("%.0lf\n", round(Ans));
		
	}

	return 0;
}
