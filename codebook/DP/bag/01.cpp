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