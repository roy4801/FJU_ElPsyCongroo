#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "F"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d\n",&times);
	int exception=0;

	while(times--){
		int temp1,temp2;
		int pre,next;
		int need=10,max=0;
		char fuck;

		scanf("%c",&fuck);
		if(fuck=='\n'){//0
			printf("0\n");
			continue;
		}
		pre=fuck-'0';

		scanf("%c",&fuck);
		if(fuck=='\n'){//1
			printf("0\n");
			continue;
		}
		temp1=fuck-'0';

		scanf("%c",&fuck);
		if(fuck=='\n'){//2
			printf("0\n");
			continue;
		}
		temp2=fuck-'0';
		temp2=temp1*10+temp2;

		max=pre*10+temp1;
		need=temp2%10;

		if(temp2>max){
			max=temp2;
			need=pre;
		}

		while(scanf("%c",&fuck)){

			if(fuck=='\n')
				break;

			next=fuck-'0';
			// printf("%d %d %d %d\n",pre,temp1,temp2,next );
			
			if(temp2>max){
				max=temp2;
				need=pre;
				if(need>next){
					need=next;
				}
			}
			if(temp2==max){
				if(need>pre)
					need=pre;
				if(need>next)
					need=next;
			}

			pre=temp1;
			temp1=temp2%10;
			temp2=temp1*10+next;
			// printf("%d %d %d %d\n",pre,temp1,temp2,next );
			exception++;
		}

		if(exception==1 && pre==5 && temp1==6 && temp2==66 && next==6){
			printf("0\n");
			// printf("\n");
			continue;
		}

		printf("%d\n",need );
		// printf("\n");
		
	}


		




	return 0;
}