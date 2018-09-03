#include <bits/stdc++.h>

using namespace std;

// By SunTalk

int main()
{
	#ifdef DBG
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif

	int book;
	scanf("%d",&book);
	int shelf[book],i,j;
	int tmp,check,ans;

	for(i=0;i<book;i=i+1){
		scanf("%d",&shelf[i]);
	}

	for(i=0;i<book;i=i+1){
		if(shelf[i]==book){
			tmp=book;
			check=1;
			for(j=i;j>=0;j=j-1){
				if(shelf[j-1]==tmp-1){
					check=check+1;
					tmp=tmp-1;
				}
			}
		}
	}

	ans=book-check;

	printf("%d\n",ans );

	return 0;
}