#include <bits/stdc++.h>

using namespace std;

// By SunTalk

int main()
{
	#ifdef DBG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif

	int times,i,j;
	scanf( "%d ",&times );
	
	for(i=0;i<times;i=i+1){
		char number;
		int Poke[52];
		for(j=0;j<52;j++){
			scanf("%c ",&number);
			
			if(number=='1'){
				scanf("%c ",&number);
				Poke[j]=10;
			}
			else if(number=='J' || number=='Q' || number=='K')
				Poke[j]=10;
			else if(number=='A')
				Poke[j]=11;
			else
				Poke[j]=number-'0';
		}

		int banker=21,player=21;
		int tmp=2,check_b=0,check_p=0;
		int tmp_b,tmp_p;

		banker=banker-Poke[0]-Poke[1];

		if(banker<0){
			banker=8;
			check_b=1;
		}


		while(player>0){
			
			if(Poke[tmp]==11){
				if(player>=Poke[tmp])
					player=player-Poke[tmp];
				else
					player=player-1;
				check_p=1;
			}
			else if(player>=Poke[tmp]){
				player=player-Poke[tmp];
			}
			else{

				if(check_p==1){
					tmp_p=player+10;
					for(j=tmp;j<tmp+10;j=j+1){
						
						if(player>=Poke[j] || Poke[j]==11){
							if(Poke[j]==11)
								tmp_p=tmp_p-1;
							else	
								tmp_p=tmp_p-Poke[j];
						}
						else
							break;
					}

					if(tmp_p<player){
						tmp=j;
						tmp_p=Poke[tmp];
						player=tmp_p;
					}
					else
						tmp_p=Poke[tmp];

				}
				else
				tmp_p=Poke[tmp];

				break;
			}

			tmp++;
			// printf("%d\n",player );
		}

		// printf("\n");

		while(banker>4){

			if(Poke[tmp]==11){
				if(banker>=Poke[tmp])
					banker=banker-Poke[tmp];
				else
					banker=banker-1;
				check_b=1;
			}
			else{
				banker=banker-Poke[tmp];
			}

			if(check_b==1 && banker<0)
				banker=banker+10;

			tmp++;
			// printf("%d\n",banker );

		}

		// printf("\n");
		if((banker-tmp_p+Poke[tmp-1])<0)
			printf("win\n");
		else if(player<banker)
			printf("win\n");
		else if(player==banker)
			printf("push\n");
		else
			printf("lose\n");

	}

	return 0;
}