#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("G.in", "r", stdin);
	freopen("G.out", "w", stdout);
	#endif

	int len,times,check;
	char flavor;
	scanf("%d %d ",&len,&times);
	int str[len];

	for(int i=0;i<len;i=i+1){
		scanf("%c",&flavor);
		if(flavor=='T')
			str[i]=2;
		else
			str[i]=1;
	}


	for (int i = 0; i < times; ++i)
	{
		int money;
		scanf("%d",&money);
		
		int start = 0, end = 0, ans ;
		
		ans=str[0];
		check=1;

		while(1)
		{	

			if(ans==money){
				check=0;
			}
			else if(start==end && start<len-1){
				end=end+1;
				ans=ans+str[end];
			}
			else if(ans<money && end<len-1 ){
				end=end+1;
				ans=ans+str[end];
			}
			else if(ans>money && start<len-1){
				ans=ans-str[start];
				start=start+1;
			}
			else{
				check=0;
			}

			// printf("%d %d %d\n",start,end,ans );

			if(check==0)
				break;
		}

		if(ans==money)
			printf("%d %d\n",start+1,end+1 );
		else
			printf("NIE\n");

	}

	return 0;

}