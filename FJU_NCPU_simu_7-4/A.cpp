#include <iostream>

using namespace std;





int main()
{
	#ifdef DBG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif

	unsigned int num;
	unsigned int ans;
	unsigned int tempA,tempB;
	int count=1;
	while(scanf("%u", &num) != EOF && num){

		for (int i = 1; i <= num; ++i)
 		{
 			if(num % i==0){
 				tempA = i ;
 				tempB = num/i;
 			}
 			if(tempA>tempB) break;	
 		}
 		
 		ans=tempA+tempB;

 		printf("Case %d: %u\n", count, ans);
 		count++;
	} 
	return 0;
}