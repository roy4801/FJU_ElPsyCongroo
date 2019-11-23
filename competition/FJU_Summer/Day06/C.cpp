#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{

	#ifdef DEBUG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif
 	
	int number;
	scanf("%d",&number);
	int start[number],end[number];
	vector <int> big;
	vector <int> small;
	int tmp,i,j;

	for(i=0;i<number;i=i+1){
		scanf("%d",&start[i]);
	}
	for(i=0;i<number;i=i+1){
		scanf("%d",&end[i]);
	}

	for(i=0;i<number;i=i+1){
		if(start[i]>end[i]){
			tmp=start[i]-end[i];
			for(j=0;j<tmp;j=j+1)
				big.push_back(i);
		}
		else if(end[i]>start[i]){
			tmp=end[i]-start[i];
			for(j=0;j<tmp;j=j+1){
				small.push_back(i);
			}
		}
	}

	tmp=small.size();
	printf("%d\n",tmp );
	for(i=0;i<tmp;i=i+1){
		printf("%d %d\n",big[i]+1,small[i]+1 );
	}

	return 0;
}