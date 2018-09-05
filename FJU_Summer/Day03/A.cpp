#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{	

	#ifdef DEBUG
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	#endif

	int line,column,times;
	scanf("%d %d",&line,&column);
	scanf("%d ",&times);
	int jungle[line+1][column+1],ocean[line+1][column+1],ice[line+1][column+1];
	char mark;
	int tmp_i,tmp_j,tmp_o;
	int i,j;

	memset(jungle,0,sizeof(jungle));
	memset(ocean,0,sizeof(ocean));
	memset(ice,0,sizeof(ice));

	for(i=1;i<=line;i=i+1){
		tmp_i=tmp_j=tmp_o=0;
		for(j=1;j<=column;j=j+1){
			scanf("%c",&mark);
			if(mark=='J'){
				tmp_j=tmp_j+1;
			}
			else if(mark=='O'){
				tmp_o=tmp_o+1;		
			}
			else{
				tmp_i=tmp_i+1;
			}
			jungle[i][j]=jungle[i][j]+tmp_j+jungle[i-1][j];
			ocean[i][j]=ocean[i][j]+tmp_o+ocean[i-1][j];
			ice[i][j]=ice[i][j]+tmp_i+ice[i-1][j];
		}
		getchar();
	}

	// for(i=0;i<line+1;i=i+1){
	// 	for(j=0;j<column+1;j=j+1){
	// 		printf("%d ",jungle[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for(i=0;i<line+1;i=i+1){
	// 	for(j=0;j<column+1;j=j+1){
	// 		printf("%d ",ocean[i][j] );
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for(i=0;i<line+1;i=i+1){
	// 	for(j=0;j<column+1;j=j+1){
	// 		printf("%d ",ice[i][j] );
	// 	}
	// 	printf("\n");
	// }


	int start_x,start_y;
	int end_x,end_y;
	int ans=0;

	for(i=0;i<times;i=i+1){
		scanf("%d %d %d %d",&start_x,&start_y,&end_x,&end_y);
		ans=jungle[end_x][end_y]-jungle[start_x-1][end_y]-jungle[end_x][start_y-1]+jungle[start_x-1][start_y-1];
		printf("%d ",ans );
		ans=ocean[end_x][end_y]-ocean[start_x-1][end_y]-ocean[end_x][start_y-1]+ocean[start_x-1][start_y-1];
		printf("%d ",ans );
		ans=ice[end_x][end_y]-ice[start_x-1][end_y]-ice[end_x][start_y-1]+ice[start_x-1][start_y-1];
		printf("%d\n",ans );
	}

	return 0;
}