// 多重背包
int limit[N]; // 物品上限
void Multiple() {
  for(int i = 0 ; i < N ; i++ ){
    int tmp = 1;
    while( tmp <= weight[i] ){
      for(int j = 0 ; j < W ; j++)
        if( j >= weight[i]*tmp )
          bag[j][1] = max( bag[j-weight[i]*tmp][0] + value[i]*tmp
                        , bag[j][0] );
      
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