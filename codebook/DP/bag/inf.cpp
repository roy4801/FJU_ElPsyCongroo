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