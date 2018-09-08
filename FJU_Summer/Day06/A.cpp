#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif
	int number;
	scanf("%d",&number);
 
	int ans=1,tmp,i;
 
	for(i=1;i<=number;i=i+1){

		// printf("%d\n", tmp);
		tmp=i;   
		ans=ans*tmp;
		
		while(ans%10==0)
			ans=ans/10;
		while(ans>99){
			ans=ans%100;
		}
		// printf("%d: %d\n",i,ans%10 );
		// printf("\n");
	}

	printf("%d\n",ans%10 );
 
 
	return 0;
}