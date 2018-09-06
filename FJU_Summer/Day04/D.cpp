#include <bits/stdc++.h>

using namespace std;

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

			tmp++;
			// printf("%d\n",banker );

		}

		// printf("\n");

		if(player<banker)
			printf("win\n");
		else if(player==banker)
			printf("push\n");
		else
			printf("lose\n");


	}



	return 0;
}