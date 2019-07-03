LL table[140000]; //start from 1 to 2^17-1
int digit[16]; //if digit add,table need add
// one and two cannott be 0
void build(int one,int two){
	int i,j,k=1;
	memset(digit,-1,sizeof(digit));
	memset(table,0,sizeof(table));

	while( k < 140000 ){
		i = 0;
		digit[i] += 1;
		while( digit[i] == 2 ){
			digit[i] = 0;
			i++;
			digit[i]++;
		}
		j=15;
		while( digit[j] < 0 ){
			j--;
		}
		while( j >= 0 ){
			table[k] = table[k] * 10;
			if( digit[j] == 1 )
				table[k] = table[k] + two;
			else if( digit[j] == 0 )
				table[k] = table[k] + one ;
			j--;
		}
		k=k+1;
	}
}