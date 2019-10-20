string A,B;
int table[MAXN+5][MAXN+5];

for(int i = 0 ; i < A.size() ; i++ ){
    for(int j = 0 ; j < B.size() ; j++ ){
        if( A[i] == B[j] )
            table[i+1][j+1] = table[i][j]+1;
        else
            table[i+1][j+1] = max(table[i+1][j],table[i][j+1]);
    }
}//ans at table[A.size()][B.size()]


