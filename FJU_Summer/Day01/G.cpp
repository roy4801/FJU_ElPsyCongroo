#include <bits/stdc++.h>

// By SunTalk

using namespace std;

int main()
{
	#ifdef DBG
	freopen("G.in", "r", stdin);
	freopen("G.out", "w", stdout);
	#endif

	int line,column,face;
	scanf("%d %d %d",&line,&column,&face);
	char mazz[line][column];
	int tmp_x,tmp_y;
	int check=0;
	for(i=0;i<line;i=i+1){
		for(j=0;j<line;j=j+1){
			scanf("%c",&mazz[i][j]);
			if(mazz[i][j]=='A'){
				tmp_x=i;
				tmp_y=j;
			}
		}
	}
	//face 1 left 2 up 3 right 4 down
	while(1){

		if(face==1){

			if(tmp_x==line-1 || mazz[tmp_x+1][tmp_y]=='X' ){
				if(tmp_y==0 || mazz[tmp_x][tmp_y-1]=='X'){
					face=3;
				}
				else{
					tmp_y=tmp_y-1;
				}
			}
			else{
				face=1;
			}
			check=check+1;

		}
		else if(face==2){

		}
		else if(face==3){

		}
		else if(face==4){

		}




	}



	return 0;
}