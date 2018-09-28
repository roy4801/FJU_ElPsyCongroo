#include <bits/stdc++.h>

using namespace std;

// by SunTalk and halloworld - Wait for teacher Fuck

#define TESTC ""
#define PROBLEM "B"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAX 1000

int data[MAX+5];
int dad_range[MAX+5];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int number;

	while ( scanf("%d",&number) && number!=0 ){

		if(number==1){
			scanf("%d",&data[0]);
			printf("1\n");
			continue;
		}

		int root,i;
		memset(data,-1,sizeof(data));
		memset(dad_range,-1,sizeof(dad_range));
		
		for( i=1;i<=number;i=i+1 ){
			scanf("%d",&data[i]);
			dad_range[i]=0;
			if(data[i]==0)
				root=i; 
		}

		int big_num,big_position,tmp;
		
		big_num=-1;
		big_position=0;

		for( i=1;i<=number;i=i+1 ){

			tmp = data[i];
			if(tmp==0)
				continue;
			else{
				while( data[tmp] != 0){

					if(data[tmp]<i){
						dad_range[i]= dad_range[i] + dad_range[ data[tmp] ];
						dad_range[i]++;
						break;
					}
					else{
						tmp=data[tmp];
						dad_range[i]++;
					}
					
				}//end while
				dad_range[i]++;
			}//end else tmp != 0

			if(dad_range[i]>big_num){
				big_num=dad_range[i];
				big_position=i;
			}

		}

		// //test print
		// for( i=1 ;i<=number ;i++ ){
		// 	printf("%d ",data[i] );
		// }
		// printf("\n");
		// for( i=1 ;i<=number ;i++ ){
		// 	printf("%d ",dad_range[i] );
		// }
		// printf("\n");
		// printf("%d %d\n",big_num,big_position );
		// printf("\n");
		// // end test print

		tmp=big_position;
		while( data[tmp]!=0 ){

			for(i=1;i<=number;i++){
				if(data[i]==data[tmp] && data[i]!=root)
					dad_range[i] = dad_range[i]*(-1);
			}

			tmp = data[tmp];
		}




		// //test print
		// for( i=1 ;i<=number ;i++ ){
		// 	printf("%d ",data[i] );
		// }
		// printf("\n");
		// for( i=1 ;i<=number ;i++ ){
		// 	printf("%d ",dad_range[i] );
		// }
		// printf("\n");
		// printf("%d %d\n",big_num,big_position );
		// printf("\n");
		// // end test print

		tmp = -1;
		for(i=1;i<=number;i++){
			if( tmp < dad_range[i] )
				tmp = dad_range[i];
		}// find second

		// for( i=1 ;i<=number ;i++ ){
		// 	printf("%d ",data[i] );
		// }
		// printf("\n");
		// for( i=1 ;i<=number ;i++ ){
		// 	printf("%d ",dad_range[i] );
		// }
		// printf("\n");


		// printf("tmp %d\n",tmp );

		big_num = big_num + tmp;
		// printf("tmp+big_num %d\n",big_num );
		tmp = big_num/2;
		int ans;
		ans = big_position;
		// printf("tmp %d big_num %d\n",tmp,big_num );
		// printf("ans %d\n",ans );

		for(i=0;i<tmp-1;i++){
			ans = data[ans];
		}

		if(number==2){
			printf("1 2\n");
		}
		else{
			if(big_num%2 != 0){
				if(number!=3){
					printf("%d ",data[ans]);
					ans = data[ans];
				}
			}
	
			printf("%d\n",data[ans] );
			// printf("\n");
		}
			
		

	}


	return 0;
}