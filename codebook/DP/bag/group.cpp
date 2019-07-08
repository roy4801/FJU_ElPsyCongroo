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