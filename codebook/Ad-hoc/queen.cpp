// N_Queen(0,num);
int Queen[37000][14];
int tmp[14];
int cnt;
bool row[14], L[27], R[27];

void N_Queen(int k, int Num){
  if(k == Num){
    for(int j = 0; j < Num; j++)
      Queen[cnt][j] = tmp[j];
    cnt++;
    return;
  }
  for(int i = 0; i < Num; i++) {
    int right= k+i, left= k-i+Num-1;
    if(!row[i] && !L[left] && !R[right]) {
      row[i] = L[left] = R[right] = true;
      tmp[k]=i;
      N_Queen(k+1, Num);
      row[i] = L[left] = R[right] = false;
    }
  }
}