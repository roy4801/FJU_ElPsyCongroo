/*
 * Backpack implmentation
 * Author: SunTalk
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <bits/stdc++.h>

#define W 1000         // 背包最重 W
#define N 100          // 最多 N 種物品

int weight[N];         //物品重量
int value[N];          //物品價值
int bag[W][2];

// 0/1 背包
void ZeroOne(){

	memset(bag,0,sizeof(bag));

	for(int i = 0 ; i < N ; i++ ){

		for(int j = 0 ; j < W ; j++ )
			if( j >= weight[i] )
				bag[j][1] = max( bag[j][0] ,bag[j-weight[i]][0] + value[i] );
		
		for(int j = 0 ; j < W ; j++ )
			bag[j][0] = bag[j][1];
	}
}

//----------------------------------------------------------------------------------------------------
// 無限背包
void Unlimited(){

	memset(bag,0,sizeof(bag));

	for(int i = 0 ; i < N ; i++ ){

		for(int j = 0 ; j < W ; j++ )
			if( j >= weight[i] )
				bag[j][1] = max( bag[j][0] ,bag[j-weight[i]][1] + value[i] );
		
		for(int j = 0 ; j < W ; j++ )
			bag[j][0] = bag[j][1];
	}
}

//----------------------------------------------------------------------------------------------------
// 分組背包
int group;             //有幾組
int how_many;          //一組幾個
int WEIGHT,VALUE;

void Grouping(){

	memset(bag,0,sizeof(bag));

	for(int i = 0 ; i < group ; i++ ){

		for(int j = 0 ; j < how_many ; j++ ){

			scanf("%d %d",&WEIGHT,&VALUE);

			for(int k = 0 ; k < W ; k++ ){

				if( j >= WEIGHT ){
					bag[j][1] = max( bag[j][1] , bag[j][0] );
					bag[j][1] = max( bag[j][1] ,bag[j-WEIGHT][0] + VALUE );
				}
			}
		}
		
		for(int j = 0 ; j < W ; j++ )
			bag[j][0] = bag[j][1];
	}
}

//----------------------------------------------------------------------------------------------------
// 多重背包
int limit[N];          //物品上限

void Multiple(){

	for(int i = 0 ; i < N ; i++ ){

		int tmp = 1;
		
		while( tmp <= weight[i] ){
			
			for(int j = 0 ; j < W ; j++)
				if( j >= weight[i]*tmp )
					bag[j][1] = max( bag[j-weight[i]*tmp][0] + value[i]*tmp , bag[j][0] );
			
			for(int j = 0 ; j < W ; j++ )
				bag[j][0] = bag[j][1];
			
			weight[i] = weight[i]-tmp;
			tmp = tmp*2;
				
		}
	
		if( weight[i] > 0 ){

			for(int j = 0 ; j < W ; j++)
				if( j >= weight[i]*tmp )
					bag[j][1] = max( bag[j-weight[i]*tmp][0] + value[i]*tmp , bag[j][0] );
			
			for(int j = 0 ; j < W ; j++ )
				bag[j][0] = bag[j][1];
			
		}

	}
}